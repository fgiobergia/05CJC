$2 ~ /R\+*/ {
	v[$4] = $NF;
}

END {
	l=length(v);
	for (j=0;j<l;j++) {
		max=0;
		for (i in v) {
			if (i+0>max+0) {
				max=i;
			}
		}
		print max"\t"v[max];
		delete v[max];
	}
}
