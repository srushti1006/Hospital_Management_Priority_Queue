#include"header.h"
void DisplayFront(
					struct priqueue **front,
					struct priqueue **rear
				)
{
	//struct patient ret = {0,{'\0'},0,{'\0'},'\0',0.0f} ;
	struct patient *deq= NULL ;
	//printf("displayfront");
	if((*front) == NULL && (*rear) == NULL)//queue empty
	{
		//ret.id = -1 ;
		printf("\n\t No patients in this queue");
	}
	else
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
		Enqueue(front,rear,deq) ;
	}
	//printf("displayfront");
}
