CC=/home/carr27/dataconf-workspace2/buildShared/bin/clang

test: test.c
	$(CC) -g -O2 -mllvm -dataconf -fsanitize=dataconf test.c -o test

clean:
	rm test
