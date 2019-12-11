#pragma once
#include <SDL.h>
#include <SDL_image.h>


class FSM
{

public:
	FSM();
	~FSM();


	bool Initialize(const char*, int, int, int, int, int);
	void LoadContent();


	SDL_Rect GetAnimation();

	void update();

	void IDLE();
	void WALKLEFT();
	void WALKRIGHT();
	void CLIMB();
	void DIE();
	 
	void changeAnimation();
	void UpdateAnimation();




private:

	Uint32 ticks;
	int animationSpeed;
	int animationFrameChange;
	int animationFrame = 6;

	SDL_Rect animation = { 0, 150, 80, 80 };

	int animationNumber = 0;
	int animationPreviousNumber = 0;
	int animationCurrentNumber = 0;

	/// <summary>
	/// 0 = Idel
	/// 1 = left
	/// 2 = right 
	/// 3 =  climb
	/// 4 = die 
	/// </summary>
	
	int animationCountTotal = 0;
	int animationCount = 0;
};