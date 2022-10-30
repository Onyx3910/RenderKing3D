#include "RenderKing.h"

#include "IApplication.h"
#include "Common/CmdLineArgs.h"


extern Win32::IApplication* EntryApplication();

INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Engine::Simulation* simulation = dynamic_cast<Engine::Simulation*>(EntryApplication());
	if (!simulation) return 1;

	PerGameSettings GameSettings;
	simulation->SetupPerGameSettings();

	Common::CmdLineArgs::ReadArguments();

	Common::Logger logger;

	simulation->PreInitialize();
	simulation->Initialize();

	MSG msg = { 0 };
	simulation->Timer()->Reset();
	while (msg.message != WM_QUIT)
	{
		// If there are Window messages then process them.
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			simulation->Update();
			simulation->D3DXContext()->Draw(simulation->Timer()->DeltaTime());
		}
	}

	return 0;
}