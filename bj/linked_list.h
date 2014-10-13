#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct list_node {
	void* item;
	struct list_node* next;
	struct list_node* previous;
};
typedef struct list_node node;

struct linked_list 
{
	node* front;
	node* rear;
	int size;
};
typedef struct linked_list list;
 
list create_linked_list();
int is_empty(list a);
int size(list a);
void delete(list* a);
int prepend(list* a, void* item);
int append(list* a, void* item);
int insert_into_list(list* a, void* item, int location);
int delete_from_list(list* a, int location);
void* get(list* a, int location);
int set(list* a, void* item, int location);

#endif
