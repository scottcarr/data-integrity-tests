#CXX=~/sunblaze-ucb/build/bin/clang++
CXX=~/data-integrity/build/bin/clang++
SRC=test12.cpp

all: $(SRC)
	$(CXX) -g -flto -fcpi  $(SRC)
	#$(CXX) -S -emit-llvm  $(SRC) -o test.ll
	$(CXX) $(SRC) -o normal
	$(CXX) -S -emit-llvm  $(SRC) -o normal.ll

clean:
	rm a.out *.ll test5 test6 test7 test8 test9 test10 test11 normal

tests: test5.cpp test6.cpp test7.cpp test8.cpp test9.cpp test10.cpp test11.cpp test12.cpp
	$(CXX) -g -flto -fcpi test5.cpp -o test5
	$(CXX) -g -flto -fcpi test6.cpp -o test6
	$(CXX) -g -flto -fcpi test7.cpp -o test7
	$(CXX) -g -flto -fcpi test8.cpp -o test8
	$(CXX) -g -flto -fcpi test9.cpp -o test9
	$(CXX) -g -flto -fcpi test10.cpp -o test10
	$(CXX) -g -flto -fcpi test11.cpp -o test11
	$(CXX) -g -flto -fcpi test11.cpp -o test12

run-tests: tests run-tests.py
	python run-tests.py
