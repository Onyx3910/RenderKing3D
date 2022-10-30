#include "RenderKing.h"
#include "CmdLineArgs.h"
#include <algorithm>

VOID Common::CmdLineArgs::ReadArguments()
{
	int argc = 0;
	LPWSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);

	// Start at index 1 to skip URL
	for (int i = 1; i < argc; ++i)
	{
		std::wstring key = argv[i]; // Get ith argument
		if (key[0] == '-')
		{
			key.erase(0, 1); // Erase hyphen
			std::transform(key.begin(), key.end(), key.begin(), ::tolower);
			ReadArgument(key.c_str());
		}
	}
}

VOID Common::CmdLineArgs::ReadArgument(const WCHAR* argument)
{
	if (wcscmp(argument, L"mtail") == 0)
		Logger::StartMTail();
	if (wcscmp(argument, L"debug") == 0)
		Engine::SetMode(Engine::EngineMode::DEBUG);
	if (wcscmp(argument, L"editor") == 0)
		Engine::SetMode(Engine::EngineMode::EDITOR);
	if (wcscmp(argument, L"server") == 0)
		Engine::SetMode(Engine::EngineMode::SERVER);
}
