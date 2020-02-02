MAIN = main
OBJ = main.o google_v8.o knipp.o libreoffice.o mktime.o

main: $(OBJ)
	gcc -pg -o $(MAIN) $(OBJ)

%.o: %.c
	gcc -pg -c -O3 $<

clean:
	rm $(OBJ) $(MAIN)