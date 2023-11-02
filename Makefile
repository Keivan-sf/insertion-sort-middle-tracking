CPP_SOURCES := $(wildcard *.cpp)
CPP_LINKERS :=  $(CPP_SOURCES:.cpp=.o)

all: $(CPP_LINKERS) build

$(CPP_LINKERS): $(CPP_SOURCES)
	g++ -c $^ 

build:
	g++ $(CPP_LINKERS)

clean:
	rm -rf *.o
