// Fill out your copyright notice in the Description page of Project Settings.

#include "BuglyBlueprintLibrary.h"
#include "BuglyModule.h"

void UBuglyBlueprintLibrary::Startup()
{
	FString BuglyAppId;

#if PLATFORM_ANDROID
	GConfig->GetString(TEXT("/Script/Bugly.BuglySettings"), TEXT("AndroidAppID"), BuglyAppId, GGameIni);
#elif PLATFORM_IOS
	GConfig->GetString(TEXT("/Script/Bugly.BuglySettings"), TEXT("IOSAppID"), BuglyAppId, GGameIni);
#endif

	FString BuglyAppVersion, BuglyAppChannel;
	GConfig->GetString(TEXT("/Script/Bugly.BuglySettings"), TEXT("BuglyAppVersion"), BuglyAppVersion, GGameIni);
	GConfig->GetString(TEXT("/Script/Bugly.BuglySettings"), TEXT("BuglyAppChannel"), BuglyAppChannel, GGameIni);

	FBuglyModule::Get().GetBugly()->OnStartup(BuglyAppId, BuglyAppVersion, BuglyAppChannel, false);
}

void UBuglyBlueprintLibrary::TestNativeCrash()
{
	FBuglyModule::Get().GetBugly()->TestNativeCrash();
}

void UBuglyBlueprintLibrary::SetUserId(const FString& InUserId)
{
	FBuglyModule::Get().GetBugly()->SetUserId(InUserId);
}

void UBuglyBlueprintLibrary::SetUserSceneTag(int32 InTagId)
{
	FBuglyModule::Get().GetBugly()->SetUserSceneTag(InTagId);
}

void UBuglyBlueprintLibrary::PutUserData(const FString& InKey, const FString& InValue)
{
	FBuglyModule::Get().GetBugly()->PutUserData(InKey, InValue);
}

void UBuglyBlueprintLibrary::LogVerbose(const FString& InLog, const FString& InTag/* = TEXT("")*/)
{
	FBuglyModule::Get().GetBugly()->LogVerbose(InLog, InTag);
}

void UBuglyBlueprintLibrary::LogDebug(const FString& InLog, const FString& InTag/* = TEXT("")*/)
{
	FBuglyModule::Get().GetBugly()->LogDebug(InLog, InTag);
}

void UBuglyBlueprintLibrary::LogInfo(const FString& InLog, const FString& InTag/* = TEXT("")*/)
{
	FBuglyModule::Get().GetBugly()->LogInfo(InLog, InTag);
}

void UBuglyBlueprintLibrary::LogWarning(const FString& InLog, const FString& InTag/* = TEXT("")*/)
{
	FBuglyModule::Get().GetBugly()->LogWarning(InLog, InTag);
}

void UBuglyBlueprintLibrary::LogError(const FString& InLog, const FString& InTag/* = TEXT("")*/)
{
	FBuglyModule::Get().GetBugly()->LogError(InLog, InTag);
}

void UBuglyBlueprintLibrary::SetLogCache(int32 ByteSize)
{
	FBuglyModule::Get().GetBugly()->SetLogCache(ByteSize);
}

void UBuglyBlueprintLibrary::UpdateVersion(const FString& InVersion)
{
	FBuglyModule::Get().GetBugly()->UpdateVersion(InVersion);
}

void UBuglyBlueprintLibrary::UpdateChannel(const FString& InChannel)
{
	FBuglyModule::Get().GetBugly()->UpdateChannel(InChannel);
}

void UBuglyBlueprintLibrary::PostCatchedException(const FString& InMsg)
{
	FBuglyModule::Get().GetBugly()->PostCatchedException(InMsg);
}
