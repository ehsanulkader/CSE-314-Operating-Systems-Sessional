#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Usage $0 filename1 filename2 ..."
else
	for filename in $*; do
		if ! [[ -e $filename ]]; then
            echo "$filename doesn't exist"
        elif [[ -d $filename ]]; then
            echo "$filename is not a regular file"
        elif ! [[ -x $filename ]]; then
            echo $(ls -l $filename)
        else
            echo "$filename is currently executable."
            echo $(ls -l $filename)
            echo "$filename's executable permission is now changing."
            chmod a-x $filename
            echo $(ls -l $filename)
            echo "$filename is currently not executable."
        fi
	done
fi
