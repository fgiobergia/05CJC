declare -A hash

for word in `cat $1`; do
	hash[$word]=$[${hash[$word]}+1];
done


for i in ${!hash[@]}; do
	echo $i " " ${hash[$i]};
done
