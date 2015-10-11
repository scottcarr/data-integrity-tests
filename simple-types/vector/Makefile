CC = ~/dataconf-workspace2/buildShared/bin/clang

all: test.out test.dc.out test.S test.dc.S works broken

#test.out: test.ll
#	$(CC) test.ll -o test.out

test.ll: test.c
	$(CC) -O2 -S -emit-llvm test.c

test.dc.out: test.c
	$(CC) -g -O2 -mllvm -dataconf -fsanitize=dataconf -mllvm -dataconf-disable-splitstack test.c -o test.dc.out

test.out: test.c
	$(CC) -g -O2 test.c -o test.out

test.dc.S: test.dc.out
	objdump -D test.dc.out > test.dc.S

test.S: test.out
	objdump -D test.out > test.S

works: works.ll
	$(CC) works.ll -o works

broken: broken.ll
	$(CC) broken.ll -o broken

broken.ll: test.dc.out
	cp test.c_after.ll broken.ll

works.ll: test.dc.out
	cp test.c_before.ll works.ll

clean:
	rm test.ll test.out test.dc.out test.dc.S test.S *.ll
