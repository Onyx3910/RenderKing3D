#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class RENDERKING_API IApplication
{
public:
	IApplication();
	virtual ~IApplication() {};

public:
	// Called to setup our pergame settings
	virtual VOID SetupPerGameSettings() = 0;

	// Called to initialize the application
	virtual VOID Initialize() = 0;

	// Game Loop - Called in a loop while the application is running
	virtual VOID Update() = 0;
};

IApplication* EntryApplication();