#include "includes.h"
#include "kiero/minhook/include/MinHook.h"
#include <iostream>
#include "il2cpp.h"
#include "DisableAntiCheat.hpp"
#include "Kubom.hpp"
#include <vector>
#include "MonoString.h"
#include "MenuVariables.h"



OwnedMenu* MenuVars = new OwnedMenu();

float radiusFov = 160.f;

UnityEngine_Vector3_o HitTarget = {};



extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);



#define M_PI 3.14159265358979323846



Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool SetupConsole()
{
	FILE* fStream;
	if (AllocConsole())
	{
		freopen_s(&fStream, "CONOUT$", "w", stdout);
		std::cout.clear();
		return true;
	}
	return false;
}



// ESSENCIAIS PARA HOOKS E ESTRUTURAS 

static void* LocalPlayer = nullptr;
std::vector <void*> Players;

// Recoil
float RecoilMM[2] = { 0.f,85.f };




// HOOKS DE FUNÇÕES 


// Fov
float (*get_FieldOfView_Original)(void*) = (nullptr);
float get_FieldOfView(void* __this)
{
	if (__this == nullptr)
		get_FieldOfView_Original(__this);

	return RecoilMM[1];
}

//Arma
void (*O_weaponScript)(void*) = nullptr;
void weaponScript(void* __this)
{

	void* Player = *reinterpret_cast<void**>((uintptr_t)__this + 0xE8); //Ponteiro para o jogador

	if (LocalPlayer == Player)
	{
		if (MenuVars->NoRecoil)
		{
			// Remover Recoil
			UnityEngine_Vector3_o zeroRecoil{};
			zeroRecoil.fields.x = 0.0f;
			zeroRecoil.fields.y = 0.0f;
			zeroRecoil.fields.z = 0.0f;

			uintptr_t recoilAddr = (uintptr_t)__this + 0x1CC;


			*reinterpret_cast<UnityEngine_Vector3_o*>((uintptr_t)__this + 0x128) = zeroRecoil;
			*reinterpret_cast<UnityEngine_Vector3_o*>((uintptr_t)__this + 0x134) = zeroRecoil;
			*reinterpret_cast<UnityEngine_Vector3_o*>((uintptr_t)__this + 0x140) = zeroRecoil;
			*reinterpret_cast<UnityEngine_Vector3_o*>(recoilAddr) = zeroRecoil;

			*reinterpret_cast<float*>((uintptr_t)__this + 0x88) = 0.f;
			*reinterpret_cast<float*>((uintptr_t)__this + 0x174) = 0.f;
			*reinterpret_cast<float*>((uintptr_t)__this + 0x178) = 0.f;



			*reinterpret_cast<float*>((uintptr_t)__this + 0xF4) = 9999999999.f;
			*reinterpret_cast<float*>((uintptr_t)__this + 0xF8) = 9999999999.f;

			*reinterpret_cast<short*>((uintptr_t)__this + 0x188) = 999;


			*reinterpret_cast<bool*>((uintptr_t)__this + 0x18C) = true;
			*reinterpret_cast<bool*>((uintptr_t)__this + 0xE4) = false;
			*reinterpret_cast<bool*>((uintptr_t)__this + 0x18A) = true;
		}
	}

	return O_weaponScript(__this);
}


// Player Update
void(*o_Update)(void* __this) = nullptr;
void PlayerScript__Update(void* __this)
{
	if (__this)
	{
		if (std::find(Players.begin(), Players.end(), __this) == Players.end())
			Players.push_back(__this);
	}
	return o_Update(__this);
}


// OnDestroy -> Remover Jogadores da lista quando forem destruídos para evitar nullptr
void (*OnDestroy_Original)(void*) = nullptr;
void OnDestroy(void* __this)
{
	if (__this)
	{
		auto it = std::find(Players.begin(), Players.end(), __this);
		if (it != Players.end())
		{
			Players.erase(it);
		}
	}
	return OnDestroy_Original(__this);
}



// Local Player -> Obter jogador local

//Local Update
void (*PlayerScript__LocalUpdate_Original)(void*);
void PlayerScript__LocalUpdate(void* __this)
{
	if (LocalPlayer == __this)
	{

		
		//*reinterpret_cast<int*>((uintptr_t)__this + 0x3B0) = 9999;
		*reinterpret_cast<float*>((uintptr_t)__this + 0x68) = 0000000000.f;
		//*reinterpret_cast<float*>((uintptr_t)__this + 0x70) = 30.f;
		//*reinterpret_cast<float*>((uintptr_t)__this + 0x6C) = 30.f;
		//*reinterpret_cast<float*>((uintptr_t)__this + 0x74) = 30.f;
	}
	return PlayerScript__LocalUpdate_Original(__this);
}



