


CC = gcc
CXX = g++
CFLAGS = -O3 -Wall -Wextra $(SYSCFLAGS) $(MYCFLAGS)
LDFLAGS = -Llib $(SYSLDFLAGS) $(MYLDFLAGS)
LIBS = -lMingw32 -lm $(SYSLIBS) $(MYLIBS)

AR = ar rcu
RANLIB = ranlib
RM = rm -f
UNAME = uname

SYSCFLAGS =
SYSLDFLAGS =
SYSLIBS =

MYCFLAGS =
MYLDFLAGS =
MYLIBS = -lLua -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
MYOBJS =


CMCFLAGS = 


VPATH := Window Gal Physics
OBJ_PATH = ./obj











window.o:window.c
renderer.o:renderer.c
window_widget.o:Widget/widget.c
window_label.o:Widget/label.c


