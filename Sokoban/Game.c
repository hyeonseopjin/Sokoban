#include "stdafx.h"
#include "Framework/Game.h"
#include "Framework/Renderer.h"

bool Initialize()
{
	if (false == InitializeRenderer())
	{
		return false;
	}

	return true;
}

void processInput()
{

}

void update()
{

}

void render()
{
	RenderMap();
}

int32_t Run()
{
	// Game Loop: -> 플레이어로부터의 입력을 하드웨어와 분리시킨다.
	
	// Game Loop의 전체를 Frame
	// 60프레임이면 while이 1초에 60번 도는 것.
	while (true)
	{
		// 입력 처리
		processInput();
		// 업데이트
		update();
		// 렌더링
		render();
	}
}