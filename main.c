#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
   int data;
   struct node *next;
   struct node *prev;
};
struct node *head = NULL;
struct node *last = NULL;

/***********************Listeleme Kismi**************************////buketecrinozturk
void listele() {

   struct node *list = head;
	
   printf("\n[ ");
   printf("(%d) ",list->data);
   
   list = list->next; 
    while(list!= head) {       
      printf("(%d) ",list->data);
      list = list->next; 
    }
   printf(" ]");
   
printf("\n*_*head_prev_*_* %d",head->prev->data);
printf("\n*_*last_next_*_* %d",last->next->data);
}

/********************** Basa ve Sona Eleman EKleme Kismi*****************///buketecrinozturk
void elemanEkleme(int data,int konum) {

   struct node *list = (struct node*) malloc(sizeof(struct node));
   list->data = data;
   
   if(head==NULL) { // Yani liste boþsa
   	  list->next=NULL;
   	  list->prev=NULL;
      head=last = list;
      
   } else {
   		if(konum==1) //Listenin Baþýna eklenecek ise
   		{
   			 head->prev = list;
   			 list->next = head;
   			 list->prev = last;
   			 last->next = list;
   			 head = list;

		}
		else if (konum==2)//Listenin sonuna eklenecek ise
    	{	
			
    		last->next=list;
    		list->prev=last;
    		list->next=head;
    		head->prev=list;
    		last = list;
		} 
		
   }
}

/********************** Araya Eleman EKleme Kismi *****************////buketecrinozturk
void arayaElemanEkleme (int data, int n){
   struct node *list = (struct node*) malloc(sizeof(struct node));
   struct node *list_gecici = head;
int i=0; 
	
	list->data=data;
		printf("\n....%d",list->data);
   while(i < n) {
		list_gecici = list_gecici -> next;
		i++;
	}
		printf("\n....%d",list_gecici->data);
		list->next=list_gecici;
		list->prev=list_gecici->prev;
		
   		list_gecici->prev->next=list;
   		list_gecici->prev=list;
   }
/********************** Eleman Silme Kismi *****************////buketecrinozturk

void elemanSil(int data){
	
	struct node *list=NULL;
	bool found=false;
	if(head==NULL){//Liste boþ
		last=NULL;	
	}
	else{
		if(head->data==data){//Silinecek eleman baþta ise
		
			head->prev=NULL;
			list=head->next;
			list->prev=last;
			last->next=list;
			head=list;
		}
		else if(last->data==data){//Silinecek eleman sonda ise
			last->next=NULL;
			list=last->prev;
			list->next=head;
			head->prev=list;
			last=list;
		}else{
			list=head;
			while(list->data!=data){
					list=list->next;
					if(list->next==head){
						found=false;
						printf("\nBoyle bir eleman listede yok");
						return;
					}else{
						found=true;
					}
			}
			if(true==found)
			{
				list->prev->next = list->next;
				list->next->prev=list->prev;
							
		  		free(list);
	      		list = NULL;
					
			}
			
		} 
		
	}
	
	
}
int main(int argc, char *argv[]) {
   int i,j,k=0;
   struct node *current=NULL;
   for(i=6; i<10; i++){
   	  elemanEkleme(i,2); //sona eleman ekleme
   }
 
   for(j=4; j>0; j--){
   	   elemanEkleme(j,1); //baþa eleman ekleme
   }
   arayaElemanEkleme(5,4);
      listele();
    printf("\n Listeden ilk eleman siliniyor: ");  
    elemanSil(1);
    listele();
    printf("\n Listeden son eleman siliniyor: ");  
    elemanSil(9);
    listele();
    printf("\n Listede olmayan bir eleman siliniyor: ");  
    elemanSil(100);
    listele();
 /*
    printf("\n Liste Elemanlari (Bastan Sona Dogru): ");  
    listele(); 
    printf("\n *************** ");  
    printf("\n Listeden ilk eleman siliniyor: ");  
    elemanSil(1);
    listele(); 
    printf("\n *************** ");  
    printf("\n Listeden son eleman siliniyor: ");  
    elemanSil(9);
    listele(); 
    printf("\n *************** ");  
    printf("\n Listede 6 elemani siliniyor: ");  
    elemanSil(6);
    listele(); 
    printf("\n *************** ");  
    printf("\n Listede 12 elemani siliniyor: ");  
    elemanSil(12);
    listele(); 
    printf("\n *************** "); 
    */
	return 0; 
}

