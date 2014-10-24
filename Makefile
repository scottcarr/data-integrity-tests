#CXX=~/sunblaze-ucb/build/bin/clang++
CXX=~/LBS_Project/build/bin/clang++
SRC=sec_test2.cpp

all: $(SRC)
	$(CXX) $(SRC) -o normal
	$(CXX) -S -emit-llvm  $(SRC) -o normal.ll
	$(CXX) -g -flto -fcfi  $(SRC)

clean:
	rm a.out *.ll normal
	#rm a.out *.ll test5 test6 test7 test8 test9 test10 test11 normal

tests: sec_test.cpp sec_test1.cpp sec_test2.cpp

#test5.cpp test6.cpp test7.cpp test8.cpp test9.cpp test10.cpp \
	test11.cpp test12.cpp test13.cpp test14.cpp test15.cpp sec_test.cpp \
	sec_test1.cpp
	#$(CXX) -g -flto -fcfi test5.cpp -o test5
	#$(CXX) -g -flto -fcfi test6.cpp -o test6
	#$(CXX) -g -flto -fcfi test7.cpp -o test7
	#$(CXX) -g -flto -fcfi test8.cpp -o test8
	#$(CXX) -g -flto -fcfi test9.cpp -o test9
	#$(CXX) -g -flto -fcfi test10.cpp -o test10
	#$(CXX) -g -flto -fcfi test11.cpp -o test11
	#$(CXX) -g -flto -fcfi test12.cpp -o test12
	#$(CXX) -g -flto -fcfi test13.cpp -o test13
	#$(CXX) -g -flto -fcfi test14.cpp -o test14
	#$(CXX) -g -flto -fcfi test15.cpp -o test15
	$(CXX) -g -flto -fcfi sec_test.cpp -o sec_test
	$(CXX) -g -flto -fcfi sec_test1.cpp -o sec_test1
	$(CXX) -g -flto -fcfi sec_test2.cpp -o sec_test2
run-tests: tests run-tests.py
	python run-tests.py
