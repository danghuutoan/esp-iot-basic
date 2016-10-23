CC=gcc
CFLAGS = -g 
# uncomment this for SunOS
# LIBS = -lsocket -lnsl

all: udp-send

udp-send: udp-send.o 
	$(CC) -o udp-send udp-send.o $(LIBS)

udp-send.o: udp-send.c port.h

clean:
	rm -f udp-send udp-send.o 
