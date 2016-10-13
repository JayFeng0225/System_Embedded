#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
	char words[100];	
}word_list;

int main(){

	FILE *fp;
	int max_length;
	int index = 0;
	char string[100];
	char a[16] = "aaaa";
	char b[16] = "abcdefg";
	int k;
	for(k = 0 ; k < 16 ; k++)
		printf("%d  %d\n",a[k],b[k]);

	int num_words = 0;
	fp = fopen("dictionary/words.txt","r");
	while(fgets(string,100,fp) != NULL){
		num_words++;
	}
	rewind(fp);
	word_list *list = (struct list*) malloc (num_words*sizeof(struct list)); 

	while(fgets(string,100,fp) != NULL){
		strcpy(list[index].words,string);
		index++;
	}
	
//// random
	int i,j;
	word_list temp;
	for(i = 0 ; i < num_words ; i++){
		memset(temp.words,' ',100);
		j = rand()%(num_words);	
		strcpy(temp.words,list[i].words);
		memset(list[i].words,' ',100);
		strcpy(list[i].words,list[j].words);
		memset(list[j].words,' ',100);
		strcpy(list[j].words,temp.words);
	}
////

	for(i = 0 ; i < num_words ; i++){
		//printf("%s",list[i].words);
	}
	return 0;

}

