#pragma once

class RENDERKING_API RKEngine;
namespace Engine
{
	enum EngineMode : INT
	{
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	// Exists in namespace 'engine'; Can be used anywhere the 'Engine' namespace is used
	extern RKEngine g_RenderKingEngine;

	VOID RENDERKING_API SetMode(EngineMode mode);
	EngineMode RENDERKING_API GetMode();
	std::wstring RENDERKING_API EngineModeToString();
}

using namespace Engine;
class RENDERKING_API RKEngine
{
public:
	RKEngine();
	~RKEngine();

private:
	EngineMode m_EngineMode;

	public:
		EngineMode GetEngineMode();
		VOID SetEngineMode(EngineMode mode);
};
