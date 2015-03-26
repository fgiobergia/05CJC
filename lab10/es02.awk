BEGIN {
	pid=ARGV[1];
	ARGV[1]="";
}

$4 == pid {
	print $2"\t"$NF;
}
