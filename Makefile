CC:=g++
CFLAGS:=-W -Wall -Wextra -ansi -pedantic -s -O2
INCLUDE:=
LDFLAGS:=
BIN:=bin/sort
SRC:=$(wildcard src/*.cpp)
HEADERS:=$(wildcard src/*.hpp)
OBJ:=$(SRC:.cpp=.o)

build: $(BIN)

run:
	$(BIN)

$(BIN): $(OBJ)
	$(CC) -o $(BIN) $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm src/*.o && rm $(BIN)
