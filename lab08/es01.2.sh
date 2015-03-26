for i in `find $1`; do
	grep $2 -n $i /dev/null 2> /dev/null 1>> $3
done
