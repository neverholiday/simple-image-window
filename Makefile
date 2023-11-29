all:
	g++ main.c++ -lSDL2 -lGL -o main

clean:
	rm -rf main
