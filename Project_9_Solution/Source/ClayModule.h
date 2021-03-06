#ifndef __CLAY_H__
#define __CLAY_H__

#include "Module.h"
#include "Animation.h"
#include "Application.h"

struct SDL_Texture;

class ClayModule : public Module
{
public:
	//Constructor
	ClayModule(bool startEnabled);

	//Destructor
	~ClayModule();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate() override;

	// Disables the player and the enemies
	bool CleanUp();

public:

	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* textureVS = nullptr;
	SDL_Texture* refTexture = nullptr;

	// Animation for the public
	Animation background;

	Animation refereeAnim;

	Animation leftJapanese;
	Animation leftGerman;
	Animation leftEnglish;
	Animation rightJapanese;
	Animation rightGerman;
	Animation rightEnglish;

	uint counter = 000;
};

#endif
