CC =/home/carr27/dataconf-workspace2/buildShared/bin/clang

all: test test.ll

test.ll : test.c
	$(CC) -S -emit-llvm test.c

test : test.c
	$(CC) -g test.c -mllvm -dataconf -fsanitize=dataconf -mllvm -debug-only=DataConf -o test

clean:
	rm test test.ll

