all: build-external build-main

build-external:
	$(MAKE) -C ./external

build-main: main.c++
	g++ main.c++ -lSDL2 -lGL -L./external/lib -lglad -I./external/include -o main

clean-external:
	$(MAKE) -C external clean

clean: clean-external
	rm -v main
