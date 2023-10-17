##
#### General
##
#### Details
• Arch: x86_64  
• Size: 900K  
• Vers: v01.01.01
#### Weblinks
• Bat: https://github.com/sharkdp/bat  
• Highlight: http://www.andre-simon.de/doku/highlight/highlight.html
#### Description
This is a curses based program designed to make managing helpfiles and cheatsheets related
to different programs easier. Its also essentially just a wrapper for highlight and bat
which are being used to read the files. To do something with max efficiency, all the
useful and important data relative to doing the thing can be gathered and studied. It
helps when gathering information on complex programs to have some easy way of organizing
and accessing the files where its stored which is what dummy provides.
##
#### Installation
##
#### Depends
• bat: Cat clone with syntax highlighting and git integration  
• highlight: Fast and flexible CLI source code highlighter  
• make: GNU utility to maintain groups of programs
#### MacOS & Linux
Open a terminal and clone this repo:
```shell
git clone 'https://github.com/c0rNCh1p/dummy.git' ||
git clone 'https://gitlab.com/c0rNCh1p/dummy.git'
```
Change to the build directory and install the program with make:
```shell
cd 'dummy'
make install
```
#### Windows
Go grab git bash if not installed 'https://git-scm.com/download/win.'
Open Git Bash and follow steps for MacOS and Linux.
#### Uninstalling
Change to the install directory and uninstall the program with make:
```shell
cd '/usr/share/dummy'
make clean
```
##
#### Usage
##
```shell
dummy
```
#### Writing Help Files
A dummy help file is included to provide an example of the suggested formatting for help
files. The 'lang.lua' and 'theme.lua' files are read by highlight and allow for the
customization of things like header keywords, recognized syntax and color schemes.
#### Adding Help Files
Every submenu has its own source file which makes the process of referencing help files a
lot easier. When a file is added, the file list in the category source file, the
'all_h3lp.c' (complete list) source file and the readme are each updated with a new entry.

The 'helpfiles/update_db.sh' script will open the relevant files for a given category
using the '$VISUAL' variable to specify a graphical text editor. The files need to be
referenced with their location eg. 'category/file'. The subdirectory preceding the file
gets clipped in the menu entry but its still needed for reference.

Files are given the '.txt' extension when named but it isnt required when updating the
source arrays. The '.txt' extension as well as the 'helpfiles/' section of the path are
being handled from within 'dummy.c'. The submenu source files also define a total count of
the files to keep track of its size.
```shell
cd 'helpfiles'
./'update_db.sh' <category>
```
##
#### Notes
##
#### No Terminal Resize
The program will crash if the terminal is resized at any point during runtime. Some
dimensions are supported by curses but they need to be set beforehand.
##
