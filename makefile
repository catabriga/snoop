CC = gcc
CXX = g++ -std=c++0x
INCLUDES =
CFLAGS = -c -Wall $(INCLUDES)
LDFLAGS =
LIBS = -lwiringPi
SOURCES =	main.c
HEADERS =
HEADERS =
OBJECTS = $(patsubst %.cpp,%.o,$(patsubst %.c,%.o,$(SOURCES)))
EXECUTABLE = snoop

all: $(SOURCES) $(EXECUTABLE)
debug: CC += -g
debug: CXX += -g
debug: $(SOURCES) $(EXECUTABLE)
release: CC += -O3
release: CXX += -O3
release: $(SOURCES) $(EXECUTABLE)
prof: CC += -pg
prof: CXX += -pg
prof: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

%.o : %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) $< -o $@

%.o : %.c
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)
