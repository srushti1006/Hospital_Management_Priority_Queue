#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef int BOOL;
#define SIZE 50
#define TRUE 1
#define FALSE 0
struct patient
{
	int id ;	
	char name[20] ;
	int age ;
	char mobno[11] ;
	char gender ;
	float weight ;
};
struct priqueue
{
	struct patient *data ;
	struct priqueue *next ;
};
int menu(void) ;
int Enqueue(
			struct priqueue ** ,
			struct priqueue ** ,
			struct patient * 
			) ;
struct patient* Dequeue(
			struct priqueue ** ,
			struct priqueue ** 
			) ;
void DisplayQueue(
			struct priqueue ** ,
			struct priqueue ** 
			) ;
void DisplayFront(
			struct priqueue ** ,
			struct priqueue ** 
			) ;

void Free(	
			struct priqueue ** ,
			struct priqueue ** 
			) ;

