INC = -I./inc
MYLIB = -L./lib
JPEGLIB = -L/home/gec/jpeg_arm/lib -ljpeg -Wl,-rpath=./lib/jpeg-9/lib
CC = arm-linux-gcc
OBJ = showimage testclick
all:$(OBJ)
	$(MAKE) -C ./lib

showimage:showimage.c
	$(CC) $^ -o $@ $(INC) $(MYLIB) -lshowimage  $(JPEGLIB),-rpath=./lib/mylib

testclick:testclick.c
	$(CC) $  $^ -o $@ $(INC) $(MYLIB) -lclick
clean:
	rm $(OBJ)