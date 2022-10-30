#include "BlankProject.h"
#include "Engine/Simulation.h"
#include "Platform/Windows32/WinEntry.h"

class BlankProject : public Engine::Simulation
{
public:
	BlankProject();
	~BlankProject();

public:
	// Called to setup our pergame settings
	VOID SetupPerGameSettings();

	// Called to initialize the BlankProject
	VOID Initialize() override;

	// Game Loop - Called in a loop while the BlankProject is running
	VOID Update() override;
};

ENTRYAPP(BlankProject)

BlankProject::BlankProject()
{
}

BlankProject::~BlankProject()
{
}

VOID BlankProject::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
	PerGameSettings::SetSplashUrl(IDS_SPLASHURL);
}

VOID BlankProject::Initialize()
{
	Simulation::Initialize();
}

VOID BlankProject::Update()
{
	Simulation::Update();
}
