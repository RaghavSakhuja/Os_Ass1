all: cr clean
cr:
	gcc -w -o ls ls.c
	gcc -w -o main Main.c
	./main