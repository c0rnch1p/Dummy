#include "gaming.h"


//////////////////////////// UPDATE GAMING SECTION /////////////////////////////
#define TOTAL 4
char *gamingFiles[TOTAL]={
	"gaming/Aimlabs",
	"gaming/CS2",
	"gaming/Proton_GE",
	"gaming/Steam",
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu gamingMenu={
	.title="GAMING",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initGaming(){
	gamingMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(gamingMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		gamingMenu.list[i]=strdup(gamingFiles[i]);
		if(gamingMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanGaming(){
	for(int i = 0; i < TOTAL; i++){
		free(gamingMenu.list[i]);}
	free(gamingMenu.list);
	gamingMenu.list=NULL;
};
