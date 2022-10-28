#pragma once

#include "Platform/Windows32/IApplication.h"

namespace RenderKing
{
	class RENDERKING_API Simulation : public Win32::IApplication
	{
	public: 
		Simulation();
		~Simulation();

		virtual VOID PreInitialize() override;
	};
}