# don't invoke this program directly
# instead use make like:
# make run-tests
from subprocess import Popen, PIPE

def die(test, expected, actual): 
    print "Test " + test + " failed"
    print "expected: " + expected
    print "actual: " + actual
    exit()


# sec_test
in_data = "42\n9999\n1234\n4321\n555\n"
expected = "42\n9999\n1234\n4321\n555\n"
p = Popen(["./sec_test"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=in_data)[0]

if stdout_dat != expected:
    die("sec_test", expected, stdout_dat)
else:
    print "sec_test passed."
