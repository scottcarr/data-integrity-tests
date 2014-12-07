CXX=../../build/bin/clang++

all: sec_tests run-tests

clean:
	rm a.ll sec_test*

sec_tests: code/sec_test.cpp code/sec_test1.cpp code/sec_test2.cpp code/sec_test3.cpp \
	code/sec_test4.cpp code/sec_test5.cpp code/sec_test6.cpp
	$(CXX) -g -flto -fcps code/sec_test.cpp -o sec_test
	$(CXX) -g -flto -fcps code/sec_test1.cpp -o sec_test1
	$(CXX) -g -flto -fcps code/sec_test2.cpp -o sec_test2
	$(CXX) -g -flto -fcps code/sec_test3.cpp -o sec_test3
	$(CXX) -g -flto -fcps code/sec_test4.cpp -o sec_test4
	$(CXX) -g -flto -fcps code/sec_test5.cpp -o sec_test5
	$(CXX) -g -flto -fcps code/sec_test6.cpp -o sec_test6

run-tests: run-tests.py
	python run-tests.py
