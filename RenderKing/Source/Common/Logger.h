#pragma once

#include <string>

namespace Common
{
	class RENDERKING_API Logger
	{
	private:
		static Logger* instance;
	public:
		static Logger* Instance() { return instance; }

	public:
		Logger();
		~Logger();

		static VOID PrintLog(const WCHAR* fmt, ...);
		static std::wstring LogDirectory();
		static std::wstring LogFile();

		// Print a line of '-' chars
		static VOID PrintDebugSeperator();

		// Check to see if MTail is already running
		static BOOL IsMTailRunning();

		// Start MTail application
		static VOID StartMTail();
	};
}