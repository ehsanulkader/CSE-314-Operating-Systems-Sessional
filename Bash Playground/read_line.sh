 [[ $# -ne 1 ]] && exit 1
 
 pat=$1
 
 while IFS= read -r line; do
 	if echo "$line" | grep -q "$1"; then
 		echo "$line"
 	fi
 	# if grep -q "cin" <(echo "$line"); then
 	#	echo "$line"
 	#di
 done
