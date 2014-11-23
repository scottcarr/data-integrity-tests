CXX=~/data-integrity/build/bin/clang
SRC=nbody.c
CFLAG= -g -O0 -fcps -flto

nbody: nbody.c
	$(CXX) -g $(SRC) -o normal -lm
	$(CXX) -g -S -emit-llvm  $(SRC) -o normal.ll
	$(CXX) $(CFLAG)  $(SRC) -lm

clean:
	rm a.out *.ll
