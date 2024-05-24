#include "all_h3lp.h"


/////////////////////////// UPDATE ALL H3LP SECTION ////////////////////////////
#define TOTAL 16
char *allh3lpFiles[TOTAL]={
	"/00_dummy",
	"development/Gedit",
	"gaming/Aimlabs",	
	"gaming/CS2",
	"gaming/Proton_GE",
	"gaming/Steam",
	"multimedia/Ardour",
	"multimedia/Blender",
	"multimedia/GIMP",
	"multimedia/Inkscape",
	"multimedia/Kdenlive",
	"multimedia/Libre_Office",
	"multimedia/OBS",
	"multimedia/Reaper",
	"multimedia/Shotcut",
	"programming/Bash",
};
////////////////////////////////////////////////////////////////////////////////


// Initialize submenu
struct subMenu allh3lpMenu={
	.title="ALL H3LP",
	.list=NULL,
	.size=TOTAL
};

// Allocate lists
void initAllh3lp(){
	allh3lpMenu.list=(char**)malloc(TOTAL * sizeof(char*));
	if(allh3lpMenu.list == NULL){
		fprintf(stderr, "\n⚠ malloc failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Duplicate elements
	for(int i = 0; i < TOTAL; i++){
		allh3lpMenu.list[i]=strdup(allh3lpFiles[i]);
		if(allh3lpMenu.list[i] == NULL){
			fprintf(stderr, "\n⚠ malloc failed ⚠\n");
			exit(EXIT_FAILURE);
		}
	}
};

// Free memory
void cleanAllh3lp(){
	for(int i = 0; i < TOTAL; i++){
		free(allh3lpMenu.list[i]);}
	free(allh3lpMenu.list);
	allh3lpMenu.list=NULL;
};
