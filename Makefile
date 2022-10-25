all: cr clean
cr:
	gcc -w -o ls ls.c
	gcc -w -o cat cat.c
	gcc -w -o main Main.c
	./main

clean:
	rm -f ls main cat