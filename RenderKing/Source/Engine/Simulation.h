#pragma once

namespace Engine
{
	class RENDERKING_API Simulation : public Win32::IApplication, public Win32::Window
	{
	public: 
		Simulation();
		~Simulation();

		virtual VOID PreInitialize() override;
		virtual VOID Initialize() override;
		virtual VOID Update() override;
		virtual LRESULT MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	private:
		Common::Timer* m_Timer;
	public:
		Common::Timer* Timer() { return m_Timer; }
	};
}