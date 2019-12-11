#include "Fsm.h"


FSM::FSM()
{
}

FSM::~FSM()
{
}

SDL_Rect FSM::GetAnimation()
{
	return animation;
}

void FSM::update()
{


	ticks = SDL_GetTicks();
	animationSpeed = (ticks / 100) % animationFrame;
	animation.x = animationSpeed * 80;


	if (animationCount > (animationCountTotal * 500) && animationNumber != 0)
	{
		IDLE();
		animationCount = 0;
	}
	else if (animationNumber != 0)
	{
		animationCount++;
	}



}

void FSM::IDLE()
{
	animationNumber = 0;
	changeAnimation();
}
void FSM::WALKLEFT()
{
	animationNumber = 1;
	changeAnimation();
}
void FSM::WALKRIGHT()
{
	animationNumber = 2;
	changeAnimation();
}
void FSM::CLIMB()
{
	animationNumber = 3;
	changeAnimation();
}
void FSM::DIE()
{
	animationNumber = 4;
	changeAnimation();
}

void FSM::changeAnimation()
{
	switch (animationPreviousNumber)
	{
	case 0://idel
					switch (animationNumber)
					{
					case 1:
						animationCurrentNumber = 1;
						break;

					case 2:
						animationCurrentNumber = 2;
						break;

					case 3:
						animationCurrentNumber = 3;
						break;

					case 4:
						animationCurrentNumber = 4;
						break;

					default:
						animationCurrentNumber = 0;
						break;
					}
	break;

	case 1://left
					switch (animationNumber)
					{
					case 0:
						animationCurrentNumber = 0;
						break;

					case 2:
						animationCurrentNumber = 2;
						break;

					case 3:
						animationCurrentNumber = 3;
						break;

					default:
						animationCurrentNumber = 1;
						break;
					}
		break;


	case 2://right

					switch (animationNumber)
					{
					case 0:
						animationCurrentNumber = 0;
						break;

					case 1:
						animationCurrentNumber = 1;
						break;

					case 3:
						animationCurrentNumber = 3;
						break;

					default:
						animationCurrentNumber = 2;
						break;
					}
	break;

	case 3: //climb
					switch (animationNumber)
					{
					case 0:
						animationCurrentNumber = 0;
						break;

					default:
						animationCurrentNumber = 3;
						break;
					}
		break;


	case 4: // die 
					switch (animationNumber)
					{
					case 0:
						animationCurrentNumber = 0;
						break;

					case 1:
						animationCurrentNumber = 1;
						break;

					case 2:
						animationCurrentNumber = 2;
						break;

					default:
						animationCurrentNumber = 4;
						break;
					}
		break;



	default:
		break;
	}

	UpdateAnimation();
}

void FSM::UpdateAnimation()
{
	animationPreviousNumber = animationCurrentNumber;
	switch (animationCurrentNumber)
	{
	case 0:
		animation = { 0, 150, 80, 80 };//6 frames :IdelAnimation
		animationFrame = 6;
		animationCountTotal = 6;
		break;

	case 1:
		animation = { 0, 72, 80, 80 };//12 frames :walkLeftAnimation
		animationFrame = 12;
		animationCountTotal = 12;
		break;

	case 2:
		animation = { 0, 0, 80, 80 };//12  frames :walkRightAnimation
		animationFrame = 12;
		animationCountTotal = 12;
		break;

	case 3:
		animation = { 0, 220, 80, 90 };//10 frames :climbAnimation
		animationFrame = 10;
		animationCountTotal = 10;
		break;

	case 4:
		animation = { 0, 310, 80, 90 };//10 frames :deadAnimation
		animationFrame = 10;
		animationCountTotal = 10;
		break;

	default:
		animation = { 0, 150, 80, 80 };//6 frames :IdelAnimation
		animationFrame = 6;
		animationCountTotal = 6;
		break;
	}


}
