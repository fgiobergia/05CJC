max=0;
len=0;
#for i in `cat $1`; do
while read i; do
	len=$[$len+1];
	if [ ${#i} -gt $max ]; then
		max=${#i};
	fi
done<$1;

echo $max
echo $len
