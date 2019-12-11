#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <Dot.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <Client.h>



struct not_digit {
	bool operator()(const char c)
	{
		return c != ' ' && !isdigit(c);
	}
};

class Game
{
public:
	Game();
	~Game();




	std::string userinput; //holds the user's chat message

	Dot* player = new Dot(true);
	Dot* playerTwo = new Dot(false);


	int playerTwoX;
	int playerTwoY;

	Client* myClient = new Client("149.153.106.153", 1111, player);//Create client to connect to server 127.0.0.1 [localhost] on port 1111


	Uint32 m_totalTicks;
	Uint32 m_startingTickCount = 0;

	bool Initialize(const char*, int, int, int, int, int);
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();

	std::string playerTwoCords = "X: 600, Y: 400";;
	std::vector<int> numberFromString();

private:
	bool m_running;
	SDL_Window* m_p_Window;
	SDL_Renderer* m_p_Renderer;
};
#endif

