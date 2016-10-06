all:
	g++ src/*.cpp -o runnable -lsfml-graphics -lsfml-window -lsfml-system \
		-Wall -Werror
	./runnable
