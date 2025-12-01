#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void screen1() {
    printf("\n••••••••••••••••••••••••••\n•                       •\n•    WELCOME TO THE     •\n•       ARCADE          •\n•                       •\n•       LOADING...      •\n•                       •\n•                       •\n•••••••••••••••••••••••••");
    return ;
}
void screen2(){
    printf("\n••••••••••••••••••••••••••\n•     Select Option      •\n•   1. Snake and Fruit   •\n•   2. Tic Tac Toe       •\n•   3. Minesweeper       •\n•   4. Exit              •\n•                        •\n•                        •\n•••••••••••••••••••••••••\n Enter a number :");
    return ;
}
    
void screen3(){
  printf("\n••••••••••••••••••••••••••\n•                       •\n•                       •\n•        THE END        •\n•                       •\n•                       •\n•                       •\n•                       •\n•••••••••••••••••••••••••\n\n");
  return ;
}
//------------------------------------------------------------------------------------------------------------------------------------------------//
int x[100], y[100];  
int xf, yf, score = 0;
char s1[12][28] = {
    "***************************",
    "*                         *",
    "*                         *",
    "*                         *",
    "*                         *",
    "*                         *",
    "*                         *",
    "*                         *",
    "*                         *",
    "*                         *",
    "*                         *",
    "***************************"
};


clock_t T; // Time of clock
char moveA , prev_move='q'; // Global variable to store the previous input given by user

void stage1() {
    system("cls");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 27; j++) {
        printf("%c", s1[i][j]);
        }
        printf("\n");
    }
}

int slcheck() {
    if (x[0] <= 0 || x[0] >= 11 || y[0] <= 0 || y[0] >= 26) {
        return 0; 
    }
    for(int i=1 ; i<=score ; i++){
        if(x[i]==x[0] && y[i]==y[0]){
       return 0 ;}
    }
    return 1;
}


void fruitlocation(){
    xf = rand()%10 + 1; 
    yf = rand()%25 + 1; 
    for (int i = 0; i <= score; i++) {
        if (x[i] == xf && y[i] == yf) {
            fruitlocation();
            return;
        }
    }
    
    s1[xf][yf] = 'F';
}

void snakemovement() {
    s1[x[score]][y[score]] = ' ';

    for (int i = score; i > 0; i--) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
}

void snake_conti_move() {
    T = clock();
    while(clock() - T < 250) {  
        if (GetAsyncKeyState('W') & 0x8000) { 
            moveA = 'w';
            break;
        }
        if (GetAsyncKeyState('S') & 0x8000) { 
            moveA = 's';
            break;
        }
        if (GetAsyncKeyState('A') & 0x8000) { 
            moveA = 'a';
            break;
        }
        if (GetAsyncKeyState('D') & 0x8000) { 
            moveA = 'd';
            break;
        }
    }
}



void level1() {
    fruitlocation();
    
    while (1) {
        stage1();
        printf("Score: %d\n", score);

        
        snake_conti_move();
        char move;
    
        move = moveA;
        if(move=='w' && prev_move=='s')  move=prev_move ;
        if(move=='s' && prev_move=='w')  move=prev_move ;
        if(move=='a' && prev_move=='d')  move=prev_move ;
        if(move=='d' && prev_move=='a')  move=prev_move ;
        if(move=='s'||move=='w') Sleep(100);
        snakemovement();
        prev_move = move ;
        if (move == 'w') x[0]--;
        if (move == 's') x[0]++;
        if (move == 'a') y[0]--;
        if (move == 'd') y[0]++;

        
        if (slcheck() == 0) {
            return;
        }

        
        if (x[0] == xf && y[0] == yf) {
            score++;  
            fruitlocation();  
        }

        
        for (int i = 0; i <= score; i++) {
            s1[x[i]][y[i]] = 'o';
        }if (move == 'w') {s1[x[0]][y[0]] = '^';}
        if (move == 's') {s1[x[0]][y[0]] = 'v';}
        if (move == 'a') {s1[x[0]][y[0]] = '<';}
        if (move == 'd') {s1[x[0]][y[0]] = '>';}
        Sleep(100);
    }
}

