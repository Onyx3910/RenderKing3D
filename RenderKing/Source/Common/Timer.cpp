#include "RenderKing.h"
#include "Timer.h"
#include <ctime>
#include <sstream>
#include <iomanip>

namespace Common
{
	Timer::Timer()
		: m_SecondsPerCount(0.0), m_DeltaTime(-1.0), m_BaseTime(0), m_PausedTime(0), m_PrevTime(0), m_CurrentTime(0), m_StopTime(0), m_Stopped(FALSE)
	{
		INT64 countsPerSec;
		QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
		m_SecondsPerCount = 1.0 / (DOUBLE)countsPerSec;
	}

	FLOAT Timer::TimeElapsed() const
	{
		if (m_Stopped) return (FLOAT)(((m_StopTime - m_PausedTime) - m_BaseTime) * m_SecondsPerCount);
		return (FLOAT)(((m_CurrentTime - m_PausedTime) - m_BaseTime) * m_SecondsPerCount);
	}

	FLOAT Timer::DeltaTime() const
	{
		return (FLOAT)m_DeltaTime;
	}

	VOID Timer::Reset()
	{
		INT64 currentTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

		m_BaseTime = currentTime;
		m_PrevTime = currentTime;
		m_StopTime = 0;
		m_Stopped = FALSE;
	}

	VOID Timer::Start()
	{
		INT64 startTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

		// If the timer is not stopped then don't do anything
		if (!m_Stopped) return;

		// Otherwise
		// Accumulate the paused time
		m_PausedTime += (startTime - m_StopTime);

		// Current previous frame is not valid so reset it
		m_PrevTime = startTime;

		// Update stop state
		m_StopTime = 0;
		m_Stopped = FALSE;
	}

	VOID Timer::Stop()
	{
		// If we are already stopped then don't do anything
		if (m_Stopped) return;

		// Otherwise
		INT64 currentTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

		m_StopTime = currentTime; // Save the time we stopped at
		m_Stopped = TRUE; // Set flag to true
	}

	VOID Timer::Tick()
	{
		if (m_Stopped)
		{
			m_DeltaTime = 0.0;
			return;
		}

		// Get the time this frame
		INT64 currentTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		m_CurrentTime = currentTime;

		// Calculate difference in time between this frame and the previous
		m_DeltaTime = (m_CurrentTime - m_PrevTime) * m_SecondsPerCount;

		// Prepare for next frame
		m_PrevTime = m_CurrentTime;

		// Force nonnegative. The DXSDK's CDXUTTimer mentions that if the
		// processor goes into a power save mode or we get shuffled to
		// another processor, then m_DeltaTime can be negative.
		if (m_DeltaTime < 0.0)
		{
			m_DeltaTime = 0.0;
		}
	}

	// Get time in format '00:00:00'
	// Stripped = 000000
	std::wstring Timer::GetTime(BOOL stripped)
	{
		time_t now = time(0);
		tm ltm;
		localtime_s(&ltm, &now);
		std::wstringstream wss;
		wss << std::put_time(&ltm, L"%T");

		std::wstring timeString = wss.str();

		if (stripped)
		{
			std::wstring chars = L":";
			for (WCHAR c : chars)
			{
				timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
			}
		}

		return timeString;
	}

	// Get date in format '00/00/00'
	// stripped = 000000
	std::wstring Timer::GetDate(BOOL stripped)
	{
		time_t now = time(0);
		tm ltm;
		localtime_s(&ltm, &now);
		std::wstringstream wss;
		wss << std::put_time(&ltm, L"%d/%m/%y");

		std::wstring timeString = wss.str();

		if (stripped)
		{
			std::wstring chars = L"/";
			for (WCHAR c : chars)
			{
				timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
			}
		}

		return timeString;
	}

	// Get date time in format '00/00/00 00:00:00'
	// Stripped = 000000000000
	std::wstring Timer::GetDateTimeString(BOOL stripped)
	{
		std::wstring timeString = GetDate(stripped) + L" " + GetTime(stripped);

		if (stripped)
		{
			std::wstring chars = L" ";
			for (WCHAR c : chars)
			{
				timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
			}
		}

		return timeString;
	}
}
