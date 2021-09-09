INC = -I../inc
JPEGLIB = -L/home/gec/jpeg_arm/lib -ljpeg -Wl,-rpath=./lib/jpeg-9/lib
IMAGEOBJ = jpg.o showjpeg.o showbmp.o showimage.o
CLICKOBJ = click.o
CC = arm-linux-gcc

all:libshowimage.so libclick.so

libshowimage.so:$(IMAGEOBJ)
	$(CC) -shared -fPIC -o $@ $^ $(JPEGLIB)

jpg.o:jpg.c
	$(CC) $^ -o $@ -c $(INC) -fPIC
showjpeg.o:showjpeg.c
	$(CC) $^ -o $@ -c $(INC) -fPIC
showbmp.o:showbmp.c
	$(CC) $^ -o $@ -c $(INC) -fPIC
showimage.o:showimage.c
	$(CC) $^ -o $@ -c $(INC) -fPIC




# all:
# 	$(CC) jpg.c -o jpg.o -c -I../inc -fPIC 
# 	$(CC) showjpeg.c -o showjpeg.o -c -I../inc -fPIC 
# 	$(CC) showbmp.c -o showbmp.o -c -I../inc -fPIC
# 	$(CC) showpicture.c -o showpicture.o  -c -I../inc -fPIC 
# 	$(CC) -shared -fPIC -o libshowimage.so jpg.o showjpeg.o showbmp.o showpicture.o -L/home/gec/jpeg_arm/lib -ljpeg -Wl,-rpath=./lib/jpeg-9/lib
libclick.so:click.o
	$(CC) -shared -fPIC -o $@  $^

click.o:click.c
	$(CC) $^ -o $@ -c -fPIC $(INC)

clean:
	rm *.o *.so