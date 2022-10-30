#pragma once
#include <list>

#define	CB_CLOSE 0
#define	CB_MINIMIZE 1
#define CB_MAXIMIZE 2

namespace Win32 
{
	class RENDERKING_API Caption
	{
	public:
		struct CaptionButton {
			std::wstring Text = L"";

			INT Command = -1;
			INT Width = 50;
			RECT Rect;

			CaptionButton(std::wstring text, INT command, INT width = 50) {
				Text = text;
				Command = command;
				Width = width;
			}
		};

	private:
		BOOL m_ShowTitle = TRUE;

		std::list<CaptionButton*> m_CaptionButtons;

	public:
		BOOL ShowTitle() { return m_ShowTitle; }
		std::list<CaptionButton*> CaptionButtons() { return m_CaptionButtons; }
	public:
		VOID ShowTitle(BOOL show) { m_ShowTitle = show; }

	public:
		VOID AddCaptionButton(CaptionButton* button);

	};
}
