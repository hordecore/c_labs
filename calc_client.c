/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <string.h>
#include "calc.h"

void mcprog_1(char *host) {
	CLIENT *clnt;
	double *result;
	mypair  args;
	char o[2];
	printf("Write expression, like <arg1> <operand> <arg2>, for example '3 + 4'\n");
	scanf("%lf %s %lf", &(args.arg1), o, &(args.arg2));


//	printf("+%lf -%lf *%lf /%lf\n", strcmp(o, "+"), strcmp(o, "-"), strcmp(o, "*"), strcmp(o, "/"));

	clnt = clnt_create (host, MCPROG, MCVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit(1);
	}

//	printf("o = %s\n", o);
	if (strcmp(o, "+") == 0) {
		result = add_1(&args, clnt);
	} else if (strcmp(o,"-") == 0) {
		result = subtract_1(&args, clnt);
	} else if (strcmp(o,"*") == 0) {
		result = multiple_1(&args, clnt);
	} else if (strcmp(o,"/") == 0) {
		result = divide_1(&args, clnt);
	} else {
		printf("Error, operation '%s' not defined\n", o);
		exit(15);
	}

	if (result == (double *) NULL)
		clnt_perror (clnt, "call failed");

	printf("%lf %s %lf = %lf\n", (args.arg1), o, (args.arg2), *result);

	clnt_destroy (clnt);
}

int main (int argc, char *argv[]) {
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	mcprog_1 (host);
	exit (0);
}
