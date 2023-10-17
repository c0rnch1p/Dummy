#!/bin/bash

compInit(){
    compMain(){
        local COMPREPLY
        COMPREPLY=$(compgen -W "$2" -- "${COMP_WORDS[COMP_CWORD]}")
    }
    complete -F compMain read
}

rstrInit(){
    compInit
    while true; do
        test -n "$SUB" && echo -e "# enter $SUB"
        read -rep "▸ " STR
        if [ -z "$STR" ]; then
            echo -e "⚐ no input provided ⚐"
        elif [ ! -d "$STR" ]; then
            echo -e "⚠ invalid category ⚠"
        else break
        fi
    done
}

! test -n "$GRAPHICAL" &&\
echo -e "⚐ export the \$GRAPHICAL variable (gui editor) ⚐" && exit 0

if [[ $# -eq 1 && -d "$1" ]]; then
    ARG="${1%/}"
    "$GRAPHICAL" "readme" "all_h3lp.c" "$ARG/$ARG.c"
elif [ $# -eq 0 ]; then
    SUB="category"
    rstrInit
    STR="${STR%/}"
    "$GRAPHICAL" "readme" "all_h3lp.c" "$STR/$STR.c"
fi


unset ARG
unset SUB
