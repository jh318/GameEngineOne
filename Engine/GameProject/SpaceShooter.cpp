#include "SpaceShooter.h"

void SpaceShooter::OnStart()
{
	SetWindowTitle("Space Shooter");
	backgroundImage = LoadImage("Assets/Textures/space.png");
	shipImage = LoadImage("Assets/Textures/spaceship.bmp");

	playerShip.surface = shipImage;
	playerShip.position = Vector2(windowSurface->w / 2.0f, windowSurface->h / 2.0f);

	


}

bool SpaceShooter::OnUpdate()
{
	bool quit = false;

	if (input.keyDown(SDL_SCANCODE_ESCAPE))
	{
		quit = true;
	}

	SDL_Rect backgroundRect;
	backgroundRect.x = 0;
	backgroundRect.y = 0;
	backgroundRect.w = GetScreenWidth();
	backgroundRect.h = GetScreenHeight();
	SDL_BlitScaled(backgroundImage, nullptr, windowSurface, &backgroundRect);

	//SDL_BlitSurface(backgroundImage, nullptr, windowSurface, nullptr);
	
	if (input.keyDown(SDL_SCANCODE_W) || input.keyDown(SDL_SCANCODE_UP))
	{
		playerShip.position.y -= 1 * speed;
	}

	if (input.keyDown(SDL_SCANCODE_S) || input.keyDown(SDL_SCANCODE_DOWN))
	{
		playerShip.position.y += 1 * speed;
	}

	if (input.keyDown(SDL_SCANCODE_A) || input.keyDown(SDL_SCANCODE_LEFT))
	{
		playerShip.position.x -= 1 * speed;
	}

	if (input.keyDown(SDL_SCANCODE_D) || input.keyDown(SDL_SCANCODE_RIGHT))
	{
		playerShip.position.x += 1 * speed;
	}

	if (input.mouseDown(Input::MOUSE_LEFT))
	{
		target.x = (float)(input.getMouseX());
		target.y = (float)(input.getMouseY());
		moving = true;
	}

	

	if (moving)
	{
		Vector2 toTarget = target - playerShip.position;

		if (toTarget.Magnitude() > arriveDistance)
		{
			toTarget.Normalize();
			playerShip.position = playerShip.position + toTarget * playerShip.speed  * speed;
		}
		else
		{
			playerShip.position = target;
			moving = false;
		}
	}

	//Use this function to perform a fast surface copy to a destination surface.
	//You should call SDL_BlitSurface() unless you know exactly how SDL blitting works internally and how to use the other blit functions.
	SDL_Rect temp;
	playerShip.GetRect(temp);
	//SDL_Rect(tempBG);
	//Sacesh

	SDL_BlitScaled(backgroundImage, nullptr, windowSurface, nullptr);
	SDL_BlitSurface(shipImage, nullptr, windowSurface, &temp);

		
	// wrap ship around screen when it reaches the right edge.
	if (playerShip.position.x > windowSurface->w)
	{
		playerShip.position.x = 0;
	}

	if (playerShip.position.y > windowSurface->h)
	{
		playerShip.position.y = 0;
	}
	if(playerShip.position.y < 0)
	{
		playerShip.position.y = windowSurface->h;
	}
	if (playerShip.position.x < 0)
	{
		playerShip.position.x = windowSurface->w;
	}

	return quit;
}

void SpaceShooter::OnShutdown()
{
	SDL_FreeSurface(shipImage);
	SDL_FreeSurface(backgroundImage);
}