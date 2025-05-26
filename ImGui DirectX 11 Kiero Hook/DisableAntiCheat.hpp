#pragma once

void (*StartDetection_Original)(void*);
void StartDetection(void* _this){
	printf("StartDetection Chamado!\n");

	return;
}


void (*get_GetOrCreateInstance_Original)();
void get_GetOrCreateInstance(){
	printf("get_GetOrCreateInstance Detection Chamado!\n");
	return;
}

void (*OnCheatingDetected_Original)(void*);
void OnCheatingDetected(void* __this)
{
	printf("OnCheatingDetected Detection Chamado!\n");
	return;
}

void (*ObjectsHolderScript__Banned_O)(void*, int32_t reason);
void ObjectsHolderScript__Banned(void* __this, int32_t reason)
{
	printf("OnCheatingDetected Detection Chamado!\n");
	return;
}


void (*Ban_o)(void*, int32_t reason);
void Ban(void* __this, int32_t reason)
{
	printf("OnCheatingDetected Detection Chamado!\n");
	return;
}


void DisableAntiCheat()
{
	uintptr_t GameModule = (uintptr_t)GetModuleHandleA("GameAssembly.dll");


	if (MH_CreateHook(reinterpret_cast<void**>(GameModule + 0x5DC860), &StartDetection, reinterpret_cast<void**>(&StartDetection_Original)) == MH_OK)
	{
		printf("ANTI BAN [ON]\n");
	}
	//MH_CreateHook(reinterpret_cast<void**>(GameModule + 0x5DCC30), &get_GetOrCreateInstance, reinterpret_cast<void**>(&get_GetOrCreateInstance_Original));
	MH_CreateHook(reinterpret_cast<void**>(GameModule + 0x481720), &ObjectsHolderScript__Banned, reinterpret_cast<void**>(&ObjectsHolderScript__Banned_O));
	MH_CreateHook(reinterpret_cast<void**>(GameModule + 0x59EF80), &Ban, reinterpret_cast<void**>(&Ban_o));

}