all:input_scanf.o kernel_list.o 


input_scanf.o:input_scanf.c
	$(CC) $^ -o $@ -c -I../include


kernel_list.o:kernel_list.c
	$(CC) $^ -o $@ -c -I../include

clean:
	rm *.o
