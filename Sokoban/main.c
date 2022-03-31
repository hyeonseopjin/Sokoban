#include "stdafx.h"
#include "Framework/Game.h"

int main()
{
	if (false == Initialize())
	{
		puts("게임을 로딩하는데 문제가 생겼습니다.");

		return 1;
	}

	//puts("도움을 주셔서 너무 감사합니다! ♥");

	return Run();
}