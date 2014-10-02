#CXX=~/sunblaze-ucb/build/bin/clang++
CXX=~/data-integrity/build/bin/clang++
SRC=test9.cpp

all: $(SRC)
	$(CXX) -flto -fcfi=fptr-full  $(SRC)
	$(CXX) -S -emit-llvm  $(SRC) -o test.ll
	$(CXX) $(SRC) -o normal
	$(CXX) -S -emit-llvm  $(SRC) -o normal.ll

clean:
	rm a.out *.ll
