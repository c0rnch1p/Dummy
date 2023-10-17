#!/bin/bash

URLS=(
	"https://heather.cs.ucdavis.edu/~matloff/UnixAndC/CLanguage/Curses.pdf"
	"https://www.linux-magazine.com/Issues/2020/232/curses"
	"https://www.man7.org/linux/man-pages/man3/ncurses.3x.html"
	"https://invisible-island.net/ncurses/ncurses-intro.html"
	"https://jbwyatt.com/ncurses.html"
)

if ! command -v "$BROWSER" "/dev/null" 2>&1; then
	echo -e "#\n# export the \$BROWSER variable\n#"
elif command -v "$BROWSER" --new-window "/dev/null" 2>&1; then
	"$BROWSER" --new-window "${URLS[0]}"
	for ((i = 1; i < ${#URLS[@]}; i++)); do
		"$BROWSER" "${URLS[i]}"
	done
else
	for URL in "${URLS[@]}"; do
		"$BROWSER" "$URL"
	done
fi
