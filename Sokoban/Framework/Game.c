#include "stdafx.h"
#include "Game.h"

bool Initialize()
{
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