int snake_game() {
    srand(time(0));

    x[0] = 1, y[0] = 1;
    s1[x[0]][y[0]] = '>';
    level1();
    
    screen3();
    Sleep(2000);
    system("cls");

    s1[xf][yf]=' ';
    moveA=' ';
    for(int i=1 ; i<=score ; i++){
        s1[x[i]][y[i]]=' ';
    }
    s1[x[0]][y[0]]='*';
    score = 0 ;
   
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------//
int row, column ;
char tt[5][6] = {
    " | | ", 
    "-----", 
    " | | ", 
    "-----", 
    " | | "
};

void board(){
    for(int a=0 ; a<5 ; a++){
        for(int b=0 ; b<5 ;b++){
            printf("%c",tt[a][b]);
        }
        printf ("\n");
    }
}
int winconditionp(){
    if(tt[0][0]=='O'&&tt[0][2]=='O'&&tt[0][4]=='O') return 1 ;
    if(tt[2][0]=='O'&&tt[2][2]=='O'&&tt[2][4]=='O') return 1 ;
    if(tt[4][0]=='O'&&tt[4][2]=='O'&&tt[4][4]=='O') return 1 ;
  
    if(tt[0][0]=='O'&&tt[2][0]=='O'&&tt[4][0]=='O') return 1 ;
    if(tt[0][2]=='O'&&tt[2][2]=='O'&&tt[4][2]=='O') return 1 ;
    if(tt[0][4]=='O'&&tt[2][4]=='O'&&tt[4][4]=='O') return 1 ;
   
    if(tt[0][0]=='O'&&tt[2][2]=='O'&&tt[4][4]=='O') return 1 ;
    if(tt[0][4]=='O'&&tt[2][2]=='O'&&tt[4][0]=='O') return 1 ;
    
    return 0 ;
}
int winconditionb(){
    if(tt[0][0]=='X'&&tt[0][2]=='X'&&tt[0][4]=='X') return 1 ;
    if(tt[2][0]=='X'&&tt[2][2]=='X'&&tt[2][4]=='X') return 1 ;
    if(tt[4][0]=='X'&&tt[4][2]=='X'&&tt[4][4]=='X') return 1 ;
  
    if(tt[0][0]=='X'&&tt[2][0]=='X'&&tt[4][0]=='X') return 1 ;
    if(tt[0][2]=='X'&&tt[2][2]=='X'&&tt[4][2]=='X') return 1 ;
    if(tt[0][4]=='X'&&tt[2][4]=='X'&&tt[4][4]=='X') return 1 ;
   
    if(tt[0][0]=='X'&&tt[2][2]=='X'&&tt[4][4]=='X') return 1 ;
    if(tt[0][4]=='X'&&tt[2][2]=='X'&&tt[4][0]=='X') return 1 ;
    
    return 0 ;}
void randommove(){
    int x , y ;
    x = 2*(rand()%3) ;
    y = 2*(rand()%3) ;
    if(tt[x][y]==' '){
        tt[x][y]='X';
    }
    else{
        randommove();
    }
    return ;
}
void botmove(){
   Sleep(2000); // winning ke liye x ka movement 
    int cl ;
    if(tt[0][0]==' '){   // 0 0
        tt[0][0]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[0][0]=' ';
    }
    if(tt[0][2]==' '){   // 0 2
        tt[0][2]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[0][2]=' ';
    }
    if(tt[0][4]==' '){   // 0 4
        tt[0][4]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[0][4]=' ';
    }
    if(tt[2][0]==' '){    // 2 0
        tt[2][0]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[2][0]=' ';
    }
    if(tt[2][2]==' '){   // 2 2
        tt[2][2]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[2][2]=' ';
    }
    if(tt[2][4]==' '){  // 2 4
        tt[2][4]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[2][4]=' ';
    }
    if(tt[4][0]==' '){  // 4 0
        tt[4][0]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[4][0]=' ';
    }
    if(tt[4][2]==' '){   // 4 2
        tt[4][2]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[4][2]=' ';
    }
    if(tt[4][4]==' '){    // 4 4
        tt[4][4]='X';
        cl=winconditionb();
        if(cl==1) return ;
        tt[4][4]=' ';
    }
    
    // lossing ke liye x ka defence movement 
    
    if(tt[0][0]==' '){   // 0 0 
        tt[0][0]='O';
        cl=winconditionp();
        if(cl==1){
            tt[0][0]='X';
            return ;}
        tt[0][0]=' ';
    }
    if(tt[0][2]==' '){   // 0 2
        tt[0][2]='O';
        cl=winconditionp();
        if(cl==1){ 
            tt[0][2]='X';
            return ;}
        tt[0][2]=' ';
    }
    if(tt[0][4]==' '){   // 0 4
        tt[0][4]='O';
        cl=winconditionp();
        if(cl==1){
            tt[0][4]='X';
            return ;}
        tt[0][4]=' ';
    }
    if(tt[2][0]==' '){    // 2 0
        tt[2][0]='O';
        cl=winconditionp();
        if(cl==1){ 
            tt[2][0]='X';
            return ;}
        tt[2][0]=' ';
    }
    if(tt[2][2]==' '){   // 2 2
        tt[2][2]='O';
        cl=winconditionp();
        if(cl==1){ 
            tt[2][2]='X';
            return ;}
        tt[2][2]=' ';
    }
    if(tt[2][4]==' '){  // 2 4
        tt[2][4]='O';
        cl=winconditionp();
        if(cl==1){ 
            tt[2][4]='X';
            return ;}
        tt[2][4]=' ';
    }
    if(tt[4][0]==' '){  // 4 0
        tt[4][0]='O';
        cl=winconditionp();
        if(cl==1){ 
            tt[4][0]='X';
            return ;}
        tt[4][0]=' ';
    }
    if(tt[4][2]==' '){   // 4 2
        tt[4][2]='O';
        cl=winconditionp();
        if(cl==1){ 
            tt[4][2]='X';
            return ;}
        tt[4][2]=' ';
    }
    if(tt[4][4]==' '){    // 4 4
        tt[4][4]='O';
        cl=winconditionp();
        if(cl==1){ 
            tt[4][4]='X';
            return ;}
        tt[4][4]=' ';
    }
    
    // Random movement
    randommove();
    return  ;
    
}
void ttl(){
    int moves = 0;
    
while (1) {
    board();
    printf("\nUser row and column: ");
    scanf("%d %d", &row, &column);
    if(row<=0 || row>3 ||column<=0 || column>3){
        system("cls");
        printf("\nInvalid input, try again\n");
        continue; 
    }
    if (tt[2*(row-1)][2*(column-1)]=='O' || tt[2*(row-1)][2*(column-1)]=='X') {
        system("cls");
        printf("\nInvalid input, try again\n");
        continue;
    }

    tt[2*(row-1)][2*(column-1)] = 'O';
    moves++;
    if (winconditionp()) {
        board();
        printf("\nPlayer Wins!\n");
        break;
    }
    system("cls");
    printf("\nPlayer Move\n");
    board();

    if (moves >= 9) {
        board();
        printf("\nIt's a Draw!\n");
        break;
    }
    printf("\nBot Move\n");
    botmove();
    moves++;
    
    if (winconditionb()) {
        board();
        printf("\nBot Wins!\n");
        break;
    }

   
}}

int tic_tac_toe(){
    tt[0][0]=' ', tt[0][2]=' ', tt[0][4]=' ';
    tt[2][0]=' ', tt[2][2]=' ', tt[2][4]=' ';
    tt[4][0]=' ', tt[4][2]=' ', tt[4][4]=' ';
    ttl();
    Sleep(1000);
    system("cls");
    return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------//
char tt_board[10][10];
int mx[10], my[10];  // Mines' x and y positions
int flag = 0 ;
void tt_boardp() {
    printf("\nCurrent Board:\n");
    printf("  ");
    for (int j = 0; j < 10; j++)
        printf("%d ", j);
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        for (int j = 0; j < 10; j++) {
            printf("%c ", tt_board[i][j]);
        }
        printf("\n");
    }
    printf("flag count :%d",flag);
}

int is_mine(int x, int y) {
    for (int i = 0; i < 10; i++) {
        if (mx[i] == x && my[i] == y)
            return 1;
    }
    return 0;
}

void mine_setup(int mines) {
    while (mines < 10) {
        int x = rand() % 10;
        int y = rand() % 10;

        int alreadyPlaced = 0;
        for (int i = 0; i < mines; i++) {
            if (mx[i] == x && my[i] == y) {
                alreadyPlaced = 1;
                break;
            }
        }

        if (!alreadyPlaced) {
            mx[mines] = x;
            my[mines] = y;
            mines++;
        }
    }
}

int count_adjacent_mines(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && is_mine(nx, ny)) {
                count++;
            }
        }
    }
    return count;
}

