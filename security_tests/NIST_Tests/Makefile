CXX=../../../build/bin/clang++

#all:	clean obo-bad setup_protect

original: clean obo-bad setup_orig

protect: clean obo-protect setup_protect

clean:	
	rm -rf *-bad /tmp/foo

obo-bad: call_fb_realpath.c realpath-bad.c
	gcc -o obo-bad call_fb_realpath.c realpath-bad.c

obo-protect: call_fb_realpath.c realpath-bad.c
	$(CXX) -f -flto -fcps call_fb_realpath.c realpath-bad.c -o obo-protect 

setup_orig: 
	mkdir -p /tmp/foo/bar/foo/bar/foo/bar/foo/bar ; \
	touch /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefghi ; \
	ln -s /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefghi /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefgh ; \
	./obo-bad /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefgh

setup_protect: 
	mkdir -p /tmp/foo/bar/foo/bar/foo/bar/foo/bar ; \
	touch /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefghi ; \
	ln -s /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefghi /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefgh ; \
	./obo-protect /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefgh

