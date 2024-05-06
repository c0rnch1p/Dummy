#include "dummyfiles/headers.h"
#define CPAIRS 8
#define MMSIZE 10
#define MMWDTH 15
#define SMLNTH 20
#define SMWDTH 28
#define YCNTR (LINES / 2)
#define XCNTR (COLS / 2)

WINDOW *listallWin=NULL;
WINDOW *menuWin=NULL;
WINDOW *subWin=NULL;
WINDOW *keysWin=NULL;
WINDOW *srchWin=NULL;

// Initialize submenus
typedef struct{
	const char* title;
	char** list;
	int size;
}subMenu;

// Initlialize lists
void initSubmenus(){
	initAllh3lp();
	initMultimedia();
	initNetworking();
	initGaming();
	initAssets();
	initSecurity();
	initPackages();
	initProgramming();
	initDevelopment();
	initUtilities();
};

/* Source data is stored in the .c files in the dummyfiles/ folder, there is a
source file for each submenu, the file list arrays have been allocated dynamic
memory so they need to be initialized and cleaned */

// Clean lists
void cleanSubmenus(){
	cleanAllh3lp();
	cleanMultimedia();
	cleanNetworking();
	cleanGaming();
	cleanAssets();
	cleanSecurity();
	cleanPackages();
	cleanProgramming();
	cleanDevelopment();
	cleanUtilities();
};

int checkDeps(const char* command);
void clearTerminal();
void sigHandler(int sig);
void screenKeys(int ch, int* toggleKeys);
void fileReader(const char* flPth);
void alphabetSrch(
	const char* srchChar, int* highlight, int* curSelect,
	const char* uprMenu[], const char* lwrMenu[]);
void eliminationSrch(int highlight, subMenu subMenus[]);
void mainmenuScr(const char* uprMenu[], const char* lwrMenu[], subMenu subMenus[]);
void submenuScr(int highlight, subMenu subMenus[]);
void updateSection(int highlight, subMenu subMenus[]);

int main(){
	if(!checkDeps("bat") || !checkDeps("highlight")){
		fprintf(stderr, "⚠ dependency check failed ⚠\n");
		exit(EXIT_FAILURE);}
	// External data
	initSubmenus();
	subMenu subMenus[MMSIZE]={
		{allh3lpMenu.title, allh3lpMenu.list, allh3lpMenu.size},
		{assetsMenu.title, assetsMenu.list, assetsMenu.size},
		{developmentMenu.title, developmentMenu.list, developmentMenu.size},
		{gamingMenu.title, gamingMenu.list, gamingMenu.size},
		{multimediaMenu.title, multimediaMenu.list, multimediaMenu.size},
		{networkingMenu.title, networkingMenu.list, networkingMenu.size},
		{packagesMenu.title, packagesMenu.list, packagesMenu.size},
		{programmingMenu.title, programmingMenu.list, programmingMenu.size},
		{securityMenu.title, securityMenu.list, securityMenu.size},
		{utilitiesMenu.title, utilitiesMenu.list, utilitiesMenu.size}};
	if(subMenus == NULL){
		fprintf(stderr, "⚠ memory allocation failed ⚠\n");
		exit(EXIT_FAILURE);}
	// Main menu layout
	const char *uprMenu[1]={subMenus[0].title};
	const char *lwrMenu[MMSIZE];
	// Curses
	while(1){
		initscr();
		noecho();
		cbreak();
		curs_set(0);
		keypad(stdscr, TRUE);
		signal(SIGINT, sigHandler);
		start_color();
		use_default_colors();
		// +1 to skip first submenu title
		for(int i=0; i < MMSIZE; i++){
			lwrMenu[i]=subMenus[i + 1].title;}
		int colorPairs[CPAIRS][2]={
			{1, COLOR_BLACK},
			{2, COLOR_WHITE},
			{3, COLOR_MAGENTA},
			{4, COLOR_RED},
			{5, COLOR_YELLOW},
			{6, COLOR_GREEN},
			{7, COLOR_CYAN},
			{8, COLOR_BLUE}};
		// -1 as pair value for transparency
		for(int i=0; i < CPAIRS; i++){
			init_pair(colorPairs[i][0], colorPairs[i][1], -1);}		
		mainmenuScr(uprMenu, lwrMenu, subMenus);
		napms(250);}
	cleanSubmenus();
	return 0;
}

