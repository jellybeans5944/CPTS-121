#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()

// Andys Code from class
#define GAME_RULES 1
#define Play_Game 2
#define EXIT 3

#define TRUE 1
#define FALSE 0 

// Function Declarations
void game_menu(void);
int menu_select(void);
void print_game_rules(void);
void roll_die(int dice_roll[]);
void display_roll(int dice_roll[]);
char decision_roll();
void decision_keep_dice(int kept_dice[]);
void print_specific_score_option(int score_number);
void print_score_option(int player_scorecard[]);
int check_card(int playerScoreCard[], int option);
void get_score(int option, int dice_roll[5], int player_score_card[]);
int isThreeofAkind(int frequency_die[]);
int isFourofAkind(int frequency_die[]);
int is_FullHouse(int frequency_die[]);
int isSmallStriaght(int frequency_die[]);
int isLargeStriaght(int frequency_die[]);
int isYahtzee(int frequency_die[]);

#pragma once
