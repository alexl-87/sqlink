#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "File_functions.h"

void wordsCounter(){
	
	int capacity = 10;
	char* str;
	FILE* mFile;
	WordList* wlist;
	str = malloc(sizeof(char)*20);
	if(str == NULL) return;

	mFile = fopen("example.txt", "r");
	if(mFile == NULL) return;

	wlist = createList(capacity);
	if (wlist == NULL) return;
	

	while(!feof(mFile))
	{
		fscanf(mFile, "%s", str);
		printf("%s, ", str);
		setWord(wlist, str);
		str = malloc(sizeof(char)*20);
		if(str == NULL) return;
	}
	fclose(mFile);
}
/*
Insert word
*/
void setWord(WordList* wlist, char* str){

	int result;
	if(wlist == NULL || str == NULL)
		return;
	
	if(wlist->num_of_words == 0)
	{
		insertWord(wlist, str, 0);
		return;
	}

	result = word_search(wlist, str);
	
	if(result == wlist->num_of_words)
		insertWord(wlist, str, wlist->num_of_words);

	if(result < 0) return;

	else
	{
		shift(wlist, result);
		insertWord(wlist, str, result);
	}
	
}
/*
Insert word
*/
void insertWord(WordList* wlist, char* str, int index){
		
	Word* word;
	Word** temp;
	if(index >= wlist->capacity)
	{
		temp = (Word**) realloc(wlist->word_list, sizeof(Word*)*(wlist->capacity*2));
		if(temp == NULL) return;

		wlist->word_list = temp;
		wlist->capacity *= 2;
	}

	word = malloc(sizeof(Word));
	if (word == NULL) return;

	word = create_word(str);
	wlist->word_list[index] = word;
	wlist->num_of_words++;
}

/*
word search
*/

int word_search(WordList* wlist, char* str){

	int i = 0, bool_match = 0, first_match = -1;
	
	for(i; i < wlist->num_of_words; i++)
	{
		if(!strcmp(wlist->word_list[i]->str,str))
		{
			wlist->word_list[i]->counter++;
			return -1;
		}
		else if((int) wlist->word_list[i]->str[0] == str[0] && bool_match == 0)
		{
			bool_match = 1;
			first_match = i;
		}
	}
	if(first_match < 0)
		return wlist->num_of_words;
	else
		return first_match;	
}
/*
Create List
*/
WordList* createList(int capacity){
	WordList* wlist;
	
	wlist = malloc(sizeof(WordList));
	if(wlist == NULL) return NULL;
	
	wlist->word_list = malloc(capacity*sizeof(Word*));
	if(wlist->word_list == NULL)
	{
		free(wlist);
		return NULL;
	}

	wlist->capacity = capacity;
	wlist->num_of_words = 0;

	return wlist;
}
/*
Create word
*/
Word* create_word(char* str){

	Word* newWord;	

	if(str==NULL)
		return NULL;
	
	newWord = malloc(sizeof(Word));
	if(newWord==NULL)
		return NULL;

	newWord->counter = 1;
	newWord->str = str;

	return newWord;
}


/*
Shift
*/
void shift(WordList* wlist, int index){
	Word** temp;
	int i = wlist->num_of_words;
	
	if(index >= wlist->capacity)
	{
		temp = (Word**) realloc(wlist->word_list, sizeof(Word*)*(wlist->capacity*2));

		if(temp == NULL) return;
	
		wlist->word_list = temp;
		wlist->capacity *= 2;
	}	
	
	for(i; i > index; i--)
		wlist->word_list[i] = wlist->word_list[i-1];

}
/*
chars counter
*/

void charsCounter(char* filename){

	FILE* mFile;
	char* str;
	int i;
	int* chars = calloc(123, sizeof(int));
	str = malloc(sizeof(char)*20);
	
	if(chars == NULL || str == NULL) return;

	mFile = fopen(filename, "r");
	while(!feof(mFile))
	{
		fscanf(mFile, "%s", str);
		count(chars, str);
		free(str);
		str = malloc(sizeof(char)*20);
		if(str == NULL) return;
	}
	fclose(mFile);
	
	for(i = 0; i < 123; i++)
	{
		if(chars[i] > 0)
		{
			printf("Char :%c, count: %d\n", (char) i, chars[i]);
		}
	}

	free(chars);
	
}
/*
count
*/
void count(int* chars, char* str){

	int len, i = 0;
	len = strlen(str);
	for(i; i <len; i++)
		chars[(int) str[i]]++;

}

void printNlines(int N, char* filename){
	int i = 0, counter = 0, last_i = 0;
	char** strings;
	char* current_str;
	FILE* mFile;
	mFile = fopen(filename, "r");
	strings = malloc(N*sizeof(int));
	current_str = malloc(512*sizeof(char));

	if(mFile == NULL || strings == NULL || current_str == NULL || N < 1)
		return;

	while(!feof(mFile))
	{
		fgets(current_str, 512, mFile);
		if(counter>= N)
			free(strings[i%N]);
		last_i = i%N;
		strings[i%N] = current_str;
		counter++;
		current_str = malloc(sizeof(char)*512);
		if(current_str == NULL) return;
		i++;
	}
	
	if(counter < N)
	{
		for(i = 0; i < counter; i++)
			free(strings[i]);
		return;
	}
	for(last_i = 0; last_i < N; last_i++)
		printf("%s\n", strings[i%N]);
	
	
}
