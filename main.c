#include <stdio.h>
#include <Windows.h>

#define FRAME_WIDTH 30
#define FRAME_HEIGHT 25

#define WIDTH 10
#define HEIGHT 20

// Cursor movement and cursor type set
// Code from https://m.blog.naver.com/moon44432/220664296155

void setPos(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

// TODO: remove this if not used
void setCursorType(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void removeCursor() {
	CONSOLE_CURSOR_INFO CurInfo;

	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void render(int *frame) {
	for (int i = 0; i < FRAME_HEIGHT; i++) {
		for (int j = 0; j < FRAME_WIDTH; j++) {
			printf("%s", *(frame + i * FRAME_WIDTH + j));
		}
	}
}

void printFrame() {
	printf("\n");
	printf("  ┌──────────┬────┐\n");
	printf("  │                    │ Next   │\n");
	printf("  │                    │        │\n");
	printf("  │                    │□□□□│\n");
	printf("  │                    │□□□□│\n");
	printf("  │                    ├────┤\n");
	printf("  │                    │        │\n");
	printf("  │                    │        │\n");
	printf("  │                    │        │\n");
	printf("  │                    │ Level  │\n");
	printf("  │                    │ 00000  │\n");
	printf("  │                    │        │\n");
	printf("  │                    │ Score  │\n");
	printf("  │                    │ 00000  │\n");
	printf("  │                    │        │\n");
	printf("  │                    │ Lines  │\n");
	printf("  │                    │ 00000  │\n");
	printf("  │                    │        │\n");
	printf("  │                    │        │\n");
	printf("  │                    │        │\n");
	printf("  └──────────┴────┘\n");
}

int main() {
	setCursorType(NOCURSOR);

	printFrame();

	return 0;
}