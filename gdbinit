break llvm::PassManager::run
set $MYLIB = "~/data-integrity/build/lib/LLVMDataIntegrity.so"
run -load ~/data-integrity/build/lib/LLVMDataIntegrity.so -DataIntegrityPass test.ll
