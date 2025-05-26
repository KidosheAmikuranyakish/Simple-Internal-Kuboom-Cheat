#pragma once
//Include iostream
#ifndef _IOSTREAM_
#include <iostream>
#endif // !_IOSTREAM_


// Include Windows API
#ifndef _WINDOWS_
#include <Windows.h>
#endif // _WINDOWS_


//Maths
float euclidean_distance(float x, float y) {
	return sqrtf((x * x) + (y * y));
}

float GetDistanceCoordsBetween(float x1, float y1, float x2, float y2)
{
	return sqrtf(((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}



namespace Il2cpp {



	typedef void* (__fastcall* get_domain_T)();
	get_domain_T get_domain = reinterpret_cast<get_domain_T>((uintptr_t)(GetProcAddress(GetModuleHandleA("GameAssembly.dll"), "il2cpp_domain_get")));

	typedef const char* (__fastcall* il2cpp_string_newT)(void* domain, const char* text);
	il2cpp_string_newT il2cpp_string_new = reinterpret_cast<il2cpp_string_newT>(((uintptr_t)GetProcAddress(GetModuleHandleA("GameAssembly.dll"), "il2cpp_string_new")));
}





namespace HumanBodyBones{
    enum Part
    {
		Hip = 0,
		LeftUpperLeg = 1,
		RightUpperLeg = 2,
		LeftLowerLeg = 3,
		RightLowerLeg = 4,
		LeftFoot = 5,
		RightFoot = 6,
		Spine = 7,
		Chest = 8,
		UpperChest = 54,
		Neck = 9,
		Head = 10,
		LeftShoulder = 11,
		RightShoulder = 12,
		LeftUpperArm = 13,
		RightUpperArm = 14,
		LeftLowerArm = 15,
		RightLowerArm = 16,
		LeftHand = 17,
		RightHand = 18,
		LeftToes = 19,
		RightToes = 20,
		LeftEye = 21,
		RightEye = 22,
		Jaw = 23,
		LeftThumbProximal = 24,
		LeftThumbIntermediate = 25,
		LeftThumbDistal = 26,
		LeftIndexProximal = 27,
		LeftIndexIntermediate = 28,
		LeftIndexDistal = 29,
		LeftMiddleProximal = 30,
		LeftMiddleIntermediate = 31,
		LeftMiddleDistal = 32,
		LeftRingProximal = 33,
		LeftRingIntermediate = 34,
		LeftRingDistal = 35,
		LeftLittleProximal = 36,
		LeftLittleIntermediate = 37,
		LeftLittleDistal = 38,
		RightThumbProximal = 39,
		RightThumbIntermediate = 40,
		RightThumbDistal = 41,
		RightIndexProximal = 42,
		RightIndexIntermediate = 43,
		RightIndexDistal = 44,
		RightMiddleProximal = 45,
		RightMiddleIntermediate = 46,
		RightMiddleDistal = 47,
		RightRingProximal = 48,
		RightRingIntermediate = 49,
		RightRingDistal = 50,
		RightLittleProximal = 51,
		RightLittleIntermediate = 52,
		RightLittleDistal = 53,
		LastBone = 55,
    };
};


struct UnityString {
	void* klass;
	void* monitor;
	int length;
	char chars[1];
	char* getChars() {
		return chars;
	}
};





/*
// Game Structs 
struct UnityEngine_Vector3_Fields {
    float x;
    float y;
    float z;
};

//@brief Unity Vector 3
struct UnityEngine_Vector3_o {
    float x;
    float y;
    float z;
	UnityEngine_Vector3_o operator - (const UnityEngine_Vector3_o& other)
	{
		x - other.x;
		y - other.y;
		z - other.z;
	}
};
*/
/*
struct UnityEngine_Matrix4x4_Fields {
    float Matrix[16];
};

//@brief Unity Matrix 4x4
struct UnityEngine_Matrix4x4_o {
    UnityEngine_Matrix4x4_Fields fields;
};*/

//@brief Vector 4
struct Vector4 {
    float x, y, z, w;
};

//@brief Screen
struct Screen_t
{
    float x, y;
};

//@brief Vector 3
typedef struct Vector3_d {
    float x, y, z;
} Vector3;

//@brief Vector 2
typedef struct Vector2_d {
    float x, y;
} Vector2;



/*
struct kube_cheat_ObscuredIntAB_Fields {
    int32_t hvh;
    int32_t hvl;
    int32_t fakeValue;
};
*/
/*@bried Obcured Val
struct kube_cheat_ObscuredIntAB_o {
    kube_cheat_ObscuredIntAB_Fields fields;
};


/*@brief quaternion
struct UnityEngine_Quaternion_o {
	float x;
	float y;
	float z;
	float w;
};

/////////////
//         //
//UNITY API//
//         //
/////////////


/*
*@brief Obtém a camera da UnityGetCameraMain
*/
void* getCamera()
{
    return (((void* ( __fastcall*)())((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF1AC10))());
}

/*
*@brief Retorna um "UnityEngine_Vector3_o" com as posições do Jogador.
*/
UnityEngine_Vector3_o WorldToScreenUnity(void* camera, UnityEngine_Vector3_o Position)
{
    return (((UnityEngine_Vector3_o(*)(void*, UnityEngine_Vector3_o))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF1A7C0))(camera, Position));
}

void WorldToScreenUnity_Injected(void* camera, UnityEngine_Vector3_o position, int32_t eye, UnityEngine_Vector3_o& out)
{
	(((void (*)(void*, UnityEngine_Vector3_o, int32_t eye, UnityEngine_Vector3_o&))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF1A780))(camera, position ,eye,out));
}



/*
*@brief Retorna a transform de algum component E.g PlayerClass, PlayerScript
*/
void* GetTransform(void* object)
{
    return (((void* (*)(void*))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF32E00))(object));
}

/*
* @brief Obtem a posição da Transform
*/
UnityEngine_Vector3_o GetTransformPosition(void* transform)
{
    return (((UnityEngine_Vector3_o(*)(void*))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF42AA0))(transform));
}


