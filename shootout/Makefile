# working benchmarks: fasta, nbody, binarytrees
CXX=~/data-integrity/build/bin/clang
SRC1=binarytrees
SRC2=fasta
SRC3=nbody
CFLAG= -g -O0 -flto
CPIFLAG = -fcps

SOFT=~/softboundcets-34/softboundcets-llvm-clang34/Release+Asserts/bin/clang
SOFTLIB=~/softboundcets-34/softboundcets-lib

all: binarytrees nbody fasta

binarytrees: $(SRC1).c
	$(CXX) $(CFLAG) $(SRC1).c -o $(SRC1)
	#$(CXX) -g -S -emit-llvm  $(SRC1).c -o normal.ll
	$(CXX) $(CFLAG) $(CPIFLAG) $(SRC1).c -o $(SRC1)_dci
	$(SOFT) $(SRC1).c -o $(SRC1)_soft -fsoftboundcets -L $(SOFTLIB) -lm -lrt

fasta: $(SRC2).c
	$(CXX) $(CFLAG) $(SRC2).c -o $(SRC2)
	#$(CXX) -g -S -emit-llvm  $(SRC2) -o normal.ll
	$(CXX) $(CFLAG) $(CPIFLAG) $(SRC2).c -o $(SRC2)_dci
	$(SOFT) $(SRC2).c -o $(SRC2)_soft -fsoftboundcets -L $(SOFTLIB) -lm -lrt

nbody: $(SRC3).c 
	$(CXX) $(CFLAG) $(SRC3).c -o $(SRC3)
	#$(CXX) -g -S -emit-llvm  $(SRC3).c -o normal.ll
	$(CXX) $(CFLAG) $(CPIFLAG) $(SRC3).c -o $(SRC3)_dci
	$(SOFT) $(SRC3).c -o $(SRC3)_soft -fsoftboundcets -L $(SOFTLIB) -lm -lrt

clean:
	rm a.out *.ll binarytrees nbody fasta binarytrees_dci nbody_dci fasta_dci nbody_soft fasta_soft binarytrees_soft
