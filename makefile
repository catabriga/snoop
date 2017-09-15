CC = gcc
CXX = g++ -std=c++0x
INCLUDES =
CFLAGS = -c -Wall -DUSE_WEBSOCKET -DLINUX $(INCLUDES)
LDFLAGS =
LIBS = -lm -lpthread -lrt -ldl -lwiringPi
SOURCES = main.cpp MotorControllerWiringpi.cpp WebInterface.cpp civetweb/civetweb.c civetweb/CivetServer.cpp
HEADERS = MotorController.h MotorControllerWiringpi.h WebInterface.h civetweb/civetweb.h civetweb/CivetServer.cpp
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
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o */*.o $(EXECUTABLE)
