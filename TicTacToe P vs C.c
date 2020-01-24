#include <stdio.h>
#include <stdlib.h>

int count = 0;
char matrix[3][3];

/** Initialize the matrix. */
void init_matrix()
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            matrix[i][j] = ' ';
}

/** Display the matrix on the screen. */
void disp_matrix()
{
    printf("\n");
    printf(" 1   2   3 \n");
    printf("============\n");
    printf(" %c | %c | %c |1",matrix[0][0], matrix[0][1], matrix [0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c |2",matrix[1][0], matrix[1][1], matrix [1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c |3",matrix[2][0], matrix[2][1], matrix [2][2]);

    printf("\n\n");
}

/** Get a player's move */
void get_player_move()
{
    int x, y;
    printf("I dare you to enter some coordinates: ");
    scanf("%d%*c%d", &x, &y);
    x--;
    y--;

    if(matrix[x][y] != ' ')
    {
        printf("You can't do that, hooman.Try again, if you dare.\n");
        get_player_move();
    }
    else matrix[x][y] = 'X';
}

/** Get computer move */
void get_computer_move()
{
    int m, n;
    m = rand() % 3;
    n = rand() % 3;
    while(matrix[m][n] == 'X' || matrix[m][n] == 'O')
    {
        m = rand() % 3;
        n = rand() % 3;
    }
    count ++;

    if(count == 9)
    {
        printf("Draw...you got lucky.\n");
        exit(0);
    }
    else
        matrix[m][n]  = 'O';
}

/** See if there is a winner */
char check()
{
    int i;
    for(i=0; i<3; i++) /** check rows */
        if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2])
            return matrix[i][0];

    for(i=0; i<3; i++) /** check columns */
        if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
            return matrix[0][i];
/** test diagonals */

    if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
        return matrix[0][0];

    if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
        return matrix[0][2];

    return ' ';
}

int main()
{
    char fini = ' ';
    printf("It is I, the evil computer.\n\n");
    printf("You will be playing Tic Tac Toe against me, myself and I.\n\n");
    printf("Please proceed, hooman.\n");
    printf("The first coordinate is the line and the second one is the row.\n");
    init_matrix();

    do {
        disp_matrix();
        get_player_move();
        fini = check(); /** see if winner */

        if(fini != ' ')
            break; /** winner!*/

        get_computer_move();
        fini = check(); /* see if winner */
        } while(fini == ' ');

    disp_matrix(); /** show final positions */
    if(fini == 'X')
        printf("You w...you won.Cause I let you win.\n");
    else
        printf("I won.Pff.Obviously.\n");

    return 0;
}


