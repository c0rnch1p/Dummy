#include "programming.h"


////////////////////////// UPDATE PROGRAMMING SECTION //////////////////////////
#define TOTAL 1
char *programmingFiles[TOTAL]={
	"programming/Bash"
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu programmingMenu={
	.title="PROGRAMMING",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initProgramming(){
	programmingMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(programmingMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		programmingMenu.list[i]=strdup(programmingFiles[i]);
		if(programmingMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanProgramming(){
	for(int i = 0; i < TOTAL; i++){
		free(programmingMenu.list[i]);}
	free(programmingMenu.list);
	programmingMenu.list=NULL;
};
