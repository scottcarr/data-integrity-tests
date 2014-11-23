CXX=~/data-integrity/build/bin/clang
SRC=nbody.c
CFLAG= -g -O0 -flto
CPIFLAG = -fcps

all: $(SRC) 
	$(CXX) $(CFLAG) $(SRC) -o normal -lm
	$(CXX) -g -S -emit-llvm  $(SRC) -o normal.ll
	$(CXX) $(CFLAG) $(CPIFLAG) $(SRC) -lm

clean:
	rm a.out *.ll
