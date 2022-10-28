#pragma once

#include "PLatform/WIN32/IApplication.h"

class Application : public IApplication
{
public:
	Application();
	~Application();

public:
	// Called to setup our pergame settings
	VOID SetupPerGameSettings();

	// Called to initialize the application
	VOID Initialize();

	// Game Loop - Called in a loop while the application is running
	VOID Update();
};