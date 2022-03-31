#include "stdafx.h"
#include "Framework/Game.h"
#include "Framework/Renderer.h"
#include "Framework/Input.h"
#include "Framework/Timer.h"
#include "Game/Stage.h"

bool Initialize() // �ʱ�ȭ
{
	if (false == InitializeRenderer()) // ���� �ʱ�ȭ
	{
		return false;
	}

	InitializeTimer();

	LoadStage(STAGE_01);

	return true;
}

void processInput()
{
	UpdateInput();
}

void update()
{
	UpdateStage();
}

void render()
{
	RenderMap();
}

int32_t Run()
{
	while (true)
	{
		UpdateTimer();
		processInput();
		update();
		render();
	}

	return 0;
}