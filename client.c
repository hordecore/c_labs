/*
 * sleeps 20 seconds and terminates afterwards.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <syslog.h>

void poke(int ip, int port) {
	printf("Trying to poke %d:%d\n", ip, port);
}

int main(void) {
	int ip = 0;
	int port = 3310;
	poke(ip, port);
	return EXIT_SUCCESS;
}
