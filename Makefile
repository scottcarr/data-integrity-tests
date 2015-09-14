CXX=~..//build/bin/clang++
SRC=test14.cpp
CFLAG= -g -fcps -flto

all: $(SRC)
	$(CXX) -g $(SRC) -o normal
	$(CXX) -g -S -emit-llvm  $(SRC) -o normal.ll
	$(CXX) $(CFLAG)  $(SRC)

clean:
	rm a.out *.ll test5 test7 test8 test9 test10 normal \
	test12 test13 test14 test15 test16 test17 test18 test19 test20 \
	test21 test22 test23 test24 test25 test26 test11 test6

sec_tests: sec_test.cpp sec_test1.cpp sec_test2.cpp
	$(CXX) $(CFLAG) sec_test.cpp -o sec_test
	$(CXX) $(CFLAG) sec_test1.cpp -o sec_test1
	$(CXX) $(CFLAG) sec_test2.cpp -o sec_test2

tests: test5.cpp test7.cpp test9.cpp test10.cpp \
	test12.cpp test13.cpp test14.cpp test15.cpp \
	test16.cpp test17.cpp test18.cpp test19.cpp \
	test21.cpp test22.cpp test23.cpp test24.cpp test25.cpp \
	test26.cpp test27.cpp test28.cpp test29.cpp test31.cpp
	$(CXX) $(CFLAG) test5.cpp -o test5
	$(CXX) $(CFLAG) test7.cpp -o test7
	$(CXX) $(CFLAG) test9.cpp -o test9
	$(CXX) $(CFLAG) test10.cpp -o test10
	$(CXX) $(CFLAG) test12.cpp -o test12
	$(CXX) $(CFLAG) test13.cpp -o test13
	$(CXX) $(CFLAG) test14.cpp -o test14
	$(CXX) $(CFLAG) test15.cpp -o test15
	$(CXX) $(CFLAG) test16.cpp -o test16
	$(CXX) $(CFLAG) test17.cpp -o test17
	$(CXX) $(CFLAG) test18.cpp -o test18
	$(CXX) $(CFLAG) test19.cpp -o test19
	$(CXX) $(CFLAG) test21.cpp -o test21
	$(CXX) $(CFLAG) test22.cpp -o test22
	$(CXX) $(CFLAG) test23.cpp -o test23
	$(CXX) $(CFLAG) test24.cpp -o test24
	$(CXX) $(CFLAG) test25.cpp -o test25
	$(CXX) $(CFLAG) test26.cpp -o test26
	$(CXX) $(CFLAG) test27.cpp -o test27
	$(CXX) $(CFLAG) test28.cpp -o test28
	$(CXX) $(CFLAG) test29.cpp -o test29
	$(CXX) $(CFLAG) test31.cpp -o test31

run-tests: tests run-tests.py
	python run-tests.py
