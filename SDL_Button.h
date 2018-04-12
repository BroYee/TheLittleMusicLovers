#pragma once

#include "C:\\SDL2-2.0.8\\include\\sdl.h"
#include "C:\\SDL2-2.0.8\\include\\sdl_main.h"

#pragma comment(lib, "C:\\SDL2-2.0.8\\lib\\x86\\SDL2.lib")
#pragma comment(lib, "C:\\SDL2-2.0.8\\lib\\x86\\SDL2main.lib")

class MAINGAME;
class CSystem;
class STARTSCREEN;

class BUTTON
{
private:
	enum eButtonState { BUTTONDOWN, BUTTONUP };

	SDL_Texture* imgUp;
	SDL_Texture* imgDown;
	SDL_Texture* imgCurrent;
	
	SDL_Rect* rtClip;

	int nX, nY;
	bool bIsVisible = true;

	bool isDeleted = false;

	int(*func)();

public:

	void InitButton(SDL_Renderer* screen, const char* szUp, const char* szDown, int x, int y, int(*f)(void));
	void Release(); // �޸� ����
	void Draw(SDL_Renderer* screen); // ��ư �׸���

	eButtonState GetState();
	void ClickDown();
	void ClickUp(CSystem* system);

	bool IsOver(int px, int py); // ���콺�� ��ư ��
	void Toggle(); // ����
	void ResetOnUp(); // ������ Up ���·�
	void SetCoord(int x, int y); // ��ǥ ����
	void SetVisible(bool visible);
	bool IsVisible();

	void MouseDown(int px, int py);
	void MouseUp(CSystem* system, int px, int py);

	// StartScreen
	void StartGame(MAINGAME*& mainGame, SDL_Renderer* screen);
	void ExitGame(CSystem* system);
	void StartHowTo();
	void StartCredit();

	//InGame
	void GoToStart(STARTSCREEN*& startScreen, SDL_Renderer* screen);

	SDL_Texture* GetCurrentImg();
	SDL_Rect* GetRtClip();

};
