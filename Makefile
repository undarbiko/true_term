CXX      = $(shell fltk-config --cxx)
DEBUG    = -g
CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) -I.
LDFLAGS  = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK     = $(CXX)
STATIC   = -static

EXECUTABLE	= main
LIBRARIES	=
BIN		    = bin
SRC		    = src
SOURCES     = src/FunnyLogger/FunnyLogger.cpp \
              src/main.cpp
INCLUDE	    = -Isrc/FunnyLogger
LIB		    = lib

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SOURCES)
	$(CXX) $(STATIC) $(CXXFLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) $(LDSTATIC)

clean:
	-rm $(BIN)/*
