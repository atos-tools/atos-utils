
FOO=foo
FORCE=.FORCE

CFLAGS=-DFOO=$(FOO)

.DAFAULT: help

help:
	@echo "Targets, one of:"
	@echo " final_exe"
	@echo " final_ld_exe"
	@echo " final_reloc"
	@echo " final_ld_reloc"
	@echo " intermediate_reloc"
	@echo " intermediate_ld_reloc"

all:
	$(MAKE) FORCE= final_exe final_ld_exe final_reloc final_ld_reloc intermediate_reloc intermediate_ld_reloc

final_exe:
	$(MAKE) FOO=foo main.exe

final_ld_exe:
	$(MAKE) FOO=foo main_ld.exe

final_reloc:
	$(MAKE) FOO=foo main.ro

final_ld_reloc:
	$(MAKE) FOO=foo main_ld.ro

intermediate_reloc:
	$(MAKE) FOO=foo main_ro.exe

intermediate_ld_reloc:
	$(MAKE) FOO=foo main_ld_ro.exe

main.exe: main.o test.o
	$(CC) -o main.exe $^

main_ld.exe: main.o test.o
	$(LD) -o main_ld.exe $^ --defsym=printf=0 -e main

main.ro: main.o test.o
	$(CC) -nostdlib -r -o $@ $^

main_ld.ro: main.o test.o
	$(LD) -r -o $@ $^

main_ro.exe: main.ro
	$(CC) -o $@ $^

main_ld_ro.exe: main_ld.ro
	$(CC) -o $@ $^

main.o test.o: $(FORCE)

.FORCE:

clean:
	rm -f *.o *.exe *.ro

