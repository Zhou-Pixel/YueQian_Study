CC = arm-linux-gcc
all:
	$(CC) showjpeg.c jpg.c -o showjpeg -L/home/gec/jpeg_arm/lib -ljpeg -Wl,-rpath=./lib/jpeg-9/lib
clean:
	rm showjpeg