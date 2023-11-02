// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BuglyModule.h"

#include "Misc/ConfigCacheIni.h"

#include "BuglyDefines.h"
#if PLATFORM_ANDROID
#include "Android/AndroidBugly.h"
#elif PLATFORM_IOS
#include "IOS/IOSBugly.h"
#endif

DEFINE_LOG_CATEGORY(LogBugly)

#define LOCTEXT_NAMESPACE "FBuglyModule"

void FBuglyModule::StartupModule()
{
#if PLATFORM_ANDROID
	Bugly = MakeShared<FAndroidBugly>();
#elif PLATFORM_IOS
	Bugly = MakeShared<FIOSBugly>();
#else
	Bugly = MakeShared<FGenericBugly>();
#endif
}

void FBuglyModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if (Bugly.IsValid())
	{
		Bugly->OnShutdown();
	}

	Bugly.Reset();
}

FBuglyPtr FBuglyModule::GetBugly()
{
	return Bugly;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBuglyModule, Bugly)