void (*WeaponScript__WeaponShot_Original)(void* __this, void* bulletGO, UnityEngine_Vector3_o hitPoint, void* Dm);
void WeaponScript__WeaponShot(void* __this, void* bulletGO, UnityEngine_Vector3_o hitPoint, void* Dm)
{
	if (__this)
	{	void* Player = *reinterpret_cast<void**>((uintptr_t)__this + 0xE8);
		if (LocalPlayer == Player)
		{



			if (MenuVars->SilentAim)
				WeaponScript__WeaponShot_Original(__this, bulletGO, HitTarget, Dm);
			else
				WeaponScript__WeaponShot_Original(__this, bulletGO, hitPoint, Dm);
		}
		else
			WeaponScript__WeaponShot_Original(__this, bulletGO, hitPoint, Dm);
		//printf("Shot! At %f %f %f\n", hitPoint.x, hitPoint.y, hitPoint.z);
	}
}





//0x467AA0
bool (*getIsUnlockCursor_Original)(void*);
bool getIsUnlockCursor(void* obj)
{
	return true;
}


void* (*CreateBullet_Original)(void* __this, void* bulletGO, UnityEngine_Vector3_o shotPoint, UnityEngine_Vector3_o hitPoint, void* dm);
void* CreateBullet(void* __this, void* bulletGO, UnityEngine_Vector3_o shotPoint, UnityEngine_Vector3_o hitPoint, void* dm)
{
	if (MenuVars->SilentAim)
	{
		printf("Create Bullet hitpoint: %f %f %f | shotPoint %f %f %f\n",
			hitPoint.fields.x,
			hitPoint.fields.y,
			hitPoint.fields.z,
			shotPoint.fields.x,
			shotPoint.fields.y,
			shotPoint.fields.z)

			return CreateBullet_Original(__this, bulletGO, HitTarget, HitTarget, dm);
	}
	return CreateBullet_Original(__this, bulletGO, shotPoint, hitPoint, dm);
}



bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}
		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}


	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	float yaw = 0.0;
	float pitch = 0.0;

	if (MenuVars->isEsp)
	{
		if (Players.size() > 0)
		{
			float closestPlayer = -1.0f;
			for (size_t i = 0; i < Players.size(); i++)
			{
				RECT rect;
				GetWindowRect(GetDesktopWindow(), &rect);
				int width = rect.right - rect.left;
				int height = rect.bottom - rect.top;
				//int width = (int)ImGui::GetIO().DisplaySize.x;
				//int height = (int)ImGui::GetIO().DisplaySize.y;


				int localTeam = {-1};
				if (LocalPlayer) {
					localTeam = *reinterpret_cast<int*>((uintptr_t)Players[0] + 0x1BC);
				}
				
				__try {
					bool isLocal = getIsLocalPlayer(*reinterpret_cast<void**>((uintptr_t)Players[i] + 0x34));
					if (isLocal) LocalPlayer = Players[i];



	




					if (isLocal) continue;

					kube_cheat_ObscuredIntAB_o Health = *reinterpret_cast<kube_cheat_ObscuredIntAB_o*>  ((uintptr_t)Players[i] + 0x1A4);
					if (Health.fields.fakeValue <= 0.f) continue;


					UnityEngine_Vector3_o LeftFoot = GetTransformPosition((void*)getBoneById(*reinterpret_cast<void**>((uintptr_t)Players[i] + 0x1D4), HumanBodyBones::LeftFoot));
					UnityEngine_Vector3_o RightFoot = GetTransformPosition((void*)getBoneById(*reinterpret_cast<void**>((uintptr_t)Players[i] + 0x1D4), HumanBodyBones::RightFoot));
					UnityEngine_Vector3_o Head = GetTransformPosition((void*)getBoneById(*reinterpret_cast<void**>((uintptr_t)Players[i] + 0x1D4), HumanBodyBones::Head));
					UnityEngine_Vector3_o LocalPlayerPosition = GetTransformPosition((void*)getBoneById(*reinterpret_cast<void**>((uintptr_t)LocalPlayer + 0x1D4), HumanBodyBones::Head));

					UnityEngine_Vector3_o CameraPosition = GetTransformPosition((void*)GetTransform((void*)getCamera()));




					float abs_x = Head.fields.x - LocalPlayerPosition.fields.x;
					float abs_y = Head.fields.y - LocalPlayerPosition.fields.y;
					float abs_z = Head.fields.z - LocalPlayerPosition.fields.z;

					if (MenuVars->DrawFov)
						ImGui::GetForegroundDrawList()->AddCircle({ (float)width / 2.f, (float)height / 2.f }, radiusFov, IM_COL32(21, 32, 22, 255), 30, 2.f);





					UnityEngine_Vector3_o MiddleFooot = {
						(LeftFoot.fields.x + RightFoot.fields.x) / 2.f,
						(LeftFoot.fields.y + RightFoot.fields.y) / 2.f,
						(LeftFoot.fields.z + RightFoot.fields.z) / 2.f,
					};

					/*UnityEngine_Vector3_o MiddleBrain = {
						(LeftEye.x + RightEye.x) / 2.f,
						(LeftEye.y + RightEye.y) / 2.f,
						(LeftEye.z + RightEye.z) / 2.f,
					};*/


					UnityEngine_Vector3_o MiddleFoot = WorldToScreenUnity(getCamera(), MiddleFooot);
					UnityEngine_Vector3_o MiddleHead = WorldToScreenUnity(getCamera(), Head);

					MiddleHead.fields.y += 0.5;
					MiddleFoot.fields.y -= 0.2;


					if (MiddleFoot.fields.z > 0.f)
					{


						float Footx = MiddleFoot.fields.x;
						float Footy = (float)height - MiddleFoot.fields.y; //consertar eixo invertido
						float Headx = MiddleHead.fields.x;
						float Heady = (float)height - MiddleHead.fields.y; //consertar eixo invertido


						float boxHeight = fabsf(Heady - Footy); // altura da caixa

						Vector3 TL_v = { Headx - (boxHeight / 4),Heady,0.f };
						Vector3 TR_v = { Headx + (boxHeight / 4),Heady,0.f };
						Vector3 BL_v = { Footx - (boxHeight / 4),Footy,0.f };
						Vector3 BR_v = { Footx + (boxHeight / 4),Footy,0.f };





						//Esp Box

						bool isSameTeam = false;

						if (localTeam == *reinterpret_cast<int*>((uintptr_t)Players[i] + 0x1BC))
							isSameTeam = true;

						if (MenuVars->isBox)
						{
							ImGui::GetBackgroundDrawList()->AddLine({ TL_v.x,TL_v.y }, { TR_v.x,TR_v.y }, isSameTeam ? IM_COL32(0, 244, 2, 255) : IM_COL32(255, 0, 2, 255), 2.f);
							ImGui::GetBackgroundDrawList()->AddLine({ BL_v.x,BL_v.y }, { BR_v.x,BR_v.y }, isSameTeam ? IM_COL32(0, 244, 2, 255) : IM_COL32(255, 0, 2, 255), 2.f);
							ImGui::GetBackgroundDrawList()->AddLine({ BL_v.x,BL_v.y }, { TL_v.x,TL_v.y }, isSameTeam ? IM_COL32(0, 244, 2, 255) : IM_COL32(255, 0, 2, 255), 2.f);
							ImGui::GetBackgroundDrawList()->AddLine({ BR_v.x,BR_v.y }, { TR_v.x,TR_v.y }, isSameTeam ? IM_COL32(0, 244, 2, 255) : IM_COL32(255, 0, 2, 255), 2.f);
							ImGui::GetForegroundDrawList()->AddText({ TL_v.x,TL_v.y }, isSameTeam ? IM_COL32(0, 244, 2, 255) : IM_COL32(255, 0, 2, 255), isSameTeam ? "Amigo" : "Inimigo");
						}


						float tempDist = euclidean_distance(abs_x, abs_y);

						if (GetDistanceCoordsBetween((float)width / 2.f, (float)height / 2.f, Headx, Heady) <= radiusFov)
						{
							if (closestPlayer == -1.0f || tempDist < closestPlayer)
							{
								if (MenuVars->DrawFov)
								{
									closestPlayer = tempDist;
									if (!isSameTeam)
									{
										HitTarget = Head;
										ImGui::GetForegroundDrawList()->AddLine({ (float)width / 2.f,(float)height / 2.f }, { Headx, Heady }, IM_COL32(0, 255, 65, 255), 3.f);
									}
								}
							}
						}




						if (MenuVars->isDistance)
						{
							char DistanceText[250];
							//distance
							sprintf_s(DistanceText, "%.2f", tempDist);

							//distance
							ImGui::GetBackgroundDrawList()->AddText({ BR_v.x,BR_v.y }, isSameTeam ? IM_COL32(0, 244, 2, 255) : IM_COL32(255, 0, 2, 255)
								, DistanceText);
						}

						if (MenuVars->isLine)
						{
							ImGui::GetForegroundDrawList()->AddCircle({ Footx,Footy }, 2.f, isSameTeam ? IM_COL32(0, 244, 2, 255) : IM_COL32(255, 0, 2, 255), 10, 2.f);
							ImGui::GetForegroundDrawList()->AddLine({ (float)width / 2.f , (float)height }, { Footx , Footy }, isSameTeam ? IM_COL32(0, 244, 2, 255) : IM_COL32(255, 0, 2, 255), 2.f);
						}
				
					}
				}
				__except (EXCEPTION_EXECUTE_HANDLER) {

				}
			}
		}
	}

	// variables


	static int TabIndex = 0;
	static bool Open = true;


	//static bool 

	if (GetAsyncKeyState(VK_HOME) & 1)
		Open = !Open;

	if (Open)
	{
		ImGui::SetNextWindowSize({ 350,350 });
		ImGui::Begin("Cheat Kubom | By Your Name",(bool*)Open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);

		ImGui::BeginChild("#TitleMenu", { -1,30 }, true);
		ImGui::Text("Cheat Kubom | By Your Name");
		ImGui::EndChild();

		ImGui::BeginChild("#LateralMenu", { 100,-1 }, true);
		if (ImGui::Button("Menu Aim", { -1,40 })) TabIndex = 0;
		if (ImGui::Button("Menu Esp", { -1,40 })) TabIndex = 1;
		ImGui::EndChild();
		ImGui::SameLine();

		ImGui::BeginChild("#MainFrame", { -1,-1 }, true);

		if (TabIndex == 0)
		{
			ImGui::Text("Silent AIM");
			ImGui::Checkbox("Enable Silent aim", &MenuVars->SilentAim);
			ImGui::Text("Aim Fov");
			ImGui::SliderFloat("Fov", &radiusFov, 0.f, 3000.f);
			ImGui::Text("No Recoil");
			ImGui::Checkbox("No Recoil", &MenuVars->NoRecoil);
		}

		if (TabIndex == 1)
		{
			ImGui::Checkbox("Enable Esp", &MenuVars->isEsp);
			if (MenuVars->isEsp)
			{
				ImGui::Checkbox("Draw Lines", &MenuVars->isLine);
				ImGui::Checkbox("Draw Box", &MenuVars->isBox);
				ImGui::Checkbox("Draw Distance", &MenuVars->isDistance);
				ImGui::Checkbox("Draw Fov", &MenuVars->DrawFov);

			}
		}
		ImGui::EndChild();
		ImGui::End();
	}

	ImGui::Render();
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}










