#include "stdafx.h"
#include "Framework/Game.h"

int main()
{
	if (false == Initialize())
	{
		puts("������ �ε��ϴµ� ������ ������ϴ�.");

		return 1;
	}

	//puts("������ �ּż� �ʹ� �����մϴ�! ��");

	return Run();
}