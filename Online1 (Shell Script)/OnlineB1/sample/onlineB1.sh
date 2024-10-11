#!/bin/bash
path=$pwd
tree() {
    for file in *; do
        if [[ -d $file ]]; then
            echo "$1|--$file"
            cd "$file"
            tree "$1|  "
            cd ..
        elif [[ "${file##*.}" == "zip" ]]; then
            unzip "$file"
            rm "$file"
        else
            echo "$1|--$file"
        fi
 
    done
}
str=""
tree $str