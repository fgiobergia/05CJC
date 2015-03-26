if [[ "$1" =~ ^[0-9]+$ ]]; then
	ps -el | awk -f es02.awk $1
fi
