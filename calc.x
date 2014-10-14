/*
 * mc.x: remote calculator access protocol
 */

/* structure definitions*/
struct mypair {
	int arg1;
	int arg2;
};

/* program definition, no union or typdef definitions needed */
program MCPROG { /* could manage multiple servers */
	version MCVERS {
		int ADD(mypair) = 1;
		int SUBTRACT(mypair) = 2;
		int MULTIPLE(mypair) = 3;
		int DIVIDE(mypair) = 4;
	} = 1;
} = 0x20000002;  /* program number ranges established by ONC */
