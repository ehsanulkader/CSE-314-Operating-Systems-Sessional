#!/bin/bash
max_score=100
max_id=5
# if [[ $# -eq 2 ]]; then
#     max_score=$1
#    	max_id=$2
# elif [[ $# -eq 1 ]]; then
# 	max_score=$1
# fi
[[ $# -eq 2 ]] && {
	max_score=$1
	max_id=$2
} || {
	[[ $# -eq 1 ]] && {
		max_score=$1
	}
}
echo student_id,score > output.csv

for ((i=1;i<=$max_id;i++)); do
	ogfile=Submissions/180512$i/180512$i.sh
	score=0
	if [[ -f $ogfile ]]; then
		bash $ogfile > original.txt
		diff_count=$(diff -w original.txt AcceptedOutput.txt | grep -e "<" -e ">" | wc -l)
		score=$(( $max_score - $diff_count * 5 ))
		if (($score < 0)); then
			score=0
		fi 
		cat $ogfile > original.txt
		# for otherfile in Submissions/180512[1-$max_id]/180512[1-$max_id].sh; do
		for ((j=1;j<=$max_id;j++));	do
			otherfile=Submissions/180512$j/180512$j.sh
			if [[ -f $otherfile ]] && ! [[ $otherfile = $ogfile ]]; then
				cat $otherfile > other.txt
				diff_count=$(diff -Z -B original.txt other.txt | grep -e "<" -e ">" | wc -l)
				if [[ $diff_count -eq 0 ]]; then
					score=$((-$score ))
					break
				fi
			fi
		done
		rm original.txt other.txt
	fi
	echo 180512$i,$score >> output.csv
done
