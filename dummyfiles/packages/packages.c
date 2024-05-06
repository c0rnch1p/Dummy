#include "packages.h"
#define TOTAL 1

// file list
char *packagesFiles[TOTAL]={
	""
};

// initialize submenu
struct subMenu packagesMenu={
	.title="PACKAGES",
	.list=NULL,
	.size=TOTAL
};

// allocate lists
void initPackages(){
	packagesMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(packagesMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// duplicate elements
	for(int i = 0; i < TOTAL; i++){
		packagesMenu.list[i]=strdup(packagesFiles[i]);
		if(packagesMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// free memory
void cleanPackages(){
	for(int i = 0; i < TOTAL; i++){
		free(packagesMenu.list[i]);}
	free(packagesMenu.list);
	packagesMenu.list=NULL;
};
