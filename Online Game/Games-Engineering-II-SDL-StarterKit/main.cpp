#include <iostream>
#include <thread>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include <Game.h>
#include <Client.h>

using namespace std;

int main(int argc, char** argv){
	
	Game* game = new Game();



	

	//Adjust screen positions as needed
	game->Initialize("SDL cool fun game ",300,100,800,600, SDL_WINDOW_INPUT_FOCUS);
	

	while(game->IsRunning())
	{
		game->HandleEvents();
		game->Update();
		game->Render();



	}



	game->CleanUp();
	


	return 0;

}


