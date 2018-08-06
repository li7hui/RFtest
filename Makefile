all:test

CPP_FILES	:= $(wildcard *.cpp)
OBJ_FILES	:= $(addprefix ./,$(notdir $(CPP_FILES:.cpp=.o)))

FILES	:= ./%.cpp

./%.o: $(FILES)
	g++ -c -o $@ $<

test: $(OBJ_FILES)
	g++ -o $@ $^ -lgtest -lpthread

clean:
	rm -rf test *.o
