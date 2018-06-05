//
//  tictactoe.c
//  TicTacToe
//
//  Created by Christina Wen on 2018-06-04.
//

#include "tictactoe.h"


// print_board(board) prints the game board in progress
// effects: prints out game
static void print_board(const char board[]){
    assert(board);
    printf("\n");
    for(int row = 0; row < 3; ++row){
        printf("|");
        for(int col = 0; col < 3; ++col){
            int pos = row*3 + col;
            printf("%c", board[pos]);
            printf("|");
        }
        printf("\n");
    }
}


//============ SOLVED FUNCTIONS ===============

// row_solved(board) determines if there is a row of three in board
// requires: board is valid

static int row_solved(const char board[]){
    assert(board);
    for(int row = 0; row <3; ++row){
        int pos = row*3 + 1;
        if(board[pos] == '*'){
            // do nothing
        } else if((board[pos] == board[pos-1])&&
                  (board[pos] == board[pos+1])){
            return 1;
        } else{
            // do nothing
        }
    }
    return 0;
}


// col_solved(board) determines if there is a column of three in the board
// requires: board is valid

static int col_solved(const char board[]){
    assert(board);
    for(int col = 3; col < 6; ++col){
        if(board[col] == '*'){
            // do nothing
        } else if ((board[col] == board[col-3])&&
                   (board[col]== board[col+3])){
            return 1;
        } else {
            // do nothing
        }
    }
    return 0;
}


// diag_solved(board) determines if there is a diagonal of three in the board
// requires: board is valid

static int diag_solved(const char board[]){
    assert(board);
    if(board[4] == '*'){
        return 0;
    } else if ((board[4] == board[0])&&
               (board[4] == board[8])){
        return 1;
    } else if((board[4] == board[2])&&
              (board[4] == board[6])){
        return 1;
    } else {
        return 0;
    }
}


// is_solved(board) determines if there is three in a row in the board
// requires: board is valid

static int is_solved(const char board[]){
    assert(board);
    return (diag_solved(board) || col_solved(board) || row_solved(board));
}


// is_full(board) determines if there are any more empty spaces in board
// requires: board is valid

static int is_full(const char board[]){
    assert(board);
    int count = 0;
    for(int i = 0; i < 9; ++i){
        if(board[i]=='*'){
            ++count;
        }
    }
    return (count == 0);
}

//============ INSERT FUNCTION ===============

// insert(player, pos, board) inserts player's mark in
//      the pos-th square of board
// effects: changes board
// returns: 0 if board is successfully changed
//          1 if the insert was unsuccessful
// requires: board is valid
//           player is either 0 or 1
//           0 <= pos < 9

static int insert(int player, int pos, char board[]){
    assert(board);
    assert((player == 0)||(player == 1));
    assert((pos >= 0)&&(pos < 9));
    if(board[pos] != '*'){
        return 1;
    } else if (player == 0){
        board[pos] = 'X';
        return 0;
    } else{
        board[pos] = 'O';
        return 0;
    }
}

//============ PLAY_GAME FUNCTION ===============

// see tictactoe.h for details

void play_game(){
    // variables
    int turn = 0; // determines if it's player 1's turn or player 2's turn
    int pos = 0; // user's inserting position
    int retval = 0; // return value of scanf
    char cont; // y or n
    
    // Introduction
    printf("Welcome to 'Tic Tac Toe' in C!\n");
    printf("Player 1 is X.\nPlayer 2 is O.\n");
    printf("Players will take turns placing their marks on the board. ");
    printf("When prompted, enter the position you wish to mark. ");
    printf("The positions will be the following: \n");
    printf("|1|2|3|\n|4|5|6|\n|7|8|9|\n");
    printf("First player to get three in a row wins. Good luck!\n");
    while(1){ // "Press y to start" prompt
        char cont;
        printf("\nPress y to start.");
        scanf(" %c", &cont);
        if(cont == 'y'){
            break;
        }
    }
    
    // Starting game
    while(1){
        
        // Setting up the board
        char game[9];
        for(int i = 0; i<9; ++i){
            game[i] = '*';
        }
        
        print_board(game);
        
        while(1){ // Players alternate
            printf("Player %d, your turn:", turn+1);
            retval = scanf("%d", &pos);
            if((retval == 1) && (pos > 0) && (pos <= 9) &&
               (game[pos-1] == '*')){
                insert(turn, pos-1, game);
                print_board(game);
            } else {
                printf("Invalid position. Please try again. \n");
                continue;
            }
            
            if(is_full(game)||is_solved(game)){
                break;
            }
            
            ++turn;
            turn %= 2;
        }
        
        // Game finished
        if (is_solved(game)){
            printf("Congratulations Player %d, you win! \n", turn + 1);
        } else {
            printf("No more moves. Game over!\n");
        }
        while(1){ // "New game?" prompt
            printf("New game?(Press 'y' for yes and 'n' for no.)\n");
            scanf(" %c", &cont);
            if((cont == 'n')||(cont == 'y')){
                break;
            }
        }
        if(cont == 'n'){ // exiting game
            break;
        }
    }
}

