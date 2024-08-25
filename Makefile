all: final

final: main.o execmd.o
	gcc main.o execmd.o -o vash
	echo "vash executable"

main.o: main.c
	gcc -c main.c

execmd.o: execmd.c
	gcc -c execmd.c

clean:
	echo "Removing everyting except source files"
	rm main.o execmd.o vash