UnityEngine_Matrix4x4_o GetMatrix(void* camera)
{
    return (((UnityEngine_Matrix4x4_o(*)(void*))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF1AF90))(camera));
}



void* getBoneById(void* Animator, int32_t boneID)
{
    return (((void* (*)(void*, int32_t))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF13760))(Animator, boneID));
}

int getCameraWidth(void* camera)
{
    return (((int(*)(void*))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF1AD60))(camera));
}

int getCameraHeight(void* camera)
{
    return (((int(*)(void*))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF1ACC0))(camera));
}


bool getIsLocalPlayer(void* photon)
{
	return (((bool (*)(void*))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0x22B600))(photon));
}


UnityEngine_Quaternion_o Quaternion_LookRotation_Unity(UnityEngine_Vector3_o forward)
{
	return  (((UnityEngine_Quaternion_o(*)(UnityEngine_Vector3_o))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF3B0C0))(forward));
}

UnityEngine_Vector3_o Vector3Slerp(UnityEngine_Vector3_o a, UnityEngine_Vector3_o b, float t)
{
	return (((UnityEngine_Vector3_o(*)(UnityEngine_Vector3_o, UnityEngine_Vector3_o, float))((uintptr_t)GetModuleHandleA("GameAssembly.dll") + 0xF45F20))(a, b, t));
}



bool WorldToScreen(UnityEngine_Vector3_o pos, Screen_t& screen, float matrix[16], int windowWidth, int windowHeight)
{
    Vector4 clipCoords;
    clipCoords.x = pos.fields.x * matrix[0] + pos.fields.y * matrix[4] + pos.fields.z * matrix[8] + matrix[12];
    clipCoords.y = pos.fields.x * matrix[1] + pos.fields.y * matrix[5] + pos.fields.z * matrix[9] + matrix[13];
    clipCoords.z = pos.fields.x * matrix[2] + pos.fields.y * matrix[6] + pos.fields.z * matrix[10] + matrix[14];
    clipCoords.w = pos.fields.x * matrix[3] + pos.fields.y * matrix[7] + pos.fields.z * matrix[11] + matrix[15];

    if (clipCoords.w < 0.1f)
        return false;

    Vector3 NDC;
    NDC.x = clipCoords.x / clipCoords.w;
    NDC.y = clipCoords.y / clipCoords.w;
    NDC.z = clipCoords.z / clipCoords.w;

    screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
    screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
    return true;
}