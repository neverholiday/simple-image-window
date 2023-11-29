all: lib/libglad.so

libglad.so: glad.o
	g++ -shared -lGL -lGLEW -o libglad.so glad.o

glad.o: glad.c
	g++ -c -fPIC -I../include glad.c

clean:
	rm -v glad.o libglad.so