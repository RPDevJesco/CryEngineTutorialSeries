#pragma once
#include <CrySystem/ICryPlugin.h>
#include <CryGame/IGameFramework.h>

// The entry-point of the application
// An instance of CGamePlugin is automatically created when the library is loaded
// IEnginePlugin:  On startup, the engine parses the Game.cryproject file in your project directory, which in turn contains a path to our game plug-in DLL. 
// Once the plug-in is loaded, an instance of our plug-in is created, invoking the CGamePlugin constructor.
// ISystemEventListener is used for registering events to the engine
class CGamePlugin 
	: public Cry::IEnginePlugin
	, public ISystemEventListener
{
public:
	// Plug-ins utilize the engine's extension framework. This is a form of reflection allowing us to query implementations based on a specific interface.
	// In this case, we indicate that our implementation implements Cry::IEnginePlugin.
    CRYINTERFACE_SIMPLE(Cry::IEnginePlugin)
	// Set the GUID for our plug-in, this should be unique across all used plug-ins
	// Can be generated in Visual Studio under Tools -> Create GUID
    CRYGENERATE_SINGLETONCLASS_GUID(CGamePlugin, "Blank", "f01244b0-a4e7-4dc6-91e1-0ed18906fe7c"_cry_guid)

	virtual ~CGamePlugin();
	
	// Called shortly after loading the plug-in from disk
	// This is usually where you would initialize any third-party APIs and custom code
	virtual bool Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams) override;
	// ~Cry::IEnginePlugin
	
	// ISystemEventListener
	virtual void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;
	// ~ISystemEventListener
};
