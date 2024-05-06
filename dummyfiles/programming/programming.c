#include "programming.h"
#define TOTAL 1

// file list
char *programmingFiles[TOTAL]={
	"programming/Bash"
};

// initialize submenu
struct subMenu programmingMenu={
	.title="PROGRAMMING",
	.list=NULL,
	.size=TOTAL
};

// allocate lists
void initProgramming(){
	programmingMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(programmingMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// duplicate elements
	for(int i = 0; i < TOTAL; i++){
		programmingMenu.list[i]=strdup(programmingFiles[i]);
		if(programmingMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// free memory
void cleanProgramming(){
	for(int i = 0; i < TOTAL; i++){
		free(programmingMenu.list[i]);}
	free(programmingMenu.list);
	programmingMenu.list=NULL;
};
