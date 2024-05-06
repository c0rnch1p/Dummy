##
#### General
##
#### Details
• Arch: x86_64  
• Size: 900K  
• Vers: v02.01.01
#### Weblinks
• Bat: https://github.com/sharkdp/bat  
• Highlight: http://www.andre-simon.de/doku/highlight/highlight.html  
• Nano: https://www.nano-editor.org
#### Description
This is a curses based program designed to make managing helpfiles and cheatsheets related
to different programs easier. Its also essentially just a wrapper for highlight and bat
which are being used to read the files. To do something with max efficiency, all the
useful and important data relative to doing the thing can be gathered and studied. When
gathering information on complex programs it helps to have some easy way of organizing it,
which is what Dummy aims to provide.
##
#### Installation
##
#### Depends
• bat: Cat clone with syntax highlighting and git integration  
• highlight: Fast and flexible CLI source code highlighter  
• make: GNU utility to maintain groups of programs  
• nano: Pico editor clone with enhancements
#### MacOS & Linux
Open a terminal, go to the user data directory and clone this repo:
```shell
cd "$HOME/.local/share" &&
git clone 'https://github.com/c0rNCh1p/dummy.git' ||
git clone 'https://gitlab.com/c0rNCh1p/dummy.git'
```
Change to the build directory and install the program with the script:
```shell
cd 'Dummy' && ./'install.sh'
```
Binaries are made in "$HOME/.local/bin" and '/bin', then the folder is copied to
'/usr/share'.
#### Windows
Go grab git bash if not installed 'https://git-scm.com/download/win'.
Open Git Bash and follow steps for MacOS and Linux.
#### Uninstalling
Change to the system install directory and uninstall the program with make:
```shell
cd '/usr/share/Dummy' && make clean
```
##
#### Usage
##
```shell
dummy
```
#### Writing Dummy Files
An example dummy file is included to provide an idea of the suggested formatting for dummy
files. The 'lang.lua' and 'theme.lua' files are read by highlight and allow for the
customization of things like header keywords, recognized syntax and color schemes.
#### Adding Dummy Files
Dummy files get sorted into one of ten categories which each have their own folder in the
'dummyfiles' directory. Theyre just text files that are going to be referenced later on after
the program is properly updated by being installed with the new input.

Each section has its own '.c' source file which makes the process of referencing dummy
files a lot cleaner than if it didnt. When a file is added, the section source file, another
source file containing the full list as well as the readme are each updated with a new entry.

To update the database, press 'F10' while the main menu section being updated is
focused. This will open the files which need to be updated as root with nano for the
program and for that section, returning to the main menu when nano is closed.

For the changes to take effect, the 'install.sh' script needs to be executed again, but it
will be the one in the system data directory '/usr/share/Dummy/install.sh' rather than the
one used before to install the program to the system in the user data directory:
```shell
cd '/usr/share/Dummy' && ./'install.sh'
```
The same process is followed when any changes are made to the system source code. Dummy
files are given the '.txt' extension when named but it can be omitted when updating the
arrays. The '.txt' extension as well as the 'dummyfiles/' section of the path are being
handled from within 'dummy.c'.
##
#### Notes
##
#### No Terminal Resize
The program will crash if the terminal is resized at any point during runtime. Some
dimensions are supported by curses but they need to be set beforehand. Files that
are only around 50 lines wont open at terminal sizes smaller than the default.
##
