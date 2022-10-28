#pragma once

#include "Platform/Windows32/Window.h"

namespace SplashScreen
{
	VOID RENDERKING_API Open();
	VOID RENDERKING_API Close();
	VOID RENDERKING_API AddMessage(CONST WCHAR* message);
}

class RENDERKING_API SplashWindow : public Win32::Window
{
public:
	SplashWindow();
	~SplashWindow();

	virtual LRESULT MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:
	WCHAR m_outputMessage[MAX_NAME_STRING];
};