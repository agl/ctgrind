all: libctgrind.so libctgrind.so.1

libctgrind.so:
	gcc -o libctgrind.so -shared ctgrind.c -Wall -std=c99 -fPIC -Wl,-soname,libctgrind.so.1

libctgrind.so.1: libctgrind.so
	ln -s libctgrind.so libctgrind.so.1

a.out: test.c
	gcc test.c -Wall -ggdb -L. -lctgrind
