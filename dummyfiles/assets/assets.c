#include "assets.h"


//////////////////////////// UPDATE ASSETS SECTION /////////////////////////////
#define TOTAL 1
char *assetsFiles[TOTAL]={
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu assetsMenu={
	.title="ASSETS",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initAssets(){
	assetsMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(assetsMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		assetsMenu.list[i]=strdup(assetsFiles[i]);
		if(assetsMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanAssets(){
	for(int i = 0; i < TOTAL; i++){
		free(assetsMenu.list[i]);}
	free(assetsMenu.list);
	assetsMenu.list=NULL;
};
