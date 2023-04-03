#include"header.h"
void Free(
			struct priqueue **front ,
			struct priqueue **rear
		)
{
	while((*front) == NULL && (*rear) == NULL)
	{
		Dequeue(front,rear) ;
	}
}