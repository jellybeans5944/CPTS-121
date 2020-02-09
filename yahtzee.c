#include "Yahtzee.h"

//************************************************************************************************************************
// Prints the game rules
//************************************************************************************************************************
void game_menu(void)
{
	printf("1. Print game rules \n");
	printf("2. Start a game of Yahtzee \n");
	printf("3. Exit \n");
}

//************************************************************************************************************************
// Gets an option input from the user and stores that vlaue then returns it. 
//************************************************************************************************************************

int menu_select(void) // andys code from class
{
	int option = 0;

	// Below is an input-validation loop.
	do
	{
		game_menu();
		scanf("%d", &option);
		system("cls");
		if (option < GAME_RULES || option > EXIT)
			printf("Wrong Choice \n");
	} while (option < GAME_RULES || option > EXIT);

	return option;
}

//************************************************************************************************************************
// Prints the rules of the game
//************************************************************************************************************************

void print_game_rules(void) // Prints game rules
{
	printf("\n*The scorecard used for Yahtzee is composed of two sections. A upper sectionand a lower section. \n");
	printf("*A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("*The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("*If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("*Once a player has chosen to score a box,\n");
	printf("*it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("*If the sum of the scores in the upper section is greater than or equal to 63,\n");
	printf("*then 35 more points are added to the players overall score as a bonus.\n");
	printf("*The lower section contains a number of poker like combinations.\n");

}

//************************************************************************************************************************
// Rolls the dice 
//************************************************************************************************************************

void roll_die(int dice_roll[])
{
	for (int i = 0; i < 5; i++)
	{
		dice_roll[i] = rand() % 6 + 1;
	}		
}

//************************************************************************************************************************
// Displays the dice roll
//************************************************************************************************************************

void display_roll(int dice_roll[])
{

	for (int i = 0; i < 5; i++)
	{
		printf("Roll Value: %d \n", dice_roll[i]);
	}
}
//************************************************************************************************************************
// Calcualte frequency array 
//************************************************************************************************************************
void frequency(int dice_roll[], int frequency_die[])
{
	for (int i = 0; i < 5; i++)
	{
		frequency_die[dice_roll[i]]++;
	}

}

//************************************************************************************************************************
// Stores the character for the decision of the user, if they want ti keep rolling. 
//************************************************************************************************************************

char decision_roll()
{
	char yesorno = '\0';
	printf("Would you like to keep rolling? \n");
	scanf(" %c", &yesorno); 
	return yesorno;
}

//************************************************************************************************************************
// Stores which dice the user keeps and does not. 
//************************************************************************************************************************


void decision_keep_dice(int dice_roll[5])
{	
	char yesorno = '\0';
	for (int i = 0; i < 5; i++)
	{
		printf("Which die do you want to reroll (y/n)? die: %d ? \n", dice_roll[i]);
		do {
			scanf(" %c", &yesorno);
		} while (yesorno != 'y' && yesorno != 'n');
			
		
		if (yesorno == 'y')
		{
			dice_roll[i] = rand() % 6 + 1;
		}
	}
}
//************************************************************************************************************************
//  checks scorecard
//************************************************************************************************************************
int check_card(int playerScoreCard[], int option) {
	int used = 0;
	if (playerScoreCard[option] != 0) {
		used = 1;
	}
	return used;
	}
//************************************************************************************************************************
//  Score Functions
//************************************************************************************************************************
int isThreeofAkind(int frequency_die[])
{
	for (int i = 0; i < 7; i++)
	{
		if (frequency_die[i] >= 3)
		{
			return 1;
		}
	}

	return 0;
}
int isFourofAkind(int frequency_die[])
{
	for (int i = 0; i < 7; i++)
	{
		if (frequency_die[i] >= 4)
		{
			return 1;
		}
	}

	return 0;
}
int is_FullHouse(int frequency_die[])
{
	int found2 = 0;
	int found3 = 0;
	for (int i = 0; i < 7; i++)
	{
		int val = frequency_die[i];
		if (val == 2)
		{
			found2 = 1;

		}
		if (val == 3)
		{

			found3 = 1;

		}
	}
	if (found2 && found3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isSmallStriaght(int frequency_die[])
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		int val = frequency_die[i];
		if (val != 0)
		{
			count++;

		}
		else
		{
			count = 0;
		}

		if (count == 4)
		{
			return 1;

		}

	}
	return 0;
}

int isLargeStriaght(int frequency_die[])
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		int val = frequency_die[i];
		if (val != 0)
		{
			count++;

		}
		else
		{
			count = 0;
		}

		if (count == 5)
		{
			return 1;

		}

	}
	return 0;
}

int isYahtzee(int frequency_die[])
{
	for (int i = 0; i < 7; i++)
	{
		if (frequency_die[i] == 5)
		{
			return 1;

		}

	}

	return 0;
}
//************************************************************************************************************************
//  Gets the score of the player 
//************************************************************************************************************************

void get_score(int option, int dice_roll[5], int player_score_card[])
{
	int frequency_roll[7] = { 0 };
	frequency(dice_roll,frequency_roll);
	
	int score = 0;
	if (option <= 6)
	{
		for (int i = 0; i < 5; i++)
			if (dice_roll[i] == option)
			{
				score = score + option;
			}

		player_score_card[option - 1] = score;

	}


	else if (option == 7) // Three Of a Kind 
	{	
		
		if (check_card(player_score_card, option - 1) == 0)// do this for the rest of the options 
		{ 
			if (isThreeofAkind(frequency_roll) == 1)
			{
				player_score_card[option - 1] = sum_dice_value(dice_roll);
			}
			else
			{
				printf("Wrong choice, please select a valid option.");
			}

		}
	}
	else if(option == 8)  // Four Of a Kind 
	{	
		if (check_card(player_score_card, option - 1) == 0)
		{
			if (isFourofAkind(frequency_roll) == 1)
			{
				player_score_card[option - 1] = sum_dice_value(dice_roll);
			}
			else
			{
				printf("Wrong choice, please select a valid option.");
			}

		}
		
	}

	else if (option == 9) // Full House
	{	
		if (check_card(player_score_card, option - 1) == 0)
		{
			if (is_FullHouse(frequency_roll) == 1)
			{
				player_score_card[option - 1] = 25; // score for full house 
			}
			else
			{
				printf("Wrong choice, please select a valid option.");
			}
		}
	}
	else if (option == 10) // small Striaght
	{
		if (check_card(player_score_card, option - 1) == 0)
		{
			if (isSmallStriaght(frequency_roll) == 1)
			{
				player_score_card[option - 1] = 30; // score = 30 for small straight
			}
			else
			{
				printf("Wrong choice, please select a valid option.");
			}
		}
	
	}
	else if (option == 11) // Large straight 
	{
		if (check_card(player_score_card, option - 1) == 0)
		{
			if (isLargeStriaght(frequency_roll) == 1)
			{
				player_score_card[option - 1] = 40; // 40 = score for large straight 
			}
			else
			{
				printf("Wrong choice, please select a valid option.");
			}
		}
			
		

	}
	else if(option == 12)  // Yahtzee
	{
		if (check_card(player_score_card, option - 1) == 0)
		{
			if (isYahtzee(frequency_roll) == 1)
			{
				player_score_card[option - 1] = 50; // score for yahtzee
			}
			else
			{
				printf("Wrong choice, please select a valid option.");
			}
		}

	}

	else // Chance
	{
		if (check_card(player_score_card, option - 1) == 0)
		{
			int sum = 0;
			for (int i = 0; i < 5; i++)
			{
				sum += dice_roll[i];


			}
			player_score_card[option - 1] = sum;

		}
    }

	printf("Score %d \n", player_score_card[option - 1]);



}
//************************************************************************************************************************
//  Calcualtes the total score 
//************************************************************************************************************************

calc_score(int score, int player_scorecard[13])
{
	for (int i = 0; i < 13; i++)
	{
		score += player_scorecard[i];
	
	}
	return score; 
}

//************************************************************************************************************************
// Sums Dice Value
//************************************************************************************************************************

int sum_dice_value(int dice_roll[5])
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int val = dice_roll[i];
		sum = val + sum;
	}
	return sum; 
}

//************************************************************************************************************************
// Shows specific score option 
//************************************************************************************************************************
	
void print_specific_score_option(score_number)
{
	if (score_number <= 6)
	{
		printf("Sum of %d's \n", score_number);
	}
	else if (score_number == 7)
	{
		printf("Three-of-a-kind \n");
	}
	else if (score_number == 8)
	{
		printf("Four-of-a-kind \n");
	}
	else if (score_number == 9)
	{
		printf("Full house \n");
	}
	else if (score_number == 10)
	{
		printf("Small straight \n");
	}
	else if (score_number == 11)
	{
		printf("Large Straight \n");
	}
	else if (score_number == 12)
	{
		printf("Yahtzee!! \n");
	}
	else
	{
		printf("Chance \n");
	}
		
}

//************************************************************************************************************************
// Shows score option 
//************************************************************************************************************************

	void print_score_option(int player_scorecard[])
	{
		for (int i = 0; i < 13; i++)
		{
			if (player_scorecard[i] == 0)
			{
				print_specific_score_option(i + 1);

			}
		}
	}



















