#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry **e)
{	
	int hashindex;
	hashindex = hash(lastname);
	entry *pHead;
	pHead = e[hashindex];
	//int l = 1;
    /* TODO: implement */
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0){
			//printf("find %d : %s \n",l,pHead->lastName);
            return pHead;
		}
		//printf("here %d : %s \n",l,pHead->lastName);
		//l++;
        pHead = pHead->pNext;
	}
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}

unsigned int hash(char *key){
	unsigned int hashVal = 0;
	//printf("%c\n",*key);
	while(*key != '\0')
		hashVal = (hashVal << 5) + *key++;
	//printf("hash index:%d\n",hashVal%42737);
	return hashVal % 42737;
	//return hashVal % 9973;
}


