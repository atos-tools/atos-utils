
FOO=foo
TARGET=main.exe

CFLAGS=-DFOO=$(FOO)

all:
	$(MAKE) main.exe
	$(MAKE) TARGET=main1.exe FOO=bar main1.exe 

$(TARGET): main.o test.o
	$(CC) -o $@ $^

main.o test.o: .FORCE

.FORCE:

clean:
	rm -f *.o *.exe

