# Makefile for f2022, ecs36b
#
# g++ -std=c++14 test_GPS.cpp GPS.cpp -o test_GPS
#
# example: $ ./test_GPS 48.88 2.3

CC = g++ -std=c++14

CFLAGS = -g -I/Users/fatimashaik/Developer/vcpkg/installed/arm64-osx/include
# CFLAGS = -O3

LDFLAGS = 	-L/Users/fatimashaik/Developer/vcpkg/installed/arm64-osx/lib -ljsoncpp

# rules.
all: 	main
	@echo ""
#
#

GPS.o:		GPS.cpp GPS.h
	$(CC) -c $(CFLAGS) GPS.cpp

JvTime.o:	JvTime.cpp JvTime.h
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp Person.h
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h
	$(CC) -c $(CFLAGS) Thing.cpp

Record.o:	Record.cpp Record.h
	$(CC) -c $(CFLAGS) Record.cpp

main.o:	main.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) main.cpp

main:		GPS.o main.o Thing.o Person.o JvTime.o Record.o
	g++ -std=c++14 main.o GPS.o Thing.o Person.o JvTime.o Record.o -o main $(LDFLAGS)

clean:
	rm -f *.o *~ core main
