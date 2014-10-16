struct mypair {
	int arg1;
	int arg2;
};

program MCPROG {
	version MCVERS {
		int ADD(mypair) = 1;
		int SUBTRACT(mypair) = 2;
		int MULTIPLE(mypair) = 3;
		int DIVIDE(mypair) = 4;
	} = 1;
} = 0x20000002;
