#ifndef H_Hash
#define H_Hash

enum exeStatus {OK, mallocE, paramE, hashingE, collision, True, False};

typedef enum 		exeStatus exeStatus;
typedef struct 		HashMap HashMap;
typedef struct 		HashMapNode HashMapNode;
typedef exeStatus 	(*userHashFunction)(void* key, unsigned long* index);
typedef exeStatus 	(*userCompareFunction)(void* key_1, void* key_2);
typedef exeStatus 	(*userForEachFunction)(void* value);

exeStatus createHashMap	(unsigned long capacity, userHashFunction hashFunc, userCompareFunction compareFunc, HashMap** hMap);
exeStatus insertValue	(HashMap* map, void* key, void* value);
exeStatus findValue		(HashMap* map, void* key, void* value);
exeStatus forEach		(HashMap* map, userForEachFunction foreachFunc, void* value);
#endif