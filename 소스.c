
//3X3 퍼즐 게임
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80
#define XX 23

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
void title() {
    //프로그램창의 제목
    system("title 퍼즐게임 PUZZLE GAME! 1.0.0");
}





void name() {
    gotoxy(20, 2); printf("3x3        퍼즐게임\n");
}

void yeah() {
    gotoxy(XX, 5); printf("1. 게임 시작");
    gotoxy(XX, 6); printf("2. 게임 방법");
    gotoxy(XX, 7); printf("3. 끝내기");
    gotoxy(16, 9); printf("입력하세요 : ");
}

void explain() {

    gotoxy(5, 3); printf("3x3퍼즐게임은 그림을 맞추는 것입니다.");
    system("pause > null");
    gotoxy(5, 4); printf("그림의 순서에 따라 정리해보세요");
    system("pause > null");
    gotoxy(5, 5); printf("시간을 측정하고 있으니 최고의 기록에 도전해보세요");
    system("pause > null");

}

void restart() {
    printf("\n\n");
    printf("재시작하고싶나요?\n");
    printf("1. 네\n");
    printf("2. 아니오\n");
    printf("입력하세요 : ");
}


int get_directionkey()
{
    int key;
    key = _getch();
    if (key == 224)
    {
        return _getch(); 
    }
    return 0;   
}
void print_puzzle(int puzzle[][3])
{
    int r, c;
    system("cls");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            if (puzzle[r][c])
            {
                printf("%3d", puzzle[r][c]);
            }
            else
            {
                printf("   ");
            }

        }
        printf("\n");
    }
}
int is_ending(int puzzle[][3])
{
    int r, c;

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            if (puzzle[r][c] != r * 3 + c + 1)
            {
                return (r == 2) && (c == 2);
            }
        }
    }
    return 0;
}
int main()
{
    int puzzle[3][3] = { { 1,2,3 },{ 8,7,4 },{ 6,5,0 } };
    int row = 2;
    int col = 2;
    int key = 0;
    clock_t start1, end1;
    float res1;

    title();
a:
    system("cls");
    name();
    yeah();
    int select;
    gotoxy(29, 9); scanf_s("%d", &select);

    if (select == 1)
    {
        system("cls");
        gotoxy(9, 6); printf("생성중입니다...");
        Sleep(3000);
        system("cls");
        printf("게임시작\n");
        is_ending(puzzle);
    }
    else if (select == 2)
    {
        system("cls");
        explain();
        goto a;
    }
    else if (select == 3)
    {
        return 0;
    }


    start1 = clock();
    while (!is_ending(puzzle))
    {
        print_puzzle(puzzle);
        key = get_directionkey();

        switch (key)
        {
        case RIGHT:
            if (col > 0)
            {
                puzzle[row][col] = puzzle[row][col - 1];
                puzzle[row][col - 1] = 0;
                col--;
            }

            break;
        case LEFT:
            if (col < 3 - 1)
            {
                puzzle[row][col] = puzzle[row][col + 1];
                puzzle[row][col + 1] = 0;
                col++;
            }
            break;
        case UP:
            if (row < 3 - 1)
            {
                puzzle[row][col] = puzzle[row + 1][col];
                puzzle[row + 1][col] = 0;
                row++;
            }
            break;
        case DOWN:
            if (row > 0)
            {
                puzzle[row][col] = puzzle[row - 1][col];
                puzzle[row - 1][col] = 0;
                row--;
            }
            break;
        }
    }
    end1 = clock();
    res1 = (float)(end1 - start1) / CLOCKS_PER_SEC;

    printf("YOU DONE!\n");
    printf("게임하는데 소요된 시간 : %.3f\n", res1);

b:
    restart();
    int select2;
    scanf_s("%d", &select2);

    if (select == 1)
    {
        goto a;
    }
    else if (select == 2)
    {
        printf("OK, BYE!");
        return 0;
    }
    
    return 0;
}
