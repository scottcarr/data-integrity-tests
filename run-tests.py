# don't invoke this program directly
# instead use make like:
# make run-tests
from subprocess import Popen, PIPE
import NegativeTests

def die(test, expected, actual): 
    print "Test " + test + " failed"
    print "expected: " + expected
    print "actual: " + actual
    exit()

NegativeTests.run()

# test 5
in_data = "5"
expected = "5\n"
p = Popen(["./test5"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if expected != stdout_dat:
    die("test5", expected, stdout_dat)
else:
    print "test 5 passed."

# test 7
in_data = "321"
expected = "3\n2\n1\n"
p = Popen(["./test7"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if expected != stdout_dat:
    die("test7", expected, stdout_dat)
else:
    print "test 7 passed."

# test 9
in_data = "abc"
expected = "abc\n"
p = Popen(["./test9"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if expected != stdout_dat:
    die("test9", expected, stdout_dat)
else:
    print "test 9 passed."

# test 10
in_data = "2\n27\n33\n"
expected = "should never get here"
p = Popen(["./test10"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat.find(expected) != -1:
    print "Test 10 failed !!"
    print 'we should have never seen "{0}"'.format(expected)
    print "because an out-of-bounds read came before that"
    exit()
else:
    print "test 10 passed."

# test 12
in_data = "42\n9999\n1234\n4321\n"
expected = "should never get here"
p = Popen(["./test12"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat.find(expected) != -1:
    print "Test 12 failed !!"
    print 'we should have never seen "{0}"'.format(expected)
    print "because an out-of-bounds store came before that"
    exit()
else:
    print "test 12 passed."

# test 13
in_data = "42\n9999\n1234\n4321\n1\n"
expected = "should never get here"
p = Popen(["./test13"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat.find(expected) != -1:
    print "Test 13 failed !!"
    print 'we should have never seen "{0}"'.format(expected)
    print "because an out-of-bounds store came before that"
    exit()
else:
    print "test 13 passed."

# test 15
in_data = "42\n9999\n1234\n4321\n555\n"
expected = "42\n9999\n1234\n4321\n555\n"
p = Popen(["./test15"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("test15", expected, stdout_dat)
else:
    print "test 15 passed."

# this test is failing because it is coercing 
# the stores into a memset
# test 17
#in_data = "a\nb\nc\n"
#expected = "a\nb\nc\n"
#p = Popen(["./test17"], stdout=PIPE, stdin=PIPE)
#stdout_dat = p.communicate(input=in_data)[0]
#
#if stdout_dat != expected:
#    die("test17", expected, stdout_dat)
#else:
#    print "test 17 passed."

# test 18
in_data = "a\nb\nc\n"
expected = "a\nb\nc\n"
p = Popen(["./test18"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("test18", expected, stdout_dat)
else:
    print "test 18 passed."

# test 19
in_data = "a\nb\nc\n"
expected = "a\nb\nc\n"
p = Popen(["./test19"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("test19", expected, stdout_dat)
else:
    print "test 19 passed."

# test 20
in_data = "a\nb\nc\n"
expected = "a\nb\nc\n"
p = Popen(["./test20"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("test20", expected, stdout_dat)
else:
    print "test 20 passed."

# test 21
expected = "c\nc\nc\n"
p = Popen(["./test21"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate()[0]

if stdout_dat != expected:
    die("test21", expected, stdout_dat)
else:
    print "test 21 passed."

# test 22
in_data = "a\nb\nc\n"
expected = "a\nb\nc\n"
p = Popen(["./test22"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("test22", expected, stdout_dat)
else:
    print "test 22 passed."

# this was an old style test
# no we only protect structs
# test 23 
#in_data = "2\n27\n33\n999999\n"
#expected = "should never get here"
#p = Popen(["./test23"], stdout=PIPE, stdin=PIPE)
#stdout_dat = p.communicate(input=in_data)[0]
#
#if stdout_dat.find(expected) != -1:
#    print "Test 23 failed !!"
#    print 'we should have never seen "{0}"'.format(expected)
#    print "because an out-of-bounds read came before that"
#    exit()
#else:
#    print "test 23 passed."
    
# i'm pretty sure this test will always fail without alias
# analysis because the memset gets converted to a single store
# (of one int) which is not the protected type
# test 24 
#expected = "should never get here"
#p = Popen(["./test24"], stdout=PIPE, stdin=PIPE)
#stdout_dat = p.communicate()[0]
#
#if stdout_dat.find(expected) != -1:
#    print "Test 24 failed !!"
#    print 'we should have never seen "{0}"'.format(expected)
#    print "because an out-of-bounds read came before that"
#    exit()
#else:
#    print "test 24 passed."

# i'm pretty sure this test will always fail without alias
# analysis because the memcpy gets converted to a single store
# (of one int) which is not the protected type
# test 25 
#in_data = "2\n27\n999999\n"
#expected = "should never get here"
#p = Popen(["./test25"], stdout=PIPE, stdin=PIPE)
#stdout_dat = p.communicate(in_data)[0]
#
#if stdout_dat.find(expected) != -1:
#    print "Test 25 failed !!"
#    print 'we should have never seen "{0}"'.format(expected)
#    print "because an out-of-bounds read came before that"
#    exit()
#else:
#    print "test 25 passed."

# test 26
in_data = "a\nb\nc\n"
expected = "a\nb\nc\n"
p = Popen(["./test26"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("test26", expected, stdout_dat)
else:
    print "test 26 passed."

# test 27 
expected = "should never get here"
p = Popen(["./test27"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate()[0]

if stdout_dat.find(expected) != -1:
    print "Test 27 failed !!"
    print 'we should have never seen "{0}"'.format(expected)
    print "because an out-of-bounds read came before that"
    exit()
else:
    print "test 27 passed."

# test 27 
expected = "should never get here"
p = Popen(["./test27"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate()[0]

if stdout_dat.find(expected) != -1:
    print "Test 27 failed !!"
    print 'we should have never seen "{0}"'.format(expected)
    print "because an out-of-bounds read came before that"
    exit()
else:
    print "test 27 passed."

# test 28 
in_data = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"
expected = "should never get here"
p = Popen(["./test28"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(in_data)[0]

if stdout_dat.find(expected) != -1:
    print "Test 28 failed !!"
    print 'we should have never seen "{0}"'.format(expected)
    print "because an out-of-bounds read came before that"
    exit()
else:
    print "test 28 passed."

# test 29 
in_data = "helloworld!\n"
expected = "helloworld!\nhelloworld!\n"
p = Popen(["./test29"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(in_data)[0]

if stdout_dat != expected:
    die("test29", expected, stdout_dat)
else:
    print "test 29 passed."

# test 31a
in_data = "123456789\n"
expected = "123456789\n123456789\n123456789\n"
p = Popen(["./test31"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(in_data)[0]

if stdout_dat != expected:
    die("test31a", expected, stdout_dat)
else:
    print "test 31a passed."

# test 31b
in_data = "1234567890\n"
expected = "1234567890\n1234567890\n1234567890\n"
p = Popen(["./test31"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(in_data)[0]

if stdout_dat == expected:
    print "Test 29 failed !!"
    print 'we should have never seen "{0}"'.format(expected)
    print "because an out-of-bounds write came before that"
else:
    print "test 31b passed."
# sec_test
#in_data = "42\n9999\n1234\n4321\n555\n"
#expected = "42\n9999\n1234\n4321\n555\n"
#p = Popen(["./sec_test"], stdout=PIPE, stdin=PIPE)
#stdout_dat = p.communicate(input=in_data)[0]
#
#if stdout_dat != expected:
#    die("sec_test", expected, stdout_dat)
#else:
#    print "sec_test passed."
