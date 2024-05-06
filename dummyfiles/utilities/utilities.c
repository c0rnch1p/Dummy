#include "utilities.h"
#define TOTAL 0

// file list
char *utilitiesFiles[TOTAL]={
};

// initialize submenu
struct subMenu utilitiesMenu={
	.title="UTILITIES",
	.list=NULL,
	.size=TOTAL
};

// allocate list
void initUtilities(){
	utilitiesMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(utilitiesMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// duplicate elements
	for(int i = 0; i < TOTAL; i++){
		utilitiesMenu.list[i]=strdup(utilitiesFiles[i]);
		if(utilitiesMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// free memory
void cleanUtilities(){
	for(int i = 0; i < TOTAL; i++){
		free(utilitiesMenu.list[i]);}
	free(utilitiesMenu.list);
	utilitiesMenu.list=NULL;
};
