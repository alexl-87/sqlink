
#ifndef File_functions
#define File_functions

typedef struct Word{
	
	char* str;
	int counter;

}Word;

typedef struct WordList{
	
	Word** word_list;
	int capacity;
	int num_of_words;

}WordList;


WordList* createList(int capacity);
Word* create_word(char* str);
void wordsCounter();
void setWord(WordList* wList, char* str);
void insertWord(WordList* wlist, char* str, int index);
void shift(WordList* wList, int index);
void charsCounter(char* filename);
void count(int* chars, char* str);
void printNlines(int N, char* filename);
#endif
