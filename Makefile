all:
	gcc -o c_daemon c_daemon.c
clean:
	rm -f a.out c_daemon