// Check dependencies
int checkDeps(const char* command){
	char cmd[256];
	snprintf(cmd, sizeof(cmd),
		"command -v %s >/dev/null 2>&1", command);
	return system(cmd) == 0;
}

// Handle cleanup
void clearTerminal(){
	int wstatus;
	int pid=fork();
	if(pid == 1){
		fprintf(stderr, "⚠ pid fork failed ⚠\n");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		execlp("clear", "clear", NULL);
		return;}
	waitpid(pid, &wstatus, 0);
	system("clear");
}

/* Relating to the functions above and below theres issues with an occasional
leftover charset when ctrl+c is used to exit while bat and highlight are active,
q and ctrl+z work fine */

// Exit gracefully
void sigHandler(int sig){
	clear();
	keypad(stdscr, FALSE);
	fflush(stdout);
	endwin();
	atexit(clearTerminal);
	reset_shell_mode();
	exit(EXIT_SUCCESS);
}

// Keyboard info
void screenKeys(int ch, int* toggleKeys){
	keysWin=newwin(9, 27, LINES -9, 0);
	/* The order of args for window creation is win height, win width, row start
	and col start, the curses library, includes the LINES and COLS macros
	containing the total values for the current terminal screen */
	if(ch == KEY_F(9)){*toggleKeys=!(*toggleKeys);}
	if(*toggleKeys){
		attron(COLOR_PAIR(6));
		mvprintw(LINES - 1, 1, "<%2s> screen keys", "");
		attron(A_BOLD);
		mvprintw(LINES - 1, 2, "F9");
		attroff(A_BOLD);
		attroff(COLOR_PAIR(6));
		wclear(keysWin);
		wrefresh(keysWin);    
	}else{
		wattron(keysWin, A_BOLD | COLOR_PAIR(8));
		box(keysWin, 0, 0);
		wattroff(keysWin, A_BOLD | COLOR_PAIR(8));
		wattron(keysWin, COLOR_PAIR(6));
		mvwprintw(keysWin, 1, 2, "<%3s> Search submenus", "");
		mvwprintw(keysWin, 2, 2, "<%3s> Exit search", "");
		mvwprintw(keysWin, 3, 2, "<%7s> Cycle items", "");
		mvwprintw(keysWin, 4, 2, "<%9s> Select item", "");
		mvwprintw(keysWin, 5, 2, "<%10s> Main menu", "");
		mvwprintw(keysWin, 6, 2, "<%8s> Quit program", "");
		mvwprintw(keysWin, 7, 2, "<%3s> Update section", "");
		wattron(keysWin, A_BOLD);
		mvwprintw(keysWin, 1, 3, "/|?");
		mvwprintw(keysWin, 2, 3, "ESC");
		mvwprintw(keysWin, 3, 3, "UP|DOWN");
		mvwprintw(keysWin, 4, 3, "NTER|RGHT");
		mvwprintw(keysWin, 5, 3, "BKSPC|LEFT");
		mvwprintw(keysWin, 6, 3, "CTRL+C|Q");
		mvwprintw(keysWin, 7, 3, "F10");
		wattroff(keysWin, A_BOLD);
		mvwprintw(keysWin, 1, 4, "|");
		mvwprintw(keysWin, 3, 5, "|");
		mvwprintw(keysWin, 4, 7, "|");
		mvwprintw(keysWin, 5, 8, "|");
		mvwprintw(keysWin, 6, 9, "|");
		wattroff(keysWin, COLOR_PAIR(6));
		wrefresh(keysWin);}
	delwin(keysWin);
	keysWin=NULL;
	refresh();
}

