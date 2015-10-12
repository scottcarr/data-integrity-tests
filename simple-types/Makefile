BASE = ../../buildShared
SRC = test1
CC = $(BASE)/bin/clang
OPT = $(BASE)/bin/opt
PASS = DataConf
CLANG = $(BASE)/bin/clang
LLC = $(BASE)/bin/llc

a.out : test1.c
	$(CLANG) -g -mllvm -dataconf -mllvm -debug-only=DataConf -fsanitize=dataconf test1.c 



#all : a.out
#
#$(SRC).ll : $(SRC).c
#	clang -S -emit-llvm $(SRC).c
#
#$(SRC).out.ll: $(SRC).ll
#	$(OPT) -S -debug -load $(PASSLIB) -$(PASS) $(SRC).ll > $(SRC).out.ll
#
#test.ll : $(SRC).out.ll
#	cp $(SRC).ll test.ll
#
#a.out : $(SRC).out.ll 
#	clang $(SRC).out.ll $(BASE)/lib/clang/3.8.0/lib/linux/libclang_rt.safestack-x86_64.a $(BASE)/lib/clang/3.8.0/lib/linux/libclang_rt.tsan-x86_64.a -lpthread
#
##safestack.ll : $(SAFESTACK)
##	clang++ -S -std=c++11 -emit-llvm $(SAFESTACK) -I $(INC_DIR)
#
#clean: 
#	rm $(SRC).ll test.ll
#
clean: 
	rm a.out test1.ll before.ll after.ll 
	


