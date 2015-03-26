BEGIN {
	dd = ARGV[1];
	mm = ARGV[2];
	yyyy = ARGV[3];
	ARGV[1]="";ARGV[2]="";ARGV[3]="";
	while ("cal "mm" "yyyy | getline var) {
		if (var ~ /Su/) {
			$0 = var;
		}
		m=match(var,"\\<"dd"\\>");
		if (m) {
			print $int((m+2)/3);
		}
	}
}
