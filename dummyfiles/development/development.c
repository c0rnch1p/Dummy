#include "development.h"


///////////////////////// UPDATE DEVELOPMENT SECTION ///////////////////////////
#define TOTAL 1
char *developmentFiles[TOTAL]={
	"development/Gedit"
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu developmentMenu={
	.title="DEVELOPMENT",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initDevelopment(){
	developmentMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(developmentMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		developmentMenu.list[i]=strdup(developmentFiles[i]);
		if(developmentMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanDevelopment(){
	for(int i = 0; i < TOTAL; i++){
		free(developmentMenu.list[i]);}
	free(developmentMenu.list);
	developmentMenu.list=NULL;
};
