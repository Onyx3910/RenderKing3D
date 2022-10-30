#include "RenderKing.h"
#include "Simulation.h"
#include "Engine/SplashScreen.h"

namespace Engine
{
	Simulation::Simulation()
		: Win32::Window(L"MainApplication", NULL)
	{
		m_Timer = new Common::Timer();
		m_d3dxContext = new Renderer::d3dxContext();
	}

	Simulation::~Simulation()
	{
	}

	VOID Simulation::PreInitialize()
	{
		Common::Logger::PrintDebugSeperator();
		Common::Logger::PrintLog(L"Applcation starting...\n");
		Common::Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
		Common::Logger::PrintLog(L"Boot Time: %s\n", Common::Timer::GetDateTimeString().c_str());
		Common::Logger::PrintLog(L"Engine Mode: %s\n", Engine::EngineModeToString().c_str());
		Common::Logger::PrintDebugSeperator();

		SplashScreen::Open();

		Win32::Window::RegisterNewClass();
		Win32::Window::Initialize();
	}

	VOID Simulation::Initialize()
	{
		Timer()->Reset();
		D3DXContext()->Initialize((Win32::Window*)this);
	}

	VOID Simulation::Update()
	{
		Timer()->Tick();
		D3DXContext()->CalculateFrameStats(Timer());
	}

	LRESULT Simulation::MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{

		}

		return Window::MessageHandler(hwnd, message, wParam, lParam);
	}
}