CC=gcc
output_DIR=../bin/
net_DIR=../networking/

main: test.o server.o connection.o
	$(CC) test.o server.o connection.o -o $(output_DIR)server
	make clean

test.o: $(net_DIR)test.c
	$(CC) -c $(net_DIR)test.c

server.o: $(net_DIR)server.c
	$(CC) -c $(net_DIR)server.c

connection.o: $(net_DIR)connection.c
	$(CC) -c $(net_DIR)connection.c

clean:
	rm *.o
