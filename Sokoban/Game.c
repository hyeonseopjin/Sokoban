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
	// 0.5�� �������� Ư�� �޼��� �����̱�

	Sleep(1);

	float timeSpace = 0.5;

	sum += GetDeltaTime(); // ��Ÿ Ÿ���� ���� ���ϸ� ������ ���� ������ ���´�.

	if (sum > timeSpace) // ��Ÿ Ÿ���� ���� ���� ���� timeSpace���� ũ�� 0.5�ʰ� ���� ��.
	{
		sum = 0; // sum = 0�� �־��� �� Run�Լ����� while������ ��� ���ѷ����ϱ� �ٽ� sum = 0���� �ʱ�ȭ
		setMessage("������");
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