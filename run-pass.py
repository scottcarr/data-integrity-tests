#!/usr/bin/python
import subprocess
import sys
import os
BASE="/home/carr27/data-integrity/build"
LIB= BASE + "/lib/LLVMDataConfidentiality.so"
OPT= BASE + "/bin/opt"
subprocess.call([OPT, "-load", LIB,  "-DataConfidentialityPass", sys.argv[1]])
