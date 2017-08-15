#pragma once
#include "../Application/Game.h"
#include "../Application/Sprite.h"
#include <iostream>
using namespace std;

class RenderDemo : public Game 
{
protected:
	void OnStart();
	bool OnUpdate();
	void OnShutdown();

private:
	SDL_Texture* loadTexture(std::string path); //Loads individual image as texture
	SDL_Window* gWindow = nullptr; //The window to render to
	SDL_Renderer* gRenderer = nullptr; // window renderer
	SDL_Texture* gTexture = nullptr; //Current displayed texture

	void CreateWindow();
	bool loadMedia();
	void close();
};