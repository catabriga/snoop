CC = gcc
CXX = g++ -std=c++0x
INCLUDES =
CFLAGS = -c -Wall -DUSE_WEBSOCKET -DLINUX $(INCLUDES)
LDFLAGS =
LIBS = -lm -lpthread -lrt -ldl 
SOURCES = main.cpp WebInterface.cpp SnoopRobot.cpp civetweb/civetweb.c civetweb/CivetServer.cpp
HEADERS = MotorController.h WebInterface.h SnoopRobot.h civetweb/civetweb.h civetweb/CivetServer.cpp

UNAME_P := $(shell uname -p)
ifeq ($(UNAME_P),x86_64)    
	SOURCES += MotorControllerNopi.cpp
	HEADERS += MotorControllerNopi.h
else
	SOURCES += MotorControllerWiringpi.cpp
	HEADERS += MotorControllerWiringpi.h
	LIBS += -lwiringPi		
endif

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

ifeq ($(UNAME_P),x86_64)    
%.o : %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) $< -o $@
endif

clean:
	rm -f *.o */*.o $(EXECUTABLE)
