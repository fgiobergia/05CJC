for i in `seq 1 5`; do
	ps -e -o cmd | grep "^$1$" > /dev/null
	if [ $? -eq 1 ]; then
		exit
	fi
	sleep 1
done
killall $1
