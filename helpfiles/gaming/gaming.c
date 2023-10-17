#include "gaming.h"
#define TOTAL 1

// file list
char *gamingFiles[TOTAL]={
	"CS2"
};

// initialize submenu
struct subMenu gamingMenu={
	.title="GAMING",
	.list=NULL,
	.size=TOTAL
};

// allocate lists
void initGaming(){
	gamingMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(gamingMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// duplicate elements
	for(int i = 0; i < TOTAL; i++){
		gamingMenu.list[i]=strdup(gamingFiles[i]);
		if(gamingMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// free memory
void cleanGaming(){
	for(int i = 0; i < TOTAL; i++){
		free(gamingMenu.list[i]);}
	free(gamingMenu.list);
	gamingMenu.list=NULL;
};
