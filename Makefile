MAIN = main
MAINOBJ = main.o google_v8.o knipp.o libreoffice.o mktime.o
GCC = gcc

main: $(MAINOBJ)
	$(GCC) -o $(MAIN) $(MAINOBJ)

cmp2mktime: mktime_offset.c cmp2mktime.c
	gcc mktime_offset.c cmp2mktime.c -o cmp2mktime

$(MAIN).o: $(MAIN).c
	$(GCC) -c $<

%.o: %.c
	$(GCC) -c -O3 $<

clean:
	rm $(MAINOBJ) $(MAIN)

objdump: $(MAINOBJ)
	objdump -h --section=.text --section=.rodata $(MAINOBJ)

