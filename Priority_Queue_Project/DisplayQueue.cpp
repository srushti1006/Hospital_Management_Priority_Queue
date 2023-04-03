#include"header.h"
void DisplayQueue(
					struct priqueue **front ,
					struct priqueue **rear
				)
{
	struct priqueue *tempf = NULL ;
	struct priqueue *tempr = NULL ;

	struct patient *deq= NULL ;
	while(!((*front) == NULL && (*rear) == NULL))
	{
		deq = Dequeue(front,rear) ;
		printf("\n\t------------------------");
		printf("\n\t Id of patient is %d",deq->id) ;
		printf("\n\t Name of patient is %s",deq->name) ;
		printf("\n\t Gender of patient is %c",deq->gender) ;
		printf("\n\t Mobile number of patient is %s",deq->mobno) ;
		printf("\n\t Age of patient is %d",deq->age) ;
		printf("\n\t Weight of patient is %f",deq->weight) ;
		printf("\n\t------------------------");
		Enqueue(&tempf,&tempr,deq) ;
	}
	while(!(tempf == NULL && tempr == NULL))
	{
		deq=Dequeue(&tempf,&tempr) ;
		Enqueue(front,rear,deq) ;
	}
}
