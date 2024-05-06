#include "networking.h"


////////////////////////// UPDATE NETWORKING SECTION ///////////////////////////
#define TOTAL 1
char *networkingFiles[TOTAL]={
	"",
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu networkingMenu={
	.title="NETWORKING",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initNetworking(){
	networkingMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(networkingMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		networkingMenu.list[i]=strdup(networkingFiles[i]);
		if(networkingMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanNetworking(){
	for(int i = 0; i < TOTAL; i++){
		free(networkingMenu.list[i]);}
	free(networkingMenu.list);
	networkingMenu.list=NULL;
};
