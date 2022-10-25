all: cr clean
cr:
	gcc -w -o ls ls.c
	gcc -w -o rm rm.c
	gcc -w -o cat cat.c
	gcc -w -o date date.c
	gcc -w -o mkdir mkdir.c
	gcc -w -o main Main.c
	./main

clean:
	rm -f ls main cat date rm mkdir