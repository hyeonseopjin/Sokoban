#pragma once

#include <stdint.h>
#include <stdbool.h>

/// 게임과 관련된 데이터를 초기화 한다.
// 정상적으로 초기화 했으면 true, 아니면 false 리턴

bool Initialize();


// 게임을 동작시킨다
// 정상적으로 종료되면 0 리턴
int32_t Run();