/*
 * sleeps 20 seconds and terminates afterwards.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

void check_pid(pid_t pid) {
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid > 0)
		exit(EXIT_SUCCESS);
}

void skeleton_daemon(void) {
	int fd;
	pid_t pid;

	pid = fork();
	check_pid(pid);
	if (setsid() < 0)
		exit(EXIT_FAILURE);

	pid = fork();
	check_pid(pid);

	umask(0);
	chdir("/");
	for (fd = sysconf(_SC_OPEN_MAX); fd > 0; fd--)
		close(fd);
	openlog("c_daemon", LOG_PID, LOG_DAEMON);
}

int main(void) {
	skeleton_daemon();

	while (1) {
		syslog(LOG_NOTICE, "daemon started.");
		sleep(20);
		break;
	}

	syslog(LOG_NOTICE, "daemon terminated.");
	closelog();

	return EXIT_SUCCESS;
}
