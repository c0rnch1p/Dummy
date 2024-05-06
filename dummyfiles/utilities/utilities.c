#include "utilities.h"


/////////////////////////// UPDATE UTILITIES SECTION ///////////////////////////
#define TOTAL 0
char *utilitiesFiles[TOTAL]={
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu utilitiesMenu={
	.title="UTILITIES",
	.list=NULL,
	.size=TOTAL
};

// Allocate list
void initUtilities(){
	utilitiesMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(utilitiesMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		utilitiesMenu.list[i]=strdup(utilitiesFiles[i]);
		if(utilitiesMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanUtilities(){
	for(int i = 0; i < TOTAL; i++){
		free(utilitiesMenu.list[i]);}
	free(utilitiesMenu.list);
	utilitiesMenu.list=NULL;
};
