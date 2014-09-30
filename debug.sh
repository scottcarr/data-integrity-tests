BASE=~/data-integrity/build
LIB=$BASE/lib/LLVMDataIntegrity.so
OPT=$BASE/bin/opt

#gdb -ex=run --args $OPT -load $LIB -DataIntegrityPass test.ll 
gdb $OPT -x gdbinit
