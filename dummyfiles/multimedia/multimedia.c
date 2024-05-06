#include "multimedia.h"


////////////////////////// UPDATE MULTIMEDIA SECTION ///////////////////////////
#define TOTAL 9
char *multimediaFiles[TOTAL]={
	"multimedia/Ardour",
	"multimedia/Blender",
	"multimedia/GIMP",
	"multimedia/Inkscape",
	"multimedia/Kdenlive",
	"multimedia/Libre_Office",
	"multimedia/OBS",
	"multimedia/Reaper",
	"multimedia/Shotcut",
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu multimediaMenu={
	.title="MULTIMEDIA",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initMultimedia(){
	multimediaMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(multimediaMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		multimediaMenu.list[i]=strdup(multimediaFiles[i]);
		if(multimediaMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanMultimedia(){
	for(int i = 0; i < TOTAL; i++){
		free(multimediaMenu.list[i]);}
	free(multimediaMenu.list);
	multimediaMenu.list=NULL;
};
