#include <dlfcn.h>
#include <android/log.h>
#include <jni.h>
#include <string>
#include <string.h>
#include "mcpelauncher.h"
#include "substrate.h"

using namespace std;

static string (*Name_Real)(void* p);
string versionNameHook(void* p){
	return "Get Hacked Minecraft!";
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	void* handle = dlsym(RTLD_DEFAULT, "_ZN6Common20getGameVersionNameEv");
	mcpelauncher_hook(handle, (void*)&versionNameHook, (void**)&Name_Real);
	
	return JNI_VERSION_1_2;
}
