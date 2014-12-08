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
print "Security test 1"
p = Popen(["./sec_test"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=None)[0]
print stdout_dat

print "\n"
#if stdout_dat != expected:
#    die("sec_test", expected, stdout_dat)
#else:
#    print "sec_test passed."


# sec_test1
print "Security test 2"
p = Popen(["./sec_test1"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=None)[0]
print stdout_dat
print "\n"
#if stdout_dat != expected:

#    die("sec_test", expected, stdout_dat)
#else:
#    print "sec_test passed."

# sec_test2
print "Security test 3"
p = Popen(["./sec_test2"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=None)[0]
print stdout_dat
print "\n"
#if stdout_dat != expected:

#if stdout_dat != expected:
#    die("sec_test", expected, stdout_dat)
#else:
#    print "sec_test passed."

# sec_test3
print "Security test 4"
p = Popen(["./sec_test3"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=None)[0]
print stdout_dat
print "\n"
#if stdout_dat != expected:

#if stdout_dat != expected:
#    die("sec_test", expected, stdout_dat)
#else:
#    print "sec_test passed."

# sec_test4
print "Security test 5"
p = Popen(["./sec_test4"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=None)[0]
print stdout_dat
print "\n"
#if stdout_dat != expected:

#if stdout_dat != expected:
#    die("sec_test", expected, stdout_dat)
#else:
#    print "sec_test passed."

# sec_test5
print "Security test 6"
p = Popen(["./sec_test5"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=None)[0]
print stdout_dat
print "\n"
#if stdout_dat != expected:

#if stdout_dat != expected:
#    die("sec_test", expected, stdout_dat)
#else:
#    print "sec_test passed."

# sec_test6
print "Security test 7"
p = Popen(["./sec_test6"], stdout=PIPE, stdin=PIPE)
stdout_dat = p.communicate(input=None)[0]
print stdout_dat
print "\n"

#if stdout_dat != expected:

#if stdout_dat != expected:
#    die("sec_test", expected, stdout_dat)
#else:
#    print "sec_test passed."

