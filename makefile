connectn.out: main.o connectn.o winning.o
	gcc -g -Wall -Werror -o connectn.out main.o connectn.o winning.o
main.o: main.c connectn.h winning.h
	gcc -g -Wall -Werror -c main.c
connectn.o: connectn.c connectn.h winning.h
	gcc -g -Wall -Werror -c connectn.c
winning.o: winning.c winning.h
	gcc -g -Wall -Werror -c winning.c
clean:
	rm -fr *.o *.out
