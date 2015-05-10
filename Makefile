# Project is the thing your're executable name
PROJECT=hdraw

EXEEXT=.dll

CC=i686-w64-mingw32-gcc
CCXX=i686-w64-mingw32-g++
LD=$(CCXX)
EXTRAFLAGS+= -I/usr/include/wine/windows/ -O0 -g -gstabs
LDFLAGS=src/hdraw.def -g -gstabs -shared -static-libgcc -static-libstdc++
#include common rules
include rules.mk


