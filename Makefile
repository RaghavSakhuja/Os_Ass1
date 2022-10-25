all: cr clean
cr:
	Path_cat="/mnt/c/Users/acer/Downloads/Os/A1/cat"
	gcc -w -o ls ls.c
	gcc -w -0 cat cat.c
	gcc -w -o main Main.c
	./main

clean:
	rm -f ls main 