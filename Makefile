#CXX=~/sunblaze-ucb/build/bin/clang++
CXX=~/data-integrity/build/bin/clang++
SRC=test4.cpp

all: $(SRC)
	$(CXX) -flto -fcfi=fptr-full  $(SRC)
	#$(CXX) -g test.cpp

test: all
	./a.out
	
bitcode: test.cpp
	$(CXX) -S -emit-llvm -flto -fcfi=fptr-full $(SRC) -o test-fcfi.ll
	$(CXX) -S -emit-llvm  $(SRC) -o test.ll

clean:
	rm a.out *.ll
