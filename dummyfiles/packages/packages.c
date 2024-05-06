#include "packages.h"


/////////////////////////// UPDATE PACKAGES SECTION ////////////////////////////
#define TOTAL 1
char *packagesFiles[TOTAL]={
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu packagesMenu={
	.title="PACKAGES",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initPackages(){
	packagesMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(packagesMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		packagesMenu.list[i]=strdup(packagesFiles[i]);
		if(packagesMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanPackages(){
	for(int i = 0; i < TOTAL; i++){
		free(packagesMenu.list[i]);}
	free(packagesMenu.list);
	packagesMenu.list=NULL;
};
