all:test
test:test.o vlan.o ipconfig.o sendpacket.o
	g++ -o test test.o vlan.o ipconfig.o sendpacket.o -lgtest  -lpthread
test.o:
	g++ -c test.cpp
vlan.o:
	g++ -c vlan.cpp
ipconfig.o:
	g++ -c ipconfig.cpp
sendpacket.o:
	g++ -c sendpacket.cpp

clean:
	rm -rf test *.o
