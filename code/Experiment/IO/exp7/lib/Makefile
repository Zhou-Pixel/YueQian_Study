CC = arm-linux-gcc
all:
	$(CC) jpg.c -o jpg.o -c -fPIC -I../inc 
	$(CC) showjpeg.c -o showjpeg.o -c -fPIC -I../inc 
	$(CC) showbmp.c -o showbmp.o -c -fPIC -I../inc
	$(CC) -shared -fPIC -o libshowjpg.so jpg.o showjpeg.o -L/home/gec/jpeg_arm/lib -ljpeg
	$(CC) -shared -fPIC -o libshowbmp.so showbmp.o
clean:
	rm *.o *.so