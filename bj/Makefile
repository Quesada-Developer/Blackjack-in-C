all: blackjack.exe

linked_list.o: linked_list.c linked_list.h
	gcc -g -c linked_list.c
	
blackjack.o: blackjack.c player.h linked_list.h
	gcc -g -c blackjack.c -std=c99
	
player.o: player.c player.h linked_list.h
	gcc -g -c player.c
	
blackjack.exe: blackjack.o linked_list.o player.o
	gcc -o blackjack.exe blackjack.o linked_list.o player.o