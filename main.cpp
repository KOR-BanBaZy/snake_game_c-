#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#define UP 0x48
#define LEFT 0x4B
#define RIGHT 0x4D
#define DOWN 0x50
#define SPACE 0x20

/// 게임 시작 좌표
#define START_X_POS 3
#define START_Y_POS 3

// 게임 박스 크기
#define BOX_H_PX 30  // 가로
#define BOX_V_PX 20  // 세로

const char player_skin = 'O'; // 플레이어 스킨
// int curr_x = START_X_POS + 1;
// int curr_y = START_Y_POS + 1;

void gotoxy(int x, int y) {
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

/// @brief 게임이 진행될 사각 박스를 그립니다.
/// @param h_px 가로축 크기
/// @param v_px 세로축 크기
void draw_game_box() {
    int h_px = BOX_H_PX;
    int v_px = BOX_V_PX;
    /// 세로 그리기
    for (int i = 0; i < 2; i++) { 
        int curr_x = START_X_POS + (h_px - 1) * i;
        for (int j = 1; j < v_px; j++) {
            gotoxy(curr_x, j + START_Y_POS);
            std::cout << "|";
        }
    }

    /// 가로 그리기(윗쪽하고 아랫쪽)
    for (int i = 0; i < 2; i++) { 
        int curr_y = START_Y_POS + v_px * i;
        for (int j = 0; j < h_px; j++) {
            gotoxy(j + START_X_POS, curr_y);
            if (j == 0 || j == h_px - 1) {
                std::cout << "+";
                continue;        
            }
            std::cout << "-";
        }
    }
}

/// @brief 게임 조작법, 게임 종료법 키를 안내합니다.
void draw_guide_ui() {
    // 나중에 구현
}

/// @brief 게임 점수를 출력합니다.
void draw_score_ui() {

}

/// @brief 먹이를 배치
void draw_eating_item() {

}

/// @brief 키 입력에 따라 뱀이 이동합니다.
/// @param input left, right, up, down
void move_snake(int _input_key) {
    static int curr_x = START_X_POS + 1;
    static int curr_y = START_Y_POS + 1;

    gotoxy(++curr_x, curr_y);
    std::cout << player_skin;
}

int main(void) {
    system("cls");

    draw_game_box();

    // 대충 키 입력 감지하는 코드

    while(1) {
        if (kbhit()) {
            int input_key = getch();
            if (input_key == UP || 
                input_key == LEFT || 
                input_key == RIGHT || 
                input_key == DOWN) {
                move_snake(input_key);
            }
        }
    }
}