// Highlight and bat
void fileReader(const char* flPth){
	char modPath[255];
	char lang[]="/usr/share/Dummy/lang.lua";
	char theme[]="/usr/share/Dummy/theme.lua";
	int termCols=COLS;
	int tabSpc=(COLS >= 200) ? (COLS - 80) / 2 : 4;
	/* The variable above can be broken down as, if screen is larger than 160
	cols, subtract 80 (file width) and divide the result by 2.offset to centre
	the page, else tab width is set to 4 to avoid text wrapping */
	snprintf(modPath, sizeof(modPath), "/usr/share/Dummy/dummyfiles/%s.txt", flPth);
	int pid1=fork();
	if(pid1 == -1){
		fprintf(stderr, "⚠ fork failed ⚠\n");
		exit(EXIT_FAILURE);}
	if(pid1 == 0){
		char highlightCmd[512];
		snprintf(highlightCmd, sizeof(highlightCmd),
		    "highlight -O xterm256 -S %s -s %s -l -j3 -t3 -t %d %s", lang, theme, tabSpc, modPath);
		int pipefd[2];
		// Create a pipe
		if(pipe(pipefd) == -1){
			fprintf(stderr, "⚠ pipe failed ⚠\n");
			exit(EXIT_FAILURE);}
		int pid2=fork();
		if(pid2 == -1){
			fprintf(stderr, "⚠ fork failed ⚠\n");
			exit(EXIT_FAILURE);}
		if(pid2 == 0){
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			/* Duplicate the file descriptor onto the read (out) end of the pipe
			to be used as input, the value is stored in STDOUT_FILENO defined in
			unistd.h, its a constant integer data type */			
			close(pipefd[1]);
			execlp("sh", "sh", "-c", highlightCmd, NULL);
		}else{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			/* The corresponding write (in) end of the pipe where the file
			descriptor is copied again for use by the grandchild process, this
			process improves readbility and allows for theming */
			close(pipefd[0]);
			execlp("bat", "bat", "--style=grid,header-filename", "--file-name", modPath, NULL);}
	}else{
		int wstatus;
		waitpid(pid1, &wstatus, 0);
	}
}

// Alphabet search
void alphabetSrch(
	const char* srchChar, int* highlight, int* curSelect,
	const char* uprMenu[], const char* lwrMenu[]){
	int matchingIdx=-1; // -1 = no match, else = match
	// Upper menu matches
	for(int i=0; i < 1; i++){
		if(strncasecmp(uprMenu[i], srchChar, 1) == 0){
			matchingIdx=i;
			*curSelect=1;
			break;}}
	if(matchingIdx == -1){
		// Lower menu matches
		for(int i=0; i < MMSIZE - 1; i++){
			if(strncasecmp(lwrMenu[i], srchChar, 1) == 0){
				matchingIdx=i;
				*curSelect=2;
				break;}}}
		// Update selection
		if(matchingIdx != -1){
			*highlight=matchingIdx;
	}
}

