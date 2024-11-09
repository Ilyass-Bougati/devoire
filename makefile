all:
	gcc -o entiers entiers.c
	gcc -o reels reels.c

clean:
	rm reels
	rm entiers
