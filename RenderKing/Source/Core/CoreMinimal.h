
#pragma once 

#include "CoreDefinitions.h"

#include "Engine/RKEngine.h"

#include "Common/Logger.h"
#include "Common/Timer.h"
#include "Core/PerGameSettings.h"


#ifdef WIN32

#include "Platform/Windows32/Win32Utils.h"
#include "Platform/Windows32/SubObject.h"
#include "Platform/Windows32/Caption.h"
#include "Platform/Windows32/Window.h"
#include "Platform/Windows32/IApplication.h"

#endif

#include "Renderer/d3dUtil.h"
#include "Renderer/d3dxContext.h"