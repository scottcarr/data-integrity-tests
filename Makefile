#CXX=~/sunblaze-ucb/build/bin/clang++
CXX=~/data-integrity/build/bin/clang++
SRC=test17.cpp

all: $(SRC)
	$(CXX) $(SRC) -o normal
	$(CXX) -S -emit-llvm  $(SRC) -o normal.ll
	$(CXX) -g -flto -fcpi  $(SRC)

clean:
	rm a.out *.ll test5 test6 test7 test8 test9 test10 test11 normal

tests: test5.cpp test6.cpp test7.cpp test8.cpp test9.cpp test10.cpp \
	test11.cpp test12.cpp test13.cpp test14.cpp test15.cpp
	$(CXX) -g -flto -fcpi test5.cpp -o test5
	$(CXX) -g -flto -fcpi test6.cpp -o test6
	$(CXX) -g -flto -fcpi test7.cpp -o test7
	$(CXX) -g -flto -fcpi test8.cpp -o test8
	$(CXX) -g -flto -fcpi test9.cpp -o test9
	$(CXX) -g -flto -fcpi test10.cpp -o test10
	$(CXX) -g -flto -fcpi test11.cpp -o test11
	$(CXX) -g -flto -fcpi test12.cpp -o test12
	$(CXX) -g -flto -fcpi test13.cpp -o test13
	$(CXX) -g -flto -fcpi test14.cpp -o test14
	$(CXX) -g -flto -fcpi test15.cpp -o test15

run-tests: tests run-tests.py
	python run-tests.py
