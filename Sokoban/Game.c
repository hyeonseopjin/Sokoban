#include "stdafx.h"
#include "Framework/Game.h"
#include "Framework/Renderer.h"
#include "Framework/input.h"
#include "Framework/Timer.h"

bool Initialize() {
	if (false == InitializeRenderer())
		return false;
	return true;
}

void processInput() {
	UpdateInput();
}

static float sum = 0;

void update() {
	// 0.5초 간격으로 특정 메세지 깜박이기

	Sleep(1);

	float timeSpace = 0.5;

	sum += GetDeltaTime(); // 델타 타임을 전부 더하면 프레임 간의 간격이 나온다.

	if (sum > timeSpace) // 델타 타임을 전부 더한 값이 timeSpace보다 크면 0.5초가 지난 것.
	{
		sum = 0; // sum = 0을 넣어준 게 Run함수에서 while문으로 계속 무한루프니까 다시 sum = 0으로 초기화
		setMessage("살려줘요");
	}
}

void render() {
	RenderMap();
}

int32_t Run() {
	while (true)
	{
		UpdateTimer();
		processInput();
		update();
		render();
	}

	return 0;
}