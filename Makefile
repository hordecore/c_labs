all:
	gcc -Wall -pedantic -o c_daemon c_daemon.c
clean:
	rm -f a.out c_daemon
install:
	cp -p c_daemon /usr/local/bin/c_daemon
	cp -p c_daemon.sh /etc/rc.d/init.d/c_daemon
	chkconfig --add c_daemon
	chkconfig --level 345 c_daemon on
