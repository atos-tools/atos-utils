#
#  Makefile
#  
#  Copyright (C) 1998, 2009
#  Paul E. Jones <paulej@packetizer.com>
#  All Rights Reserved.
#
#  Copyright (C) STMicroelectronics International NV
#  Christophe Guillon <christophe.guillon@st.com>
#  Added support for building shared lib
#  Added archive generation for testing archives
#
#############################################################################
#  $Id: Makefile 12 2009-06-22 19:34:25Z paulej $
#############################################################################
#
#  Description:
#	This is a makefile for UNIX to build the programs sha, shacmp, and
#	shatest
#
#

CC	= g++

CFLAGS	= -c -O2 -Wall -D_FILE_OFFSET_BITS=64

LIBS	=

OBJS	= sha1.o
LIBSHA1 = libsha1.a

all: sha shacmp shatest 

libsha1.a: $(OBJS)
	ar cr $@ $(OBJS)

sha: sha.o $(LIBSHA1)
	$(CC) $(LDFLAGS) -o $@ sha.o -L. -lsha1 $(LIBS)

shacmp: shacmp.o $(LIBSHA1)
	$(CC) $(LDFLAGS) -o $@ shacmp.o -L. -lsha1 $(LIBS)

shatest: shatest.o $(LIBSHA1)
	$(CC) $(LDFLAGS) -o $@ shatest.o -L. -lsha1 $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

%_s.o: %.cpp
	$(CC) $(CFLAGS) -fpic -o $@ $<

sha.so: sha1_s.o
	$(CC) -o $@ -shared sha1_s.o $(LIBS)

sha-shared: sha.o sha.so
	$(CC) -o $@ sha.o ./sha.so $(LIBS)

clean:
	$(RM) *.o *.so *.a sha shacmp shatest sha-shared
