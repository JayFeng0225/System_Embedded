#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* original version */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;
/*
typedef struct HASHTABLE_ENTRY {
	char lastName[MAX_LAST_NAME_SIZE];
	struct HASHTABLE_ENTRY *next;
	entry *pHead;
} hashtable;
*/

entry *findName(char lastname[], entry **pHead);
entry *append(char lastName[], entry *e);
unsigned int hash(char *key);

#endif
