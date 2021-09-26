CC = gcc

all: gtkgis

gtkgis: gtkgis.c
	$(CC) -o gtkgis gtkgis.c `pkg-config --libs --cflags gtk4`

#-mwindows

clean:
	rm -f gtkgis
