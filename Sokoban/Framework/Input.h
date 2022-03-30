#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum KeyCode
{
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd',
} EKeyCode;

/// <summary>
/// �Է� ���¸� ������Ʈ �Ѵ�.
/// </summary>
void UpdateInput();

/// <summary>
/// ���� �����ӿ� ��ư�� ���ȴ��� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode">���� Ű �ڵ�</param>
/// <returns>���ȴٸ� true, �ƴϸ� false</returns>
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode">�ôٸ� true, �ƴϸ� false</param>
/// <returns></returns>
bool GetButtonUp(EKeyCode keyCode);

/// <summary>
/// ��ư�� ��� ���ȴ��� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode">���� Ű �ڵ�</param>
/// <returns>���ȴٸ� true, �ƴϸ� false</returns>
bool GetButton(EKeyCode keyCode);