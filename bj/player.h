#include "linked_list.h"

#ifndef _BJ_PLAYER_H
#define _BJ_PLAYER_H

typedef struct
{
	char* name;
	list current_hand;
	double bet;
	double bankroll;
} player;

typedef struct
{
	int suit;
	int value;
} hand;

player* create_player(char* name);
hand* create_hand(int i, int j);
void delete_player(player* a);

void bet(player* a, double bet);
void result(player* a, int multiplier);

void set_cur_hand(player* a, hand* h);
char* return_hand(hand* a);


char* create_copy(char* s);

#endif