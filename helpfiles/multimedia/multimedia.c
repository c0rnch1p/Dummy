#include "multimedia.h"
#define TOTAL 5

// file list
char *multimediaFiles[TOTAL]={
	"multimedia/Ardour",
	"multimedia/GIMP",
	"multimedia/Inkscape",
	"multimedia/Kdenlive",
	"multimedia/Reaper",	
};

// initialize submenu
struct subMenu multimediaMenu={
	.title="MULTIMEDIA",
	.list=NULL,
	.size=TOTAL
};

// allocate lists
void initMultimedia(){
	multimediaMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(multimediaMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// duplicate elements
	for(int i = 0; i < TOTAL; i++){
		multimediaMenu.list[i]=strdup(multimediaFiles[i]);
		if(multimediaMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// free memory
void cleanMultimedia(){
	for(int i = 0; i < TOTAL; i++){
		free(multimediaMenu.list[i]);}
	free(multimediaMenu.list);
	multimediaMenu.list=NULL;
};
