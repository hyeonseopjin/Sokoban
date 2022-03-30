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
	// Game Loop: -> �÷��̾�κ����� �Է��� �ϵ����� �и���Ų��.
	
	// Game Loop�� ��ü�� Frame
	// 60�������̸� while�� 1�ʿ� 60�� ���� ��.
	while (true)
	{
		// �Է� ó��
		processInput();
		// ������Ʈ
		update();
		// ������
		render();
	}
}