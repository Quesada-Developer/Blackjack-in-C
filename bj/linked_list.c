#include "linked_list.h"
#include <stdlib.h>

list create_linked_list()
{
	list a;	
	a.front = NULL;
	a.rear = NULL;
	a.size = 0;
	return a; 
}

int is_empty(list a)
{
	return a.front == NULL;
}

int size(list a)
{
	return a.size;
}

void delete(list* a)
{	
	if(a != NULL)
	{
		node* temp;
		while(a->front != NULL)
		{
			temp = a->front;
			a -> front = temp -> next;
			free(temp);
		}
	//free(a);
	}
	
}

int prepend(list* a, void* item)
{
	int result = 0;

	if( a != NULL)
	{
		node* temp = malloc(sizeof(node));
		if( temp != NULL)
		{
			result = 1;
			temp->item = item;
			temp->previous = NULL;
			if( a->front == NULL)
			{
				temp->next = NULL;
				a->front = temp;
				a->rear = temp;
			}
			else
			{
				temp->next = a->front;
				a->front->previous = temp;
				a->front = temp;
			}
			a->size++;
		}
	}
	return result;
}

int append(list* a, void* item)
{
	int result = 0;
	if(a != NULL)
	{
		node* temp = malloc(sizeof(node));
		if(temp != NULL)
		{
			result = 1;
			temp->item = item;
			temp->next = NULL;
			if(a->front == NULL)
			{
				temp->previous = NULL;
				a->front = temp;
				a->rear = temp;
			}
			else
			{
				temp->previous = a->rear;
				a->rear->next = temp;
				
				a->rear = temp;
			}
			a->size++;
		}
	}
	return result;
}

int insert_into_list(list* a, void* item, int location)
{
	int result;
	if( a == NULL)
		result = 0;
	else if(location < 1 || location > a->size+1)
		result = 0;
	else if(a->size == 0)
	{
		a->front = malloc(sizeof(node));
		if(a->front == NULL) 
			result = 0;
		else
		{
			result = 1;
			a->front->item = item;
			a->rear = a->front;
			a->front->next = NULL;
			a->front->previous = NULL;
			a->size++;
		}
	}
	else
	{
		node* new_node = malloc(sizeof(node));
		if(new_node == NULL) 
			result = 0;
		else
		{
			result = 1;
			new_node->item = item;
			node* temp = a->front;
			if(location == 1)
			{
				new_node->next = temp;
				new_node->previous = NULL;

				a->front->previous = new_node;
				a->front = new_node;

				a->size++;
			}
			else
			{
				int i;
				for(i=1; i<location;i++)
					temp = temp->next;
				new_node->previous = temp;
				new_node->next = temp->next;
				temp->next->previous = temp;
				temp->next = new_node;
				
				if(location == a->size+1)
					a->rear = new_node;
				a->size++;
			}
		}
	}
	return result;
}

int delete_from_list(list* a, int location)
{
	int result;
	if( a == NULL)
		result = 0;
	else if(location < 1 || location > a->size+1)
		result = 0;
	else if(a->size == 0)
		result = 0;
	else
	{
		result = 1; 
		node* temp = a->front;
		if(location == 1)
		{
			a->front = a->front->next;
			if (size (*a) == 1)
				a -> rear = NULL;
			free(temp);
			a->size--;
		}
		else
		{
			int i;
			for(i=1; i < location - 1; i++)
				temp = temp -> next;
			node* temp1 = temp -> next;
			temp -> next = temp1 -> next;
			if(location == a->size)
				a->rear = temp->next;
			free(temp);
			a->size--;
		}
	}
	return result;
}

void* get(list* a, int location)
{
	void* item = NULL;
	if(a != NULL)
	{
		if(location > 0 && location < a->size+1)
		{
			int i;
			node* ret_node = a->front; 
			for(i=1; i<location; i++)
				ret_node = ret_node->next;
			item = ret_node->item;
		}
	}
 
	return item;
}

int set(list* a, void* item, int location)
{
	int result;
	if( a == NULL)
		result = 0;

	else if(location < 1 || location > a->size+1)
		result = 0;

	else if(item == NULL)

		result = 0;
	else
	{
		node* ret_node = a->front; 
		int i;
		for(i=1; i<location; i++)
			ret_node = ret_node->next;
		ret_node->item = item;
	}
	return result;
}
