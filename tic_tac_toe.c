#include <stdio.h>
#include <stdlib.h>

void board(char *matrix){
    printf("%c | %c | %c \n", matrix[0], matrix[1], matrix[2]);
    printf("-   -   - \n");
    printf("%c | %c | %c \n", matrix[3], matrix[4], matrix[5]);
    printf("-   -   - \n");
    printf("%c | %c | %c \n", matrix[6], matrix[7], matrix[8]);
}


void player1(char *matrix) {
    int x, y;
    printf("Player1: ");
    scanf("%d%d", &x,&y);
    matrix[(x*3 + y)] = 'O';
}


void player2(char *matrix) {
    int x, y;
    printf("Player2: ");
    scanf("%d%d", &x,&y);
    matrix[(x*3 + y)] = 'X';
}


int check_board(char *matrix) {
    int i;
    for (i=0; i<3; i++){
        if (matrix[i*3+0] == 'O' && matrix[i*3+1] == 'O' && matrix[i*3+2] == 'O') { return 1;}
        if (matrix[i*3+0] == 'X' && matrix[i*3+1] == 'X' && matrix[i*3+2] == 'X') { return 2;}
    }

    for (i=0; i<3; i++){
        if (matrix[0*3+i] == 'O' && matrix[1*3+i] == 'O' && matrix[2*3+i] == 'O') { return 1;}
        if (matrix[0*3+i] == 'X' && matrix[1*3+i] == 'X' && matrix[2*3+i] == 'X') { return 2;}
    }

    if (matrix[0] == 'O' && matrix[4] == 'O' && matrix[8] == 'O') { return 1;}
    if (matrix[0] == 'X' && matrix[4] == 'X' && matrix[8] == 'X') { return 2;}

    if (matrix[2] == 'O' && matrix[4] == 'O' && matrix[6] == 'O') { return 1;}
    if (matrix[2] == 'O' && matrix[4] == 'O' && matrix[6] == 'O') { return 2;}

    return 0;
}

void game(char *matrix){
    int i, did_win;
    for (i=0; i < 5; i++) {
        board(matrix);
        player1(matrix);
        did_win = check_board(matrix);
        if (did_win == 1) {printf("Winner is Player1\n"); return;}
        if (did_win == 2) {printf("Winner is Player2\n"); return;}
        system("clear");

        if (i == 4) { continue;}

        board(matrix);
        player2(matrix);
        did_win = check_board(matrix);
        if (did_win == 1) {printf("Winner is Player1\n"); return;}
        if (did_win == 2) {printf("Winner is Player2\n"); return;}
        system("clear");

    }
    if (did_win == 0){ printf("match is draw\n");}
}



int main(void) {
    char matrix[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    game(&matrix[0][0]);

    return 0;
}
