from subprocess import call
import glob

# none of these tests should compile under DC
CC = "/home/carr27/data-integrity/build/bin/clang++"
CFLAG = "-flto -fcps -g -O0 -I ."
dirname = "./expect-fail-tests"

#negative_tests = ["expect-fail-tests/test7.cpp"]

def die(test): 
    print test + " failed (compiled when it shouldn't have"
    exit()

def compile(test):
    arg = [CC]
    arg.extend(CFLAG.split())
    arg.append(test)
    return call(arg)


def run():
    tests = glob.glob(dirname + "/*.cpp")
    for test in tests:
        if compile(test) == 0:
            die(test)
    else:
        print test + " passed."

run()
