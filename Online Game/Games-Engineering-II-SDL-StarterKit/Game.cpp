#include <Game.h>
#include <iostream>
#include <thread>



using namespace std;

Game::Game() : m_running(false)
{


}

Game::~Game()
{
}

vector<int> Game::numberFromString()
{
	//bool redWin = true;
	not_digit notADigit;



	string::iterator end = std::remove_if(playerTwoCords.begin(), playerTwoCords.end(), notADigit);

	string all_numbers(playerTwoCords.begin(), end);
	stringstream ss(all_numbers);
	vector<int> vec;

	int i;
	for (; ss >> i;)
	{
		vec.push_back(i);
	}

	return vec;
}

bool Game::Initialize(const char* title, int xpos, int ypos, int width, int height, int flags)
{

	if (!myClient->Connect()) //If client fails to connect...
	{
		std::cout << "Failed to connect to server..." << std::endl;
		system("pause");
		return -1;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_p_Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if(m_p_Window != 0)
		{
			m_p_Renderer = SDL_CreateRenderer(m_p_Window, -1, 0);
			if(m_p_Renderer != 0)
			{
				SDL_SetRenderDrawColor(m_p_Renderer, 255, 255, 255, 255);
			}
			else
			{
				return false;
			}

			player->Init(m_p_Renderer);
			player->SetPosition(0, 0);

			playerTwo->Init(m_p_Renderer);
			playerTwo->SetPosition(600, 400);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	m_running = true;

	return true;
}

void Game::Render()
{
	SDL_RenderClear(m_p_Renderer);
	player->render(m_p_Renderer);
	playerTwo->render(m_p_Renderer);

	SDL_RenderPresent(m_p_Renderer);
}

void Game::Update()
{
	m_totalTicks = SDL_GetTicks();
	m_totalTicks -= m_startingTickCount;


	std::cout << std::to_string(m_totalTicks / 60) << std::endl;


	playerTwoCords = myClient->getOpponantsCoords();

	playerTwoX  = numberFromString().at(0);
	playerTwoY = numberFromString().at(1);
	playerTwo->SetPosition(playerTwoX, playerTwoY);


	if (player->Checkcollision(playerTwo->GetCenterX(), player->GetCenterY()))
	{
		
		player->Reset();
		player->Init(m_p_Renderer);
		player->SetPosition(600, 400);

		playerTwo->Reset();
		playerTwo->Init(m_p_Renderer);
		playerTwo->SetPosition(0, 0);

		m_startingTickCount = SDL_GetTicks();
		

	}

	
}

void Game::HandleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	player->handleEvent(event);


		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_running = false;
				break;
			default:
				player->move(600, 800);
				myClient->SendString(player->GetPosAsString()); //Send string to server
				break;
			}
		}
		
	

	

}

bool Game::IsRunning()
{
	return m_running;
}

void Game::CleanUp()
{
	SDL_DestroyWindow(m_p_Window);
	SDL_DestroyRenderer(m_p_Renderer);
	SDL_Quit();
}


