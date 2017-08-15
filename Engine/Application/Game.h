#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Input.h"

class Game
{
public:
	void Start(int screenWidth = 800, int screenHeight = 600);
	void Run();
	void Shutdown();

protected:
	virtual void OnStart() = 0;
	virtual bool OnUpdate() = 0;
	virtual void OnShutdown() = 0;

	void SetWindowTitle(const char* windowTitle);
	SDL_Surface* LoadImage(const char* file);

	int GetScreenWidth() const;
	int GetScreenHeight() const;


	SDL_Window* window{};
	SDL_Surface* windowSurface{};
	Input input;
	bool isFullscreen{false};
	int fullscreenWidth{1920};
	int fullscreenHeight{1080};
	int windowedWidth{800};
	int windowedHeight{600};


	//float screenWidth;
	//float screenHeight;
};