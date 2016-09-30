#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} LIST;


LIST *append( LIST *, int );
LIST *sort( LIST * );
LIST *list_switch( LIST *, LIST * );
LIST *mergesort( LIST*);
void print_list( LIST * );

int main(void)
{
    LIST *try;
    int i;

    // This is just testing code
    try = NULL;
    try = append( try, 5 );
    try = append( try, 2 );
    try = append( try, 9 );
    try = append( try, 8 );
    try = append( try, 1 );
    try = append( try, 7 );
	
	//using  try and fast as head of two link list	
	//printf("%d %d\n",try->data,fast->data);

    printf("Original list:\n");
    print_list( try );
    try = mergesort( try );
    printf("Sorted list:\n");
    print_list( try );
    return 0;
}

void print_list( LIST *t )
{
    while( t != NULL ) {
        printf( "%d\n", t->data );
        t = t->next;
    }
}

LIST *append( LIST *start, int newdata )
{
    LIST *new, *end, *ret;

    if( (new = (LIST *)malloc(sizeof(LIST))) == NULL) {
        fprintf( stderr, "Memory Allocation error.\n" );
        // In Windows, replace following with a return statement.
        exit(1);
    }
    if( start == NULL )
        ret = new;
    else {
        ret = start;
        end = start;
        while( end->next != NULL ) end = end->next;
        end->next = new;
    }
    new->data = newdata;
    new->next = NULL;
    return ret ;
}

LIST* merge(LIST *l1, LIST *l2){
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	int count = 0;
	LIST *head = (LIST*) malloc(sizeof(LIST));
	LIST *ptr = head;
	LIST *start1 = l1;	
	LIST *start2 = l2;

	while(start1!=NULL){
		count++;
		start1 = start1->next;
	}

	while(start2!=NULL){
		count++;
		start2 = start2->next;
	}
	while(count > 1){
		ptr->next = (LIST*) malloc(sizeof(LIST));
		ptr = ptr->next;
		count--;
	}
	ptr->next = NULL;

	start1 = l1;
	start2 = l2;
	ptr = head;
	while(start1!=NULL && start2!=NULL){
		if(start1->data < start2->data){
			ptr->data = start1->data;
			ptr = ptr->next;
			start1 = start1->next;
		}
		else{
			ptr->data = start2->data;
			ptr = ptr->next;
			start2 = start2->next;
		}
	}
	while(start1!=NULL){
		ptr->data = start1->data;
		ptr = ptr->next;
		start1 = start1->next;
	}
	while(start2!=NULL){
		ptr->data = start2->data;
		ptr = ptr->next;
		start2 = start2->next;
	}
	return head;

}

LIST* mergesort(LIST *try){
	if(try->next == NULL)
		return try;
	// spilt linked list
	LIST *slow = try;
	LIST *fast = try->next;
	
	while(fast->next!=NULL){
		slow = slow->next;
		fast = fast->next;
		if(fast->next != NULL)
			fast = fast->next;
	}

	fast = slow->next;
	slow->next = NULL;
	slow = try;
	//
	//printf("%d %d\n",slow->data,fast->data);

	slow = mergesort(slow);
	fast = mergesort(fast);

	try = merge(slow,fast);
	return try;
}
LIST *list_switch( LIST *l1, LIST *l2 )
{
    l1->next = l2->next;
    l2->next = l1;
    return l2;
}
