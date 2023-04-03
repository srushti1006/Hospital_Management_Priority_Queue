#include"header.h"
int Enqueue(
			struct priqueue **front ,
			struct priqueue **rear ,
			struct patient *patient
			)
{
	struct priqueue *newnode = NULL ;
	int flag = 1 ;
	newnode = (struct priqueue *)calloc(1,sizeof(struct priqueue)) ;
	if(newnode == NULL)
	{
		printf("Memory allocation failed") ;
		flag = 0 ;
	}
	else
	{
		newnode -> data = patient ;
		if((*front) == NULL && (*rear) == NULL)//if queue is empty
		{
			*rear = newnode ;
			*front = newnode ;
		}
		else									//more than one patient in queue
		{
			(*rear) -> next = newnode ;
			(*rear) = (*rear) -> next ;
		}
		flag = 1  ;
	}
	return flag ;
}
