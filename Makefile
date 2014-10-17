CC_OPTS=-Wall -Wextra -Werror -pedantic
all:
	gcc $(CC_OPTS) -o c_server c_server.c
daemon:
	gcc $(CC_OPTS) -DDAEMONIZE -o c_server c_server.c
clean:
	rm -f c_daemon a.out client c_server
install:
	cp -p c_server /usr/local/bin/server
	cp -p c_server.sh /etc/rc.d/init.d/c_server
	chkconfig --add c_server
	chkconfig --level 345 c_server on
