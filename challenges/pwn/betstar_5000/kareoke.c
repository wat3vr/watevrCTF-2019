#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char * name;
	int points;
}Player;

void view_scores(Player *player_list, int pc){
	for(int i = 0; i < pc; i++){
		printf("Player %s currently has %d points.\n", player_list[i].name, player_list[i].points);
	}
}

void play_a_round(Player *player_list){
	int playerc = 0;
	int bet = 0;
	char playerc_char[5];
	char bet_char[5];
	char winner[64];
	fflush(stdout);
	printf("%s", "Amount of players playing this round: ");
	fgets(playerc_char, 5, stdin);
	playerc = atoi(playerc_char);
	printf("%s\n", "Each player makes a bet between 0 -> 100, the one who lands closest win the round!");
	int rng = rand() % 100 + 1;
	int lead_index = -1;
	int lead_number = 100;

	for(int i = 0; i < playerc; i++){
		printf("%s", player_list[i].name);
		printf("'s bet: ");
		bet = atoi((char *)fgets(bet_char, 5, stdin));
		if(abs(rng - bet) < lead_number){
			lead_index = i;
			lead_number = bet;
			strcpy(winner, player_list[i].name);
		}
	}
	printf("%s", "And the winner is *drumroll*: ");
	printf(winner);
	player_list[lead_index].points += 1;
}

int menu(){
	int option = 0;
	char option_char[4];
	printf("\n%s\n", "1. Play a round");
	printf("%s\n", "2. View scores");
	printf("%s\n", "3. Add a latecommer");
	printf("%s\n", "4. Edit player name");
	printf("%s\n", "5. End the game");
	fflush(stdin);
	fflush(stdout);
	fgets(option_char, 4, stdin);
	option = atoi((char *)option_char);
	return option;
}

int main(){

	time_t t;
	srand((unsigned) time(&t));

	int hasAdded = 0;

	int playerc;
	char playerc_char[3];
	char acceptance[4];
	char change_index_char[3];
	int change_index_int;

	printf("%s\n", "Welcome to the ultimate betting service.");
	printf("%s", "Enter the amount of players: ");
	fgets(playerc_char, 3, stdin);
	playerc = atoi((char *)playerc_char);

	Player* player_list = malloc((playerc+6) * sizeof *player_list);

	for(int i = 0; i < playerc; i++){
		player_list[i].name = (char*)malloc(sizeof(char*));
		printf("%s", "Name: ");
		fgets(player_list[i].name, 10, stdin);
		strtok(player_list[i].name, "\n");
	}

	printf("%s", "Alright, now let's start!");
	while(1 == 1){
		int option = menu();
		switch(option){
			default:
				printf("%s\n", "I think you missed a key there");
				break;
			case 1:
				play_a_round(player_list);
				fflush(stdout);
				break;
			case 2:
				view_scores(player_list, playerc);
				break;
			case 3:
				if(hasAdded != 6){
					printf("%s\n", "Welcome new player!");
					printf("%s", "Please enter your name: ");
					player_list[playerc].name = (char*)malloc(sizeof(char*));
					fgets(player_list[playerc].name, 20, stdin);
					strtok(player_list[playerc].name, "\n");
					playerc++;
					hasAdded++;
				}
				else{
					printf("%s\n", "Ughh, stop it. I already added enought players for you. Stop bothering me");
				}
				break;
			case 4:
				printf("%s\n", "Which player index should i change: ");
				fgets(change_index_char, 5, stdin);
				change_index_int = atoi(change_index_char);
				if(change_index_int >= 0 && change_index_int <= playerc){
					printf("Enter new name: ");
					fgets(player_list[change_index_int].name, 18, stdin);
					strtok(player_list[change_index_int].name, "\n");
				}
				break;
			case 5:
				printf("\n%s", "Accept defeat? [Y/N]: ");
				fflush(stdout);
				if(strcmp(fgets(acceptance, 3, stdin), "N\n") == 0){
					printf("%s\n", "Deal with it. >:)");
				}
				printf("%s\n", "Cya later!");
				exit(0);
				break;
		}
	}
}