DWORD WINAPI MainThread(LPVOID lpReserved)
{
	SetupConsole();

	MH_Initialize();

	uintptr_t gameAssemblyBase = (uintptr_t)GetModuleHandleA("GameAssembly.dll");



	std::cout << "[INFO] GameAssembly Base: 0x" << std::hex << gameAssemblyBase << '\n';


	// player update
	uintptr_t targetFunction = gameAssemblyBase + 0x4A3C40;
	// zoom
	uintptr_t CameraZoom = gameAssemblyBase + 0xF1ABE0;
	// Weapon Recoil 
	uintptr_t WeaponRecoil = gameAssemblyBase + 0x501010;
	//Local Update
	uintptr_t LocalUpdate = gameAssemblyBase + 0x4964C0;
	// On PlayerDestroy
	uintptr_t OnDestroyed = gameAssemblyBase + 0x497480;
	// On DeadUpdate
	uintptr_t OnDeadUpdate = gameAssemblyBase + 0x4909B0;
	// On EulerAngles
	uintptr_t OnShoot = gameAssemblyBase + 0x501D80;

	uintptr_t onShotUpdate = gameAssemblyBase + 0x4FCFD0;



	//Desabilitar AntiCheat
	DisableAntiCheat();

	MH_CreateHook(reinterpret_cast<void**>(CameraZoom), &get_FieldOfView, reinterpret_cast<void**>(&get_FieldOfView_Original));
	MH_CreateHook(reinterpret_cast<void**>(LocalUpdate), &PlayerScript__LocalUpdate, reinterpret_cast<void**>(&PlayerScript__LocalUpdate_Original));
	MH_CreateHook(reinterpret_cast<void**>(WeaponRecoil), &weaponScript, reinterpret_cast<void**>(&O_weaponScript));
	MH_CreateHook(reinterpret_cast<void**>(targetFunction), &PlayerScript__Update, reinterpret_cast<void**>(&o_Update));
	MH_CreateHook(reinterpret_cast<void**>(OnDestroyed), &OnDestroy, reinterpret_cast<void**>(&OnDestroy_Original));
	MH_CreateHook(reinterpret_cast<void**>(OnShoot), &WeaponScript__WeaponShot, reinterpret_cast<void**>(&WeaponScript__WeaponShot_Original));
	MH_CreateHook(reinterpret_cast<void**>(onShotUpdate), &CreateBullet, reinterpret_cast<void**>(&CreateBullet_Original));
	MH_EnableHook(MH_ALL_HOOKS);

	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);

	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}