// Elimination search
void eliminationSrch(int highlight, subMenu subMenus[]){
    char srchInput[50]="";
    int curSelect=0;
    int matchCnt=0; // current number of matched files
    srchWin=newwin(3, 17, 1, 1);
    keypad(srchWin, TRUE);
    nodelay(srchWin, TRUE);    
    while(1){
        // Search prompt
        werase(srchWin);
        wattron(srchWin, A_BOLD | COLOR_PAIR(8));
        box(srchWin, 0, 0);
        wattroff(srchWin, A_BOLD | COLOR_PAIR(8));
        wattron(srchWin, COLOR_PAIR(6));
        mvwprintw(srchWin, 1, 1, " : ");
        wattron(srchWin, A_BOLD);
        mvwprintw(srchWin, 1, 4, "%s", srchInput);
        wattroff(srchWin, A_BOLD);
        wattroff(srchWin, COLOR_PAIR(6));
        wrefresh(srchWin);
        // Redraw submenu
        werase(subWin);
        wattron(subWin, A_BOLD | COLOR_PAIR(8));
        box(subWin, 0, 0);
        wattroff(subWin, COLOR_PAIR(8));
        wattron(subWin, COLOR_PAIR(6));
        mvwprintw(subWin, 0, 16, "%s", subMenus[highlight].title);
        wattroff(subWin, A_BOLD);
		/* This code block performs a process of elimination style search on
		files in the submenu, redrawing the submenu attributes in the code above
		allows search match/es to change the highlight below */
        int matchCnt=0;
        int selectIdx=-1; // Index of files within the matching list
        for(int i=0; i < subMenus[highlight].size; i++){
            if(strcasestr(subMenus[highlight].list[i], srchInput)){
                matchCnt++;
                if(matchCnt - 1 == curSelect){
                    selectIdx = i;
                    wattron(subWin, A_BOLD);}
					const char *fullString=subMenus[highlight].list[i];
					if(subMenus[highlight].title != allh3lpMenu.title){
						const char *slashPos = strchr(fullString, '/');
						if(slashPos){
							mvwprintw(subWin, i - selectIdx + 1, 2, "%s", slashPos + 1);
						}else{
							mvwprintw(subWin, i - selectIdx + 1, 2, "%s", fullString);}
					}else{
						mvwprintw(subWin, i - selectIdx + 1, 2, "%s", fullString);}                    
                wattroff(subWin, A_BOLD);}}
        wrefresh(subWin);
		// Catch chars        
        int ch=getch();
        if(ch == ERR){
            continue;
        }else if(ch == 27){
            srchInput[0]='\0';
            curSelect=-1;
            werase(srchWin);
            wrefresh(srchWin);
            delwin(srchWin);
            srchWin=NULL;
            return;}
        switch(ch){
            // Cycle selection
            case KEY_UP:
                if(curSelect > 0){
                    curSelect--;}
                break;
            case KEY_DOWN:
                if(curSelect < matchCnt - 1){
                    curSelect++;}
                break;
            // Select file
            case KEY_ENTER:
            case KEY_RIGHT:
            case '\n':
                if (selectIdx >= 0){
                    int wstatus;
                    fileReader(subMenus[highlight].list[selectIdx]);
                    wait(&wstatus);
                    wclear(stdscr);
                    refresh();}
                break;
            // Delete char
            case KEY_BACKSPACE:
                if(strlen(srchInput) > 0){
                    srchInput[strlen(srchInput) - 1]='\0';
                }else{
                    matchCnt=0;}
                break;
            default:
                if(isprint(ch)){
                    if(strlen(srchInput) + 1 < sizeof(srchInput)){
	                	// Build the query from single chars
                        strncat(srchInput, (char*)&ch, 1);}}
                break;}
		refresh();}
    delwin(srchWin);
    srchWin=NULL;
}

