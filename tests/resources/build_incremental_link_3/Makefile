CC_PATH:=$(shell which $(CC))
LINKER_DIR:=$(shell dirname $(CC_PATH))
LINKER=$(LINKER_DIR)/ld

all: main.exe

relocatable: kotmp/test.ko

kotmp/test.ko: test1.o test2.o
	mkdir -p $(dir $@) && $(LINKER) -r -o $@ $^

main.exe: kotmp/test.ko main.o
	$(CC) -o $@ $^ -lgcov

%.o: %.c
	$(CC) -c $< -mtune=generic -o $@

clean:
	rm -f kotmp/* *.o *.exe