int minesweeper() {
    
    // Initialize board
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tt_board[i][j] = '*';

    mine_setup(0);
    tt_boardp();
    
    while (1) {
        char rf;
        int rx, ry;
        printf("\nEnter move R/F/B and x , y: ");
        scanf(" %c", &rf);
        if(rf=='b') return 0 ;
    
        scanf("%d %d", &rx, &ry);

        

        if (rx < 0 || rx >= 10 || ry < 0 || ry >= 10) {
            printf("Invalid coordinates\n");
            continue;
        }

        if (rf == 'R' || rf == 'r') {
            if (is_mine(rx, ry)) {
                printf( "You hit a mine. Game Over.\n");
                tt_board[rx][ry] = 'X';
                tt_boardp();
                break;
            } else {
                int mines_around = count_adjacent_mines(rx, ry);
                tt_board[rx][ry] = '0' + mines_around;
            }
        } else if ( (rf == 'F' || rf == 'f') && tt_board[rx][ry] =='F' ) {
            tt_board[rx][ry] = '*';
            flag -- ;
        }else if (( rf == 'F' || rf == 'f' ) && flag<10) {
            tt_board[rx][ry] = 'F';
            flag++ ;
        } else {
            printf("Invalid option\n");
            continue;
        }

        if(flag==10){
            int i ;
            for(i=0 ; i<10 ; i++){
                if(tt_board[mx[i]][my[i]]!='F') break  ;
            }
          if(i==10) { printf("\nPlayer Win\n");
            return 0 ;}
        }

        tt_boardp();
    }
    flag=0 ;
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------//


int main() {
    int choice;
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    screen1();
    Sleep(2000);
    system("cls");
    while (1) { 
        screen2();
        scanf("%d", &choice);

        if (choice == 1) {
            snake_game();
        } else if (choice == 2) {
            tic_tac_toe();
        } else if (choice == 3) {
            minesweeper();
        } else if (choice == 4) {
            break;
        } else {
            continue;
        }
        
        Sleep(2000);
    }
    return 0;
}