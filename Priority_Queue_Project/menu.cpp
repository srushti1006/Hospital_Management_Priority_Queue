#include"header.h"
int menu(void)
{
	int choice = 0 ;
	do
	{
		printf("\n\t Priority Queue using SLL") ;
		printf("\n\t 1. Add a patient") ;
		printf("\n\t 2. Treat a patient") ;
		printf("\n\t 3. Display the first patient to be treated") ;
		printf("\n\t 4. Display all patients") ;
		printf("\n\t 0. Exit\n\t") ;
		printf("\n\t Enter choice : ") ;
		scanf("%d", &choice) ;
	}while(choice < 0 || choice> 4 ) ;
	return choice ;
}
