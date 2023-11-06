SRC := ./
OBJ := .obj/
CPP_SOURCES := $(shell find -name "*.cpp")
CPP_LINKERS :=  $(subst $(SRC), $(OBJ), $(CPP_SOURCES:.cpp=.o))

all: $(CPP_LINKERS) build

$(CPP_LINKERS): $(CPP_SOURCES)
	mkdir -p $(dir $@)
	g++ -c $(subst .obj,., $(@:.o=.cpp)) -o $@

build:
	g++ $(CPP_LINKERS)

clean:
	rm -rf .obj
