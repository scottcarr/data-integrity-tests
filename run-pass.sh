BASE=~/data-integrity/build
LIB=$BASE/lib/LLVMDataIntegrity.so
OPT=$BASE/bin/opt
#$OPT -default-data-layout="" -targetlibinfo -basicaa -datalayout -load $LIB -DataIntegrityPass < test.ll > /dev/null
#$OPT -targetlibinfo -basicaa -datalayout -load $LIB -DataIntegrityPass < test.ll > /dev/null
$OPT -load $LIB -DataIntegrityPass < test.ll > /dev/null
#$OPT -load $LIB -DataIntegrityPass < test-fcfi.ll > /dev/null
#$OPT -load $LIB -DataIntegrityPass < test.ll
