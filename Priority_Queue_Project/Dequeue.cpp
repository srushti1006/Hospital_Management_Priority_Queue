#include"header.h"
struct patient* Dequeue(
						struct priqueue **front ,
						struct priqueue **rear
						)
{
	struct priqueue *dnode = NULL ;
	struct patient *ret = NULL ;
	if((*front) == NULL && (*rear) == NULL)		//if queue is empty
	{
		ret = NULL ;
	}
	else if ((*front) == (*rear))				//only one node is present
	{
		dnode = (*front) ;
		ret = dnode -> data ;
		free(dnode) ;
		*front = *rear = NULL ;
		dnode = NULL ;
	}
	else										//more than one node
	{
		dnode = (*front) ;
		ret = dnode -> data ;
		*front = (*front) -> next ;
		free(dnode) ;
		dnode = NULL ;
	}
	return ret ;
}
