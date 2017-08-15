#include "Game.h"
#include <iostream>
#include <assert.h>
using namespace std;

void Game::Start(int screenWidth, int screenHeight)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Failed to initialize SDL: " << SDL_GetError() << endl;
	}
	else
	{
		Uint32 flags = SDL_WINDOW_SHOWN;

		if (isFullscreen)
		{
			flags |= SDL_WINDOW_FULLSCREEN;
		}
		
		window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GetScreenWidth(), GetScreenHeight(), flags);

		if (window == nullptr)
		{
			cout << "Failed to create window: " << SDL_GetError() << endl;
		}
		else
		{
			windowSurface = SDL_GetWindowSurface(window);
		}
	}

	input.init();
	OnStart();
}

void Game::Run()
{
	bool quit = false;
	SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return;
			}
		}

		input.update();

		quit = OnUpdate();

		SDL_UpdateWindowSurface(window);
		//SDL_Delay(1);

		if (input.keyHit(SDL_SCANCODE_F))
		{
			isFullscreen = !isFullscreen;
			if (isFullscreen)
			{
				SDL_SetWindowSize(window, 1920, 1080);
				cout << "User toggled fullscreen." << endl;
				SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
			}
			else
			{
				SDL_SetWindowSize(window, 800, 600);
				cout << "user switched to windowd mode." << endl;
				SDL_SetWindowFullscreen(window, 0);
				SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
			}
			windowSurface = SDL_GetWindowSurface(window);
		}

	}
}

void Game::Shutdown()
{
	OnShutdown();

	input.kill();

	SDL_FreeSurface(windowSurface);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::SetWindowTitle(const char* windowTitle)
{
	assert(window != nullptr);
	SDL_SetWindowTitle(window, windowTitle);
}

SDL_Surface* Game::LoadImage(const char* file)
{
	SDL_Surface* image = nullptr;
	SDL_Surface* convertedImage = nullptr;

	image = IMG_Load(file);

	if (image != nullptr)
	{
		convertedImage = SDL_ConvertSurface(image, windowSurface->format, 0);
		SDL_FreeSurface(image);

		if (convertedImage != nullptr)
		{
			Uint32 color = SDL_MapRGB(convertedImage->format, 255, 0, 255);
			SDL_SetColorKey(convertedImage, SDL_TRUE, color);
		}
	}

	return convertedImage;
}

int Game::GetScreenWidth() const
{
	return isFullscreen ? fullscreenWidth : windowedWidth;
}

int Game::GetScreenHeight() const
{
	return isFullscreen ? fullscreenHeight : windowedHeight;
}