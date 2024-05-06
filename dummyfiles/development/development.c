#include "development.h"
#define TOTAL 1

// file list
char *developmentFiles[TOTAL]={
	"development/Gedit"
};

// initialize submenu
struct subMenu developmentMenu={
	.title="DEVELOPMENT",
	.list=NULL,
	.size=TOTAL
};

// allocate lists
void initDevelopment(){
	developmentMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(developmentMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// duplicate elements
	for(int i = 0; i < TOTAL; i++){
		developmentMenu.list[i]=strdup(developmentFiles[i]);
		if(developmentMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// free memory
void cleanDevelopment(){
	for(int i = 0; i < TOTAL; i++){
		free(developmentMenu.list[i]);}
	free(developmentMenu.list);
	developmentMenu.list=NULL;
};
