#CXX=~/sunblaze-ucb/build/bin/clang++
CXX=~/data-integrity/build/bin/clang++
SRC=test7.cpp

all: $(SRC)
	$(CXX) -flto -fcfi=fptr-full  $(SRC)
	#$(CXX) -g test.cpp

test: all
	./a.out
	
bitcode: $(SRC)
	#$(CXX) -S -emit-llvm -flto -fcfi=fptr-full $(SRC) -o test-fcfi.ll
	$(CXX) -S -emit-llvm  $(SRC) -o test.ll
	# the bitcodes were always the same  because FCFI doesn't run until LTO

clean:
	rm a.out *.ll
