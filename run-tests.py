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