// Main menu
void mainmenuScr(const char* uprMenu[], const char* lwrMenu[], subMenu subMenus[]){
	int ch=0;
	int highlight=0;
	int highlightIdx=0;
	int curSelect=1; // 1 = upper menu, 2 = lower menu
	int toggleKeys=1; // 1 = screen keys hidden, else = visible
	char srchChar[MMWDTH]="";
	while(1){
		wclear(stdscr);
		refresh();
		screenKeys(ch, &toggleKeys);
		// Draw upper menu box
		listallWin=newwin(3, MMWDTH, YCNTR - 8, XCNTR - 8);
		keypad(listallWin, TRUE);
		werase(listallWin);
		wattron(listallWin, A_BOLD | COLOR_PAIR(8));
		box(listallWin, 0, 0);
		wattroff(listallWin, A_BOLD | COLOR_PAIR(8));
		wattron(listallWin, COLOR_PAIR(6));
		for(int i=0; i < 1; i++){
			if(i == highlight && curSelect == 1){
				wattron(listallWin, A_BOLD);}
			mvwprintw(listallWin, i + 1, 2, " %s", uprMenu[i]);
			wattroff(listallWin, A_BOLD);}
		wrefresh(listallWin);
		// Draw lower menu box
		menuWin=newwin(11, MMWDTH, YCNTR - 4, XCNTR - 8);
		keypad(menuWin, TRUE);
		werase(menuWin);
		wattron(menuWin, A_BOLD | COLOR_PAIR(8));
		box(menuWin, 0, 0);
		wattroff(menuWin, A_BOLD | COLOR_PAIR(8));
		wattron(menuWin, COLOR_PAIR(6));
		for(int i=0; i < 9; i++){
			if(i == highlight && curSelect == 2){
				wattron(menuWin, A_BOLD);}
			mvwprintw(menuWin, i + 1, 2, "%s", lwrMenu[i]);
			wattroff(menuWin, A_BOLD);}
		wrefresh(menuWin);
		// Catch chars
		if(curSelect ==  1){
			ch=wgetch(listallWin);
		}else{
			ch=wgetch(menuWin);}
		// Quick search
		if(ch != ERR){
			if(isalpha(ch) && tolower(ch) != 'q'){
				echo();
				srchChar[0]=ch;
				/* The main menu only used alphabet search style, a text prompt
				isnt required for this, the selection will just jump to the
				letter index position on keystroke */
				alphabetSrch(srchChar, &highlight, &curSelect, uprMenu, lwrMenu);
				refresh();
				noecho();}}
			switch(ch){
				// Cycle selection
				case KEY_UP:
					if(curSelect == 1){
						if(highlight > 0){
							highlight--;
						}else{
							curSelect=2;
							highlight=8;}
					}else if(curSelect == 2){
						if(highlight > 0){
							highlight--;
						}else{
							curSelect=1;
							highlight=0;}}
					break;
				case KEY_DOWN:
					if(curSelect == 1){
						curSelect=2;
						highlight=0;
					}else if(curSelect == 2){
						if(highlight < 8){
							highlight++;
						}else{
							curSelect=1;
							highlight=0;}}
					break;
				// Select submenu
				case KEY_ENTER:
				case KEY_RIGHT:
				case '\n':
					if(curSelect != 1){
						highlightIdx=highlight;
						highlight += 1;
						submenuScr(highlight, subMenus);
						highlight=highlightIdx;
					}else{
						submenuScr(highlight, subMenus);
						wclear(stdscr);
						refresh();}
					break;
				// Update highlighted section
				case KEY_F(10):
			    	updateSection(highlight, subMenus);
		        	break;					
				// Quit Dummy
				case 'q':
				case 'Q':
					sigHandler(SIGINT);
					break;
				default:
					break;}
		refresh();}
	delwin(listallWin);
	listallWin=NULL;
	delwin(menuWin);
	menuWin=NULL;
}

