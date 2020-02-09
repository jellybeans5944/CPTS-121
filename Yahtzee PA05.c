/*
Name: Anelica Heneghan
Date: 10/23/19
Descrption: This game will contruct yahtzee. The rules are as follows:
*	The scorecard used for Yahtzee is composed of two sections.A upper sectionand a lower section.
*	A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.
*	The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.
*	If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12
*	Once a player has chosen to score a box,\n");
*	it may not be changed and the combination is no longer in play for future rounds.
*	If the sum of the scores in the upper section is greater than or equal to 63,
*	then 35 more points are added to the players overall score as a bonus.
*	The lower section contains a number of poker like combinations.
*/

#include "Yahtzee.h"

int main(void)
{
	srand(time(NULL));

// Variable Declarations 
	int option = 0, roll_num = 0, user_roll = 0, score1 = 0, score2 = 0, rounds = 0, score = 0, player_scorecard[13];
	int player_scoreoptions[13] = { 0 }, player1_scorecard[13] = { 0 }, player2_scorecard[13] = { 0 };
	int dice_roll[5] = { 0 };
	char decision = '\0';
	int userChoice = 0;
	
// Play Yahtzee
	do{
		option = menu_select();
		switch (option) {
		case GAME_RULES: print_game_rules(); //print game rules 
			break;
		case Play_Game:
			while (rounds < 13) {
				
				printf("Player 1s turn...\n");
				roll_die(dice_roll);
				display_roll(dice_roll);
				decision = 'y';
				while (decision == 'y' && user_roll < 2) // rerolls
				{
					decision = decision_roll();
					if(decision == 'y')
					{
						decision_keep_dice(dice_roll);
					}
					user_roll++;
					display_roll(dice_roll);
				}
				
				do {
					print_score_option(player1_scorecard);
					printf("Which score slot which you like to use (1 - 13)\n...");
					scanf("%d", &userChoice);
				} while (userChoice < 1 || userChoice > 13);
				get_score(userChoice, dice_roll, player1_scorecard);
				score1 = calc_score(score, player1_scorecard); // use calcualte_score 
				printf("Total score: %d \n", score1);
				user_roll = 0;
				
				// Player 2 turn 
				printf("Player 2s turn...\n");
				roll_die(dice_roll);
				display_roll(dice_roll);
				decision = 'y';
				while (decision == 'y' &&user_roll < 2) //rerolls
				{
					decision = decision_roll();
					if (decision == 'y')
					{
						decision_keep_dice(dice_roll);
					}
					user_roll++;
					display_roll(dice_roll);
				}
				do {
					print_score_option(player2_scorecard);
					printf("Which score slot which you like to use (1 - 13)\n...");
					scanf("%d", &userChoice);
				} while (userChoice < 1 || userChoice > 13);
				get_score(userChoice, dice_roll, player2_scorecard);
				score2 = calc_score(score2, player2_scorecard);
				printf("Total score: %d \n", score2);
				user_roll = 0;
				rounds++;
			}
			break;
		case EXIT: 
			break;
		default: 
			printf("wrong Choice");
			break;
		
		}

	
	} while (option != EXIT);

 return 0; 
}