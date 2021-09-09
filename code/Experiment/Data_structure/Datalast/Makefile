OBJ = main.o input_scanf.o kernel_list.o
main: $(OBJ)
	$(CC) ./main/main.o ./src/input_scanf.o ./src/kernel_list.o -o program

main.o:
	$(MAKE) -C ./main

input_scanf.o kernel_list.o:
	$(MAKE) -C ./src


clean:
	$(MAKE) -C ./src clean
	$(MAKE) -C ./main clean
	rm *.o program