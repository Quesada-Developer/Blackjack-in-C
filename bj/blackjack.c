#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "player.h"
#include "linked_list.h"

int ranNumGen();
int ranSuitGen();
int randBetGen(int bet);
void create_player_hand(player* a);
void display_list(list* a);
void setUp();
void play();
void portClear();
void gamePlay();
char* return_full_hand(player* a);

list players;
list hands_Played;
player* dealer;
player* mainP;
int pot = 0;

int main()
{
	portClear();
	srand(time(NULL));
	hands_Played = create_linked_list();
	players = create_linked_list();
	dealer = create_player("Dealer");
	
	printf("______ _       ___  _____  _   __   ___  ___  _____  _   __\n");
	printf("| ___ \\ |    \\/ _ \\/  __ \\| | / /  |_  |/ _ \\/  __ \\| | / /\n");
	printf("| |_/ / |    / /_\\ \\ /  \\/| |/ /     | / /_\\ \\ /  \\/| |/ / \n");
	printf("| ___ \\ |    |  _  | |    |    \\     | |  _  | |    |    \\ \n");
	printf("| |_/ / |____| | | | \\__/\\| |\\  \\/\\__/ / | | | \\__/\\| |\\  \\\n");
	printf("\\____/\\_____/\\_| |_/\\____/\\_| \\_/\\____/\\_| |_/\\____/\\_| \\_/\n");
	printf("in C\n\n\n\n");
	
	setUp();
	play();
	return 0;
}

void portClear()
{
	int i;
	for(i = 0; i <= 25; i++)
		printf("\n");
}
int ranNumGen()
{
	return rand() %12;
}
int ranSuitGen()
{	
	return rand() %3;
}
int randBetGen(int bet)
{
	return rand() % bet;
}
void display_list(list* a)
{
	int i;
	for(i = 1; i <= a->size; i++)
		printf("%d\n", (int) get(a,i));
	printf("\n");
}
void setUp()
{
	int i, noPlayers;
	char nameArray[25];
	char* name = nameArray;
	
	printf("Please state your name: ");
	scanf("%s", name);
	printf("Please input number of AI players: ");
	scanf("%d", &noPlayers);
		
	mainP = create_player(name);	
	for(i = 1; i <= noPlayers; i++)
	{
		char tempArray[8];
		char* tempName = tempArray;
		sprintf(tempName,"%s %d", "Player", i);
		prepend(&players, (void *) create_player(tempName));
	}
	prepend(&players, (void *) mainP);
}
void play()
{
	int i,j,k;
	k = 1;
	printf("Your current bank is $%.2f\n", mainP->bankroll);
	while(k)
	{
		printf("Place your bet\n");
		double temp = 0;
		fflush(stdin);
		if(scanf("%f", &temp) < 0)
			printf("Please input a number");
		if(temp > mainP->bankroll)
			printf("Cannot bet more than your bankroll\n");
		else
		{
			bet(mainP, temp);
			k = 0;
		}
	}
	for(j = 0; j < 2; j++)
	{
		create_player_hand(dealer);
		for(i = 1; i <= players.size; i++)
		{
			create_player_hand((player *) get(&players, i));
			printf("For %s, their card is %s\n", ((player*) get(&players, i)) -> name, return_hand(get(&(((player*) get(&players, i)) -> current_hand), 1)));
		}
		if(j)
			printf("The dealer shows %s\n", return_hand(get(&(dealer -> current_hand),1)));
	}
	gamePlay();
}

void gamePlay()
{
	int sum = 0;
	printf("\nCurrent Hand: %s\n", return_full_hand(mainP));
	
}

char* return_full_hand(player* a)
{
	int i;
	char* curHand = return_hand(get(&(((player*) get(&players, 1)) -> current_hand), 1));
	for(i = 2; i <= (mainP -> current_hand).size; i++)
	{
		char* temp = curHand;
		sprintf(curHand, "%s %s", temp, return_hand(get(&(((player*) get(&players, 1)) -> current_hand), i)));
	}
	return curHand;
}

void create_player_hand(player* a)
{
	int p = 1;
	int k = 0;
	int j;
	//printf("creating hands\n");
	while(p)
	{
		hand* b = create_hand(ranSuitGen(), ranNumGen());
		for(j = 1; j <= hands_Played.size; j++)
		{
			hand* c = get(&hands_Played, j);
			//printf("%d:%d - ", b->value,b->suit);
			//printf("%d:%d\n", c->value,c->suit);
			if(c -> value == b -> value)
			{
				if(c -> suit == b-> suit)
					k = 0;
				else
					k = 1;
			}
			else
				k = 1;
		}
		if(k || hands_Played.size == 0)
		{
			set_cur_hand(a, b);
			p = 0;
			append(&hands_Played, (void *) b);
		}
	}
}