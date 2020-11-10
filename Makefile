CC = g++

SRC := src

OBJ := obj

APP_NAME = areia

COMPILER_FLAGS = -Wall -std=c++11 -g 

INCLUDE_FLAGS = `sdl2-config --cflags` -I$(SRC)/

LINKER_FLAGS = `sdl2-config --libs`

SOURCES := $(wildcard $(SRC)/*.cpp)
LINKS := $(wildcard $(SRC)/*.h)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

all : $(OBJECTS)
	$(CC) $(COMPILER_FLAGS) $^ -o $(APP_NAME) $(LINKER_FLAGS)

$(OBJ)/%.o : $(SRC)/%.cpp 
	$(CC) $(INCLUDE_FLAGS) $(LINKER_FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)/* $(APP_NAME)