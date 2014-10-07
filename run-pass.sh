BASE=~/data-integrity/build
LIB=$BASE/lib/LLVMDataConfidentiality.so
OPT=$BASE/bin/opt
$OPT -load $LIB -DataConfidentialityPass normal.ll 
