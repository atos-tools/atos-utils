CC_PATH:=$(shell which $(CC))
LINKER_DIR:=$(shell dirname $(CC_PATH))
LINKER=$(LINKER_DIR)/ld

all: main.exe

kotmp/test.ko: test1.o test2.o
	mkdir -p $(dir $@) && $(LINKER) -r -o $@ $^

main.exe: kotmp/test.ko main.o
	$(CC) -O1 -fno-peephole -o $@ $^

test1.o: test1.c
	$(CC) -O3 -funroll-loops -fomit-frame-pointer -c $< -o $@

%.o: %.c
	$(CC) -O0 -funroll-loops -fomit-frame-pointer -fno-inline -fno-builtin -g -c $< -o $@

clean:
	rm -f kotmp/* *.o *.exe