// Sub menus
void submenuScr(int highlight, subMenu subMenus[]){
	int ch=0;
	int srchMode=0;
	int curSelect=0; // 0 = submenu
	int toggleKeys=1;
	int srchLength=0;
	char srchQuery[50];
	char* visFiles[MMSIZE];
	char srchChar[SMWDTH]="";
	while(1){
		wclear(stdscr);
		refresh();
		screenKeys(ch, &toggleKeys);
		// Draw submenu box
		subWin=newwin(SMLNTH, SMWDTH, YCNTR - 10, XCNTR - 14);
		keypad(subWin, TRUE);
		werase(subWin);
		wattron(subWin, A_BOLD | COLOR_PAIR(8));
		box(subWin, 0, 0);
		wattroff(subWin, COLOR_PAIR(8));
		wattron(subWin, COLOR_PAIR(6));
		mvwprintw(subWin, 0, 16, "%s", subMenus[highlight].title);
		wattroff(subWin, A_BOLD);
		// Visible scrolling index
		int startIdx=curSelect;
		int endIdx=curSelect + getmaxy(subWin) - 3;
		if(endIdx >= subMenus[highlight].size - 1){
			endIdx=subMenus[highlight].size - 1;
			startIdx=endIdx - getmaxy(subWin) + 3;
			if(startIdx < 0){startIdx=0;}}
				for(int i = startIdx; i <= endIdx; i++){
					if(i == curSelect){
						wattron(subWin, A_BOLD);}
					const char *fullString=subMenus[highlight].list[i];
					if(subMenus[highlight].title != allh3lpMenu.title){
						const char *slashPos = strchr(fullString, '/');
						if(slashPos){
							mvwprintw(subWin, i - startIdx + 1, 2, "%s", slashPos + 1);
						}else{
							mvwprintw(subWin, i - startIdx + 1, 2, "%s", fullString);}
					}else{
						mvwprintw(subWin, i - startIdx + 1, 2, "%s", fullString);}
					wattroff(subWin, A_BOLD);}
		/* Without this section any submenu that contains a list of n files
		exceeding the number of rows in the length of the window box will merge
		at the bottom edge of the box with the last visble entry, also this is
		where the path in the list entry gets clipped for each submenu except
		the all h3lp menu */ 
		wrefresh(subWin);
		// Catch chars
		ch=wgetch(subWin);
		switch(ch){
			// Cycle selection
			case KEY_UP:
				if(curSelect > 0){
					curSelect--;
					if(curSelect < startIdx){
						startIdx--;
						endIdx--;}
				}else{
					curSelect=subMenus[highlight].size - 1;
					startIdx=curSelect - getmaxy(subWin) + 2;
					if(startIdx < 0){startIdx=0;}
						endIdx=curSelect;}
				break;
			case KEY_DOWN:
				if(curSelect < subMenus[highlight].size - 1){
					curSelect++;
					if(curSelect > endIdx){
						startIdx++;
						endIdx++;}
				}else{
					curSelect=0;
					startIdx=0;
					endIdx=getmaxy(subWin) - 2;}
				break;
			// Text search
			case '/':
			case '?':
				eliminationSrch(highlight, subMenus);
				touchwin(subWin);
				wrefresh(subWin);
				refresh();
				break;
			// Return to main menu
			case KEY_LEFT:
			case KEY_BACKSPACE:
				delwin(subWin);
				subWin=NULL;
				touchwin(listallWin);
				touchwin(menuWin);
				refresh();
				return;
			// Select file
			case KEY_ENTER:
			case KEY_RIGHT:
			case '\n':
				int wstatus;
				fileReader(subMenus[highlight].list[curSelect]);
				wait(&wstatus);
				wclear(stdscr);
				refresh();
				break;
			// Quit Dummy
			case 'q':
			case 'Q':
				sigHandler(SIGINT);
			default:
				break;}
		refresh();}
	delwin(subWin);
	subWin=NULL;
}

void updateSection(int highlight, subMenu subMenus[]){
    // Ensure the highlight index is within bounds
    int submenuCount=10; // Adjust according to the actual count of `subMenus`
    if (highlight < 0 || highlight >= submenuCount){
        mvprintw(LINES - 2, 0, "Invalid selection. No files to open.");
        return;}
    // Get the highlighted submenu title and list
    subMenu selectedSubMenu=subMenus[highlight];
    const char *categoryName=selectedSubMenu.title;
    // Construct the paths for the three files to open
    char filePaths[3][512]; // Array for the three file paths
    snprintf(filePaths[0], sizeof(filePaths[0]), "dummyfiles/readme");
    snprintf(filePaths[1], sizeof(filePaths[1]), "dummyfiles/all_h3lp.c");
    snprintf(filePaths[2], sizeof(filePaths[2]), "dummyfiles/%s/%s.c", categoryName, categoryName);
    // Loop through the file paths and open each one with the editor
    for (int i=0; i < 3; i++){
        char command[512]; // Buffer size should be adjusted if necessary
        snprintf(command, sizeof(command), "nano '%s'", filePaths[i]);
        // Execute the command to open the file in the editor
        int result=system(command);
        if (result != 0){
            mvprintw(LINES - 2, 0, "Error opening file: %s", filePaths[i]);}}
    mvprintw(LINES - 2, 0, "Files related to category '%s' opened.", categoryName);
}
