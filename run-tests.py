# don't invoke this program directly
# instead use make like:
# make run-tests
from subprocess import Popen, PIPE

def die(test, expected, actual): 
    print "Test " + test + " failed"
    print "expected: " + expected
    print "actual: " + actual
    exit()

# test 5
in_data = "5\n"
expected = "5\n"
p = Popen(["./test5"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if expected != stdout_dat:
    die("test5", expected, stdout_dat)
else:
    print "test 5 passed."

# test 6
in_data = "5.5\n"
expected = "5.5\n"
p = Popen(["./test6"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if expected != stdout_dat:
    die("test6", expected, stdout_dat)
else:
    print "test 6 passed."


# test 7
in_data = "3\n2\n1\n"
expected = "3\n2\n1\n"
p = Popen(["./test7"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if expected != stdout_dat:
    die("test7", expected, stdout_dat)
else:
    print "test 7 passed."

# test 8
in_data = "2\n"
expected = "2\n"
p = Popen(["./test8"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if expected != stdout_dat:
    die("test8", expected, stdout_dat)
else:
    print "test 8 passed."

# test 9
in_data = "2\n27\n33\n"
expected = "2\n27\n33\n"
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

# test 11
in_data = "42\n"
expected = "42\n"
p = Popen(["./test11"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if expected != stdout_dat:
    die("test11", expected, stdout_dat)
else:
    print "test 11 passed."

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

# test 15
in_data = "42\n9999\n1234\n4321\n555\n"
expected = "42\n9999\n1234\n4321\n555\n"
p = Popen(["./test15"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("test15", expected, stdout_dat)
else:
    print "test 15 passed."

# test 17
in_data = "a\nb\nc\n"
expected = "a\nb\nc\n"
p = Popen(["./test17"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("test17", expected, stdout_dat)
else:
    print "test 17 passed."

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

# sec_test
in_data = "42\n9999\n1234\n4321\n555\n"
expected = "42\n9999\n1234\n4321\n555\n"
p = Popen(["./sec_test"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("sec_test", expected, stdout_dat)
else:
    print "sec_test passed."
