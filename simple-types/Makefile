SRC = test1
CC = ../../build/bin/clang
OPT = ../../build/bin/opt
PASSLIB = ../../build/lib/LLVMDataConf.so
PASS = DataConf

$(SRC).ll : $(SRC).c
	clang -S -emit-llvm $(SRC).c
	$(OPT) -debug -load $(PASSLIB) -$(PASS) $(SRC).ll 

clean: 
	rm $(SRC).ll
	


