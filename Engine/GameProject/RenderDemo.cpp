#include "RenderDemo.h"

float SCREEN_WIDTH = 800.0f;
float SCREEN_HEIGHT = 600.0f;


void RenderDemo::OnStart()
{
}

bool RenderDemo::OnUpdate()
{
	bool quit = false;

	while(!quit)
	{
		while (input.keyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}
	}
	 
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	SDL_RenderPresent(gRenderer);

	return quit;
}

void RenderDemo::OnShutdown()
{
}

void RenderDemo::CreateWindow()
{
	bool success = true;

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) 
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else 
	{
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (gRenderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error %s\n", IMG_GetError());
				success = false;
			}
		}
	}
}

SDL_Texture* RenderDemo::loadTexture(std::string path)
{
		SDL_Texture* newTexture = NULL;

		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
			if (newTexture == NULL)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
}

bool RenderDemo::loadMedia()
{
	bool success = true;

	gTexture = loadTexture("Engine\\Assets\\Textures\\background.png"); //image path
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	
	return success;
}

void RenderDemo::close() 
{
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

