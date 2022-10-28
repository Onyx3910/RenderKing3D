#include "RenderKing.h"
#include "Simulation.h"
#include "Engine/SplashScreen.h"

RenderKing::Simulation::Simulation()
{
}

RenderKing::Simulation::~Simulation()
{
}

VOID RenderKing::Simulation::PreInitialize()
{
	Logger::PrintDebugSeperator();
	Logger::PrintLog(L"Applcation starting...\n");
	Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
	Logger::PrintLog(L"Boot Time: %s\n", Time::GetDateTimeString().c_str());
	Logger::PrintLog(L"Engine Mode: %s\n", Engine::EngineModeToString().c_str());
	Logger::PrintDebugSeperator();

	SplashScreen::Open();
}
