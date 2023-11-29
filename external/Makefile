all: lib/libglad.so

lib/libglad.so: lib/glad.o
	g++ -shared -lGL -lGLEW -o lib/libglad.so lib/glad.o

lib/glad.o: src/glad.c
	g++ -c -fPIC -I./include -o lib/glad.o src/glad.c

clean:
	rm -v lib/glad.o lib/libglad.so