

all: main.exe

.libs/libtest.so: test.o
	mkdir -p $(dir $@) && $(CC) -shared -o $@ $^ 

main.exe: .libs/libtest.so main.o
	$(CC) -o $@ main.o -Wl,--rpath,.libs -L.libs -ltest

install: all
	$(MAKE) libtest.so

libtest.so: test.o
	$(CC) -shared -o $@ $^ 

%.o: %.c
	$(CC) -fpic -c $< -o $@

clean:
	rm -f .libs/* *.o *.so

