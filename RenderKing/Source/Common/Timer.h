#pragma once

namespace Common
{
	class RENDERKING_API Timer
	{
	public:
		Timer();

		FLOAT TimeElapsed() const; // In seconds
		FLOAT DeltaTime() const; // In seconds

		VOID Reset(); // Call before message loop
		VOID Start(); // Call when unpaused
		VOID Stop(); // Call when paused
		VOID Tick(); // Call every frame

		// Get current time in string format
		static std::wstring GetTime(BOOL stripped = FALSE);

		// Get current date in string format
		static std::wstring GetDate(BOOL stripped = FALSE);

		// Get current date and time in string format
		static std::wstring GetDateTimeString(BOOL stripped = FALSE);

	private:
		DOUBLE m_SecondsPerCount;
		DOUBLE m_DeltaTime;

		INT64 m_BaseTime;
		INT64 m_PausedTime;
		INT64 m_StopTime;
		INT64 m_PrevTime;
		INT64 m_CurrentTime;

		BOOL m_Stopped;
	};
}
