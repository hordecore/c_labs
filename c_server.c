#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <syslog.h>
#include <arpa/inet.h>

#define PORT 1488

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

void do_listen(void) {
	int sock, listener;
	struct sockaddr_in addr, c_addr;
	char buf[1024];
	char c_addr_s[INET_ADDRSTRLEN];
	int bytes_read;
	socklen_t len = sizeof(c_addr);

	listener = socket(AF_INET, SOCK_STREAM, 0);

	if(listener < 0) {
		perror("socket");
		exit(1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("bind");
		exit(2);
	}

	listen(listener, 1);

	while(1) {
		sock = accept(listener, (struct sockaddr *)&c_addr, &len);
		if(sock < 0) {
			perror("accept");
			exit(3);
		}

		inet_ntop(AF_INET, &(c_addr.sin_addr), c_addr_s, INET_ADDRSTRLEN);
#ifdef DAEMONIZE
		syslog(LOG_NOTICE, "someone connected from %s:%u\n", c_addr_s, ntohs(c_addr.sin_port));
#else
		printf("%s:%u\n", c_addr_s, ntohs(c_addr.sin_port));
#endif /* lol */

		while(1) {
			bytes_read = recv(sock, buf, 1024, 0);
			if(bytes_read <= 0)
				break;
			send(sock, buf, bytes_read, 0);
		}

		close(sock);
	}
}

int main(void) {
#ifdef DAEMONIZE
	skeleton_daemon();
#endif
	syslog(LOG_NOTICE, "%s", "daemon started.");
	do_listen();
	syslog(LOG_NOTICE, "daemon terminated.");
	closelog();
	return EXIT_SUCCESS;
}
