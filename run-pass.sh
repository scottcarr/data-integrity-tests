BASE=~/data-integrity/build
LIB=$BASE/lib/LLVMDataIntegrity.so
OPT=$BASE/bin/opt
$OPT -load $LIB -DataIntegrityPass < test.ll > /dev/null
#$OPT -load $LIB -DataIntegrityPass < test.ll
