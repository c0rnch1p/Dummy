#include "security.h"


/////////////////////////// UPDATE SECURITY SECTION ////////////////////////////
#define TOTAL 1
char *securityFiles[TOTAL]={
	"",
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu securityMenu={
	.title="SECURITY",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initSecurity(){
	securityMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(securityMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		securityMenu.list[i]=strdup(securityFiles[i]);
		if(securityMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanSecurity(){
	for(int i = 0; i < TOTAL; i++){
		free(securityMenu.list[i]);}
	free(securityMenu.list);
	securityMenu.list=NULL;
};
