CC=~/dataconf-workspace2/how-does-lto-work/build/bin/clang
#CC=clang

#test: test.c
#	$(CC) test.c -flto -o test

#test: test.c
#	$(CC) test.c test2.c -flto -mllvm -dataconf -fsanitize=dataconf -mllvm -debug-only=DataConf -o test
#
test: test.c
	$(CC) -flto test.c test2.c -o test

clean:
	rm test *.ll
