#pragma once
#include <Windows.h>
#include <string>
using namespace std;

void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenPrint(SHORT x, SHORT y, string str);
void ScreenRelease();