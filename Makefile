all:test
test:test.o
	g++ -o test test.o -lgtest  -lpthread
test.o:
	g++ -c test.cpp
clean:
	rm -rf test *.o
