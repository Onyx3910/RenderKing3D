#include "RenderKing.h"

namespace Engine
{
	RKEngine g_RenderKingEngine; // Creates engine

	VOID SetMode(EngineMode mode)
	{
		g_RenderKingEngine.SetEngineMode(mode);
	}

	EngineMode GetMode()
	{
		return g_RenderKingEngine.GetEngineMode();
	}

	std::wstring RENDERKING_API EngineModeToString()
	{
		switch (Engine::GetMode())
		{
		case EngineMode::DEBUG:		return L"Debug";
		case EngineMode::RELEASE:	return L"Release";
		case EngineMode::SERVER:	return L"Server";
		case EngineMode::EDITOR:	return L"Editor";
		default:					return L"None";
		}
	}
}

RKEngine::RKEngine()
{
#ifdef _DEBUG
	m_EngineMode = EngineMode::DEBUG;
#else
	m_EngineMode = EngineMode::RELEASE;
#endif

}

RKEngine::~RKEngine()
{
}

EngineMode RKEngine::GetEngineMode()
{
	return m_EngineMode;
}

VOID RKEngine::SetEngineMode(EngineMode mode)
{
	m_EngineMode = mode;
}
