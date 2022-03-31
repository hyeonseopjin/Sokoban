#include "stdafx.h"
#include "Stage.h"
#include "Framework/Input.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;
static int32_t s_boxOnGoalCount = 0;
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;

bool parseMapType(int i, int j, char mapType)
{
	if (mapType == '\n' || mapType == '\0')
	{
		return false;
	}

	switch (mapType)
	{
	case '\n':

		return false;

	case 'P':
		s_playerX = j;
		s_playerY = i;

	case 'a':
		s_goalCount++;

	default:
		s_map[i][j] = mapType;

		// 각 맵 타입별로 해줘야 하는 일들
	}

	// 반환은 행에 다다랐을 때
}

void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
	s_goalCount = 0;
	s_boxOnGoalCount = 0;
	s_playerX = 0;
	s_playerY = 0;
}

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);

	static char path[MAX_PATH] = { 0 };
	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", (int32_t)level);

	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage();

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i, j, ch))
			{
				break;
			}
		}

		if (feof(fp))
		{
			break;
		}
	}

	fclose(fp);
}


void UpdateStage()
{
	if (GetButtonDown(KEYCODE_W))
	{
		if (s_map[s_playerY - 1][s_playerX] != MAPTYPE_WALL && s_map[s_playerY - 1][s_playerX] != MAPTYPE_BOX
			&& s_map[s_playerY - 1][s_playerX] != MAPTYPE_BOX_ON_GOAL && s_map[s_playerY - 1][s_playerX] != MAPTYPE_GOAL
			)
		{
			s_map[s_playerY - 1][s_playerX] = MAPTYPE_PLAYER;
			s_map[s_playerY][s_playerX] = ' ';
			--s_playerY;
		}

		else if (s_map[s_playerY - 1][s_playerX] == MAPTYPE_BOX && s_map[s_playerY - 2][s_playerX] != MAPTYPE_WALL
			&& s_map[s_playerY - 2][s_playerX] != MAPTYPE_BOX && s_map[s_playerY - 2][s_playerX] != MAPTYPE_BOX_ON_GOAL)
		{
			if (s_map[s_playerY - 2][s_playerX] == MAPTYPE_GOAL)
			{
				s_map[s_playerY - 1][s_playerX] = MAPTYPE_PLAYER;
				s_map[s_playerY - 2][s_playerX] = MAPTYPE_BOX_ON_GOAL;
				s_map[s_playerY][s_playerX] = ' ';
				s_boxOnGoalCount++;
				s_playerY--;
			}
			else
			{
				s_map[s_playerY - 1][s_playerX] = MAPTYPE_PLAYER;
				s_map[s_playerY - 2][s_playerX] = MAPTYPE_BOX;
				s_map[s_playerY][s_playerX] = ' ';
				--s_playerY;
			}
		}
	};

	if (GetButtonDown(KEYCODE_D))
	{
		if (s_map[s_playerY][s_playerX + 1] != MAPTYPE_WALL && s_map[s_playerY][s_playerX + 1] != MAPTYPE_BOX
			&& s_map[s_playerY][s_playerX + 1] != MAPTYPE_BOX_ON_GOAL && s_map[s_playerY][s_playerX + 1] != MAPTYPE_GOAL
			)
		{
			s_map[s_playerY][s_playerX + 1] = MAPTYPE_PLAYER;
			s_map[s_playerY][s_playerX] = ' ';
			++s_playerX;
		}

		else if (s_map[s_playerY][s_playerX + 1] == MAPTYPE_BOX && s_map[s_playerY][s_playerX + 2] != MAPTYPE_WALL
			&& s_map[s_playerY][s_playerX + 2] != MAPTYPE_BOX && s_map[s_playerY][s_playerX + 2] != MAPTYPE_BOX_ON_GOAL)
		{
			if (s_map[s_playerY][s_playerX + 2] == MAPTYPE_GOAL)
			{
				s_map[s_playerY][s_playerX + 1] = MAPTYPE_PLAYER;
				s_map[s_playerY][s_playerX + 2] = MAPTYPE_BOX_ON_GOAL;
				s_map[s_playerY][s_playerX] = ' ';
				s_boxOnGoalCount++;
				s_playerX++;
			}
			else
			{
				s_map[s_playerY][s_playerX + 1] = MAPTYPE_PLAYER;
				s_map[s_playerY][s_playerX + 2] = MAPTYPE_BOX;
				s_map[s_playerY][s_playerX] = ' ';
				++s_playerX;
			}
		}
	};

	if (GetButtonDown(KEYCODE_S))
	{
		if (s_map[s_playerY + 1][s_playerX] != MAPTYPE_WALL && s_map[s_playerY + 1][s_playerX] != MAPTYPE_BOX
			&& s_map[s_playerY + 1][s_playerX] != MAPTYPE_BOX_ON_GOAL && s_map[s_playerY + 1][s_playerX] != MAPTYPE_GOAL
			)
		{
			s_map[s_playerY + 1][s_playerX] = MAPTYPE_PLAYER;
			s_map[s_playerY][s_playerX] = ' ';
			++s_playerY;
		}

		else if (s_map[s_playerY + 1][s_playerX] == MAPTYPE_BOX && s_map[s_playerY + 2][s_playerX] != MAPTYPE_WALL
			&& s_map[s_playerY + 2][s_playerX] != MAPTYPE_BOX && s_map[s_playerY + 2][s_playerX] != MAPTYPE_BOX_ON_GOAL)
		{
			if (s_map[s_playerY + 2][s_playerX] == MAPTYPE_GOAL)
			{
				s_map[s_playerY + 1][s_playerX] = MAPTYPE_PLAYER;
				s_map[s_playerY + 2][s_playerX] = MAPTYPE_BOX_ON_GOAL;
				s_map[s_playerY][s_playerX] = ' ';
				s_boxOnGoalCount++;
				s_playerY++;
			}
			else
			{
				s_map[s_playerY + 1][s_playerX] = MAPTYPE_PLAYER;
				s_map[s_playerY + 2][s_playerX] = MAPTYPE_BOX;
				s_map[s_playerY][s_playerX] = ' ';
				++s_playerY;
			}
		}
	};

	if (GetButtonDown(KEYCODE_A))
	{
		if (s_map[s_playerY][s_playerX - 1] != MAPTYPE_WALL && s_map[s_playerY][s_playerX - 1] != MAPTYPE_BOX
			&& s_map[s_playerY][s_playerX - 1] != MAPTYPE_BOX_ON_GOAL && s_map[s_playerY][s_playerX - 1] != MAPTYPE_GOAL
			)
		{
			s_map[s_playerY][s_playerX - 1] = MAPTYPE_PLAYER;
			s_map[s_playerY][s_playerX] = ' ';
			--s_playerX;
		}

		else if (s_map[s_playerY][s_playerX - 1] == MAPTYPE_BOX && s_map[s_playerY][s_playerX - 2] != MAPTYPE_WALL
			&& s_map[s_playerY][s_playerX - 2] != MAPTYPE_BOX)
		{
			if (s_map[s_playerY][s_playerX - 2] == MAPTYPE_GOAL)
			{
				s_map[s_playerY][s_playerX - 1] = MAPTYPE_PLAYER;
				s_map[s_playerY][s_playerX - 2] = MAPTYPE_BOX_ON_GOAL;
				s_map[s_playerY][s_playerX] = ' ';
				s_boxOnGoalCount++;
				s_playerX--;
			}
			else
			{
				s_map[s_playerY][s_playerX - 1] = MAPTYPE_PLAYER;
				s_map[s_playerY][s_playerX - 2] = MAPTYPE_BOX;
				s_map[s_playerY][s_playerX] = ' ';
				--s_playerX;
			}
		}
	};

	
	if (s_boxOnGoalCount + 1 == s_goalCount)
	{
		for (EStageLevel i = STAGE_01; i < STAGE_MAX; i++)
		{
			LoadStage(i);
		}
	}


	// 입력에 대해서 처리를 함

	// 게임이 클리어 됐는지도 파악함
}

const char** GetMap()
{
	return s_map;
}

// @인 상태에서도 if (s_boxOnGoalCount + 1 == s_goalCount) 아니라면
// 카운트 빼고 상자가 움직일 수도 있게

// 함수 정리

// 스테이지 순서대로 출력.