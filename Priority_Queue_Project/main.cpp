#include"header.h"
int main(void)
{
	char name[20] = {'\0'} ;
	int choice = 0 ;
	int id = 0 ;
	int pri = 0 ;
	int ret = 0 ;
	struct patient *deq = NULL ;
	struct patient *disfro = NULL ;
	struct patient *enq = NULL ;
	struct priqueue *shead=NULL, *stail=NULL;
	struct priqueue *mhead=NULL, *mtail=NULL;
	struct priqueue *ghead=NULL, *gtail=NULL;
	do
	{
		choice = menu() ;
		switch(choice)
		{
			case 1 :
				enq = (struct patient *)calloc(1,sizeof(struct patient)) ;
				flushall();
				printf("\n\t Enter name of patient: ") ;
				scanf("%19s",enq->name) ;
				flushall() ;
				printf("\n\t Enter age of patient: ") ;
				scanf("%d",&enq->age) ;
				flushall() ;
				do
				{
					printf("\n\t Enter 10 digit mobile number of patient: ") ;
					scanf("%10s",enq->mobno) ;
				}while(strlen(enq->mobno) != 10 ) ;
				flushall() ;
				do
				{
					printf("\n\t Enter gender of patient Male:m and Female:f : ") ;
					scanf("%c",&enq->gender) ;
					flushall() ;
				}while(enq->gender != 'm' && enq->gender != 'f' && enq->gender!='M' && enq->gender!='F') ;
				flushall() ;
				printf("\n\t Enter weight of patient in kgs: ") ;
				scanf("%f",&enq->weight) ;
				flushall() ;
				id++ ;
				enq->id = id ;
				do
				{
					printf("\n\t Enter priority of patient\n\t 1.serious illness\n\t 2.medium illness\n\t 3.general\n\t ") ;
					scanf("%d",&pri) ;
				}while(pri < 1 && pri > 3) ;
				if(pri == 1) 
				{
					ret = Enqueue(&shead,&stail,enq) ;
				}
				else if(pri == 2)
				{
					ret = Enqueue(&mhead,&mtail,enq) ;
				}
				else if(pri == 3)
				{
					ret = Enqueue(&ghead,&gtail,enq) ;
				}
				else
				{
					printf("\n\t You entered wrong priority") ;
				}
				if(ret == 0)
				{
					printf("\n\t Patient can't be queued Hospital is full") ;
				}
				else
				{
					printf("\n\t Patient queued with id %d",id) ;
				}
				break ;
			case 2 :
				do
				{
					printf("\n\t Enter patient to be treated\n\t 1.serious illness\n\t 2.medium illness\n\t 3.general\n\t ") ;
					scanf("%d",&pri) ;
				}while(pri < 1 && pri > 3) ;
				if(pri == 1) 
				{
					deq = Dequeue(&shead,&stail) ;
				}
				else if(pri == 2)
				{
					deq = Dequeue(&mhead,&mtail) ;
				}
				else
				{
					deq = Dequeue(&ghead,&gtail) ;
				}
				
				if(deq == NULL)
				{
					printf("\n\t There were no patients") ;
				}
				else
				{
					printf("\n\t Patient treated with id %d",deq->id) ;
					printf("\n\t Name of patient treated is %s",deq->name) ;
					printf("\n\t Gender of patient treated is %c",deq->gender) ;
					printf("\n\t Mobile number of patient treated is %s",deq->mobno) ;
					printf("\n\t Age of patient treated is %d",deq->age) ;
					printf("\n\t Weight of patient treated is %f",deq->weight) ;
				}
				break ;
			case 3 :
				do
				{
					printf("\n\t Enter priority of patient to be displayed\n\t 1.serious illness\n\t 2.medium illness\n\t 3.general\n\t ") ;
					scanf("%d",&pri) ;
				}while(pri < 1 && pri > 3) ;
				if(pri == 1) 
				{
					DisplayFront(&shead,&stail) ;
				}
				else if(pri == 2)
				{
					DisplayFront(&mhead,&mtail) ;
				}
				else
				{
					DisplayFront(&ghead,&gtail) ;
				}
				/*if(disfro->id == -1)
				{
					printf("\n\t There were no patients") ;
				}*/
				break ;
			case 4 :
				printf("\n\t 1.Serious patients") ;
				DisplayQueue(&shead,&stail) ;
				printf("\n\t ");
				printf("\n\t 2.Medium illness patients") ;
				DisplayQueue(&mhead,&mtail) ;
				printf("\n\t ");
				printf("\n\t 3.General patients") ;
				printf("\n\t ");
				DisplayQueue(&ghead,&gtail) ;
				break ;
			case 0 :
				if(!(shead == NULL && shead == NULL))
				{
					Free(&shead,&stail) ;
				}
				if(!(mhead == NULL && mhead == NULL))
				{
					Free(&mhead,&mtail) ;
				}
				if(!(ghead == NULL && ghead == NULL))
				{
					Free(&ghead,&gtail) ;
				}
				printf("\n\t Exiting\n\t ") ;
		}
	}while(choice != 0) ;
	return 0 ;
}
