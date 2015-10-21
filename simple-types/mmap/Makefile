CC=/home/carr27/dataconf-workspace2/buildShared/bin/clang

test: test.c
	#$(CC) -v -g -mllvm -dataconf -fsanitize=dataconf -mllvm -debug-only=DataConf test.c -o test
	$(CC) -v -g -O2 -mllvm -dataconf -fsanitize=dataconf -mllvm -debug-only=DataConf -mllvm -dataconf-disable-splitstack test.c -o test
	#$(CC) -v -O2 -g test.c -o test

clean:
	rm test
