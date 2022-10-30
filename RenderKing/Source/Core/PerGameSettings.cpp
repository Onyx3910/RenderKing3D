#include "RenderKing.h"

PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{
	instance = this;
	wcscpy_s(instance->m_GameName, L"undefined");
	wcscpy_s(instance->m_ShortName, L"undefined");
	wcscpy_s(instance->m_BootTime, Common::Timer::GetDateTimeString(TRUE).c_str());
	wcscpy_s(instance->m_SplashUrl, L"..\\RenderKing\\Content\\Images\\RenderKingSplash.bmp");
}

PerGameSettings::~PerGameSettings()
{
}
