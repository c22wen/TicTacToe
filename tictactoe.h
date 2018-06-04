//
//  tictactoe.h
//  TicTacToe
//
//  Created by Christina Wen on 2018-06-04.
//

#ifndef tictactoe_h
#define tictactoe_h

#include <stdio.h>
#include <assert.h>

#endif /* tictactoe_h */

//============ PRINT FUNCTION ===============
// see tictactoe.c for details
void print_board(const char board[]);

//============ SOLVED FUNCTIONS ===============
// see tictactoe.c for details
int row_solved(const char board[]);

// see tictactoe.c for details
int col_solved(const char board[]);

// see tictactoe.c for details
int diag_solved(const char board[]);

// see tictactoe.c for details
int is_solved(const char board[]);

// see tictactoe.c for details
int is_full(const char board[]);

//============ INSERT FUNCTION ===============
/// see tictactoe.c for details
int insert(int player, int pos, char board[]);

//============ PLAY_GAME FUNCTION ===============
// see tictactoe.c for details
void play_game(void);
