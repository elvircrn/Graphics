CC = g++

CFLAGS = -g -DGL_GLEXT_PROTOTYPES
INCFLAGS = -I./glm-0.9.7.1 -I./include/ -I/usr/X11R6/include -I/sw/include \
		-I/usr/sww/include -I/usr/sww/pkg/Mesa/include -IUCSD/
LDFLAGS = -L./lib/nix -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib \
		-L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lGLEW -lglut -lGLU -lGL -lX11 -lfreeimage

RM = /bin/rm -f

run:
	./transforms

all: transforms

transforms: main.o shaders.o Transform.o Geometry.o shaders.h Transform.h Geometry.h grader.o UCSD/grader.h
	$(CC) $(CFLAGS) -o transforms main.o shaders.o Transform.o Geometry.o grader.o $(INCFLAGS) $(LDFLAGS)  -no-pie
main.o: main.cpp shaders.h Geometry.h Transform.h UCSD/grader.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c main.cpp
shaders.o: shaders.cpp shaders.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c shaders.cpp
Transform.o: Transform.cpp Transform.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c Transform.cpp  
grader.o: UCSD/grader.cpp UCSD/grader.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c UCSD/grader.cpp
Geometry.o: Geometry.cpp Geometry.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c Geometry.cpp
clean: 
	$(RM) *.o transforms *.png
