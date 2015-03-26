i=0;
flag=0;
name=$1;
while [ $flag -eq 0 ]; do
	sum=0;
	count=0;
	for f in `find $name -maxdepth $i`; do
		new=`echo $f | tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ`;
		count=$[$count+1];
		mv $f $new 2> /dev/null;
		sum=$[$sum+$?];
	done;
	if [ $sum -eq $count ]; then
		flag=1;
	fi
	if [ $i -eq 0 ]; then
		name=$new;
	fi
	i=$[$i+1];
done

