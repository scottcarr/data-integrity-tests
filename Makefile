#CXX=~/sunblaze-ucb/build/bin/clang++
CXX=~/data-integrity/build/bin/clang++
SRC=test8.cpp

all: $(SRC)
	$(CXX) -flto -fcfi=fptr-full  $(SRC)
	$(CXX) -S -emit-llvm  $(SRC) -o test.ll

clean:
	rm a.out *.ll
