#include "GP4_MainMenuGameMode.h"
#include "GP4_GameInstance.h"
#include "Kismet/GameplayStatics.h"

// Impl in main menu widget

void AGP4_MainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = Cast<UGP4_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (GameInstance != nullptr)
	{
		bool bIsNewGame = GameInstance->IsNewGame();
		// Widget layout wether its a new game or if theres a save
		OnShowMainMenu(bIsNewGame);
	}
}
// Start a new game
void AGP4_MainMenuGameMode::OnNewGame_Implementation(FName MapNameToLoad)
{
	if (GameInstance == nullptr) return;
	
	if (GameInstance->CreateNewSaveGame())
	{
		FLatentActionInfo LatentInfo;
		//UGameplayStatics::LoadStreamLevel(GetWorld(), MapNameToLoad, true, false, LatentInfo);
	}
}
// Load a saved game
void AGP4_MainMenuGameMode::OnLoadGame_Implementation(FName MapNameToLoad)
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(GetWorld(), MapNameToLoad, true, false, LatentInfo);
}
