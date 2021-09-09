CC = arm-linux-gcc
all:
	$(CC) main.c -o main -ldl -Wl,-rpath=./lib/jpeg-9/lib
test:
	$(CC) test.c -o test -L./lib -lshowjpg -L/home/gec/jpeg_arm/lib -ljpeg -Wl,-rpath=/home/gec/jpeg_arm/lib,-rpath=./lib -I./inc -ldl
clean:
	rm main test