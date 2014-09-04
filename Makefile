#CXX=~/sunblaze-ucb/build/bin/clang++
CXX=~/data-integrity/debug/bin/clang++

all: test.cpp
	$(CXX) -flto -fcfi=fptr-full test.cpp
	#$(CXX) -g test.cpp

test: all
	./a.out
	
bitcode: test.cpp
	$(CXX) -S -emit-llvm -flto -fcfi=fptr-full test.cpp -o test-fcfi.ll
	$(CXX) -S -emit-llvm test.cpp -o test.ll
