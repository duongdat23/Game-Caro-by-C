#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkWin(char array[3][3]);
void input(char array[3][3], int object);
void display(char a[3][3]);

int main()
{
    printf("\tGAME TICTACTOE C \n");
    printf("PLAYER 1 - [X] \t PLAYER 2 = [O]\n\n");
    int i = 0;
    char array[3][3];
    memset(array, 32, 9);
    display(array);
    while (i < 9)
    {
        input(array, i % 2 + 1);
        display(array);
        if (checkWin(array) == true)
        {
            printf("\nPlayer %d WIN\n", i % 2 + 1);
            break;
        }

        i++;
    }

    return 0;
}
void display(char array[3][3])
{
    printf("----------------------\n");
    printf("|   %c  |   %c  |   %c  |\n", array[0][0], array[0][1], array[0][2]);
    printf("----------------------\n");
    printf("|   %c  |   %c  |   %c  |\n", array[1][0], array[1][1], array[1][2]);
    printf("----------------------\n");
    printf("|   %c  |   %c  |   %c  |\n", array[2][0], array[2][1], array[2][2]);
    printf("----------------------\n");
}
void input(char array[3][3], int object)
{

    bool check_position = 0;

    // check_position = 1 : đã chọn
    while (check_position != 1)
    {

        printf("Player %d, choose position: ", object);
        int index;
        scanf("%d", &index);
        index--;
        int temp_i = index / 3;
        int temp_j = index % 3;
        if (array[temp_i][temp_j] != ' ')
        {
            printf("\n--position have been choose---\n");
            printf("Let choose again ! \n");
            check_position = 0;
        }
        else
        {
            if (object == 1)
                array[temp_i][temp_j] = 'x';
            else
                array[temp_i][temp_j] = 'o';
            check_position = 1;
        }
    }
}

bool checkWin(char array[3][3])
{
    if (array[0][0] == array[1][1] && array[0][0] == array[2][2] && (array[0][0] == 'x' || array[0][0] == 'o'))
    {
        return true;
    }
    // check row
    for (int i = 0; i < 2; i++)
    {
        if (array[i][0] == array[i][1] && array[i][0] == array[i][2] && (array[i][0] == 'x' || array[i][0] == 'o'))
        {
            return true;
        }
    }
    // check colum
    for (int i = 0; i < 2; i++)
    {
        if (array[0][i] == array[1][i] && array[0][i] == array[2][i] && (array[i][2] == 'x' || array[i][2] == 'o'))
        {
            return true;
        }
    }
    return false;
}