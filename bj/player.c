#include <stdlib.h>
#include "player.h"
#include "linked_list.h"
#include <string.h>
#include <stdio.h>

player* create_player(char* n)
{
	player* a = malloc(sizeof(a));
	a -> bet = 0.0;
	a -> bankroll = 500.0;
	a -> current_hand = create_linked_list();
	a -> name = create_copy(n);
	return a;
}

hand* create_hand(int i, int j)
{
	hand* a = malloc(sizeof(a));
	a -> suit = i;
	a -> value = j;
	return a;
}

void delete_player(player* a)
{
	if(a != NULL)
	{
		free(a -> name);
		delete(&(a -> current_hand));
		free(a);
	}
}

void bet(player* a, double bet)
{
	a -> bet = bet;
	a -> bankroll -= bet;
}
void result(player* a, int multiplier)
{
	a -> bankroll += a -> bet * multiplier;
}
void set_cur_hand(player* a, hand* h)
{
	prepend(&(a -> current_hand), (void *) h);
}

char* create_copy(char* s)
{
	char* cpy = NULL;
	if(s!= NULL)
	{
		cpy = malloc ((strlen(s) + 1) * sizeof(char));
		strcpy(cpy, s);
		cpy[strlen(s)] = 0;
	}
	return cpy;
}
char* return_hand(hand* a)
{
	//char cur_hand[3];
	//char* current_hand = malloc (3 * sizeof(char));
	char temp[2];
	char* cur_hand;
	switch(a -> suit)
	{
		case 0: strcpy(temp, "S "); break;
		case 1: strcpy(temp, "C "); break;
		case 2: strcpy(temp, "D "); break;
		case 3: strcpy(temp, "H "); break;
	}
	switch(a -> value)
	{
		case 0: sprintf(cur_hand, "%s%s", "A", temp); break;
		case 1: sprintf(cur_hand, "%s%s", "1", temp); break;
		case 2: sprintf(cur_hand, "%s%s", "2", temp); break;
		case 3: sprintf(cur_hand, "%s%s", "3", temp); break;
		case 4: sprintf(cur_hand, "%s%s", "4", temp); break;
		case 5: sprintf(cur_hand, "%s%s", "5", temp); break;
		case 6: sprintf(cur_hand, "%s%s", "6", temp); break;
		case 7: sprintf(cur_hand, "%s%s", "7", temp); break;
		case 8: sprintf(cur_hand, "%s%s", "8", temp); break;
		case 9: sprintf(cur_hand, "%s%s", "9", temp); break;
		case 10: sprintf(cur_hand, "%s%s", "J", temp); break;
		case 11: sprintf(cur_hand, "%s%s", "Q", temp); break;
		case 12: sprintf(cur_hand, "%s%s", "K", temp); break;
	}
	//printf("%s",cur_hand);
	//strcpy(current_hand, cur_hand);
	//current_hand[strlen(s)] = 0;
	//printf("%s", temp);
	return cur_hand;
	
}