program: main.o thread_pool.o thread_pool.h
	$(CC) $^ -o $@ -pthread

main.o:main.c
	$(CC) $^ -o $@ -c
thread_pool.h:thread_pool.o

thread_pool.o:thread_pool.c
	$(CC) $^ -o $@ -c


clean:
	rm program