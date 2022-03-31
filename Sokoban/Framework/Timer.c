#include "stdafx.h"
#include "Timer.h"

static clock_t s_prevTick;
static float s_deltaTime;

void InitializeTimer()
{
	s_prevTick = clock();
}

void UpdateTimer()
{
	clock_t currentTick = clock();

	s_deltaTime = (currentTick - s_prevTick) / (float)CLOCKS_PER_SEC; //CLOCKS_PER_SEC: 결과 값을 초로 변환하는 것.
	// 현재 프레임 - 이전 프레임 한 값을 /(float)CLOCKS_PER_SEC 하면 델타타임이 나온다.

	s_prevTick = currentTick;
}

float GetDeltaTime()
{
	return s_deltaTime;
}