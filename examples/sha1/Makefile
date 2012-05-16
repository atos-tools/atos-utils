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

all: sha shacmp shatest sha-shared

sha: sha.o $(OBJS)
	$(CC) -o $@ sha.o $(OBJS) $(LIBS)

shacmp: shacmp.o $(OBJS)
	$(CC) -o $@ shacmp.o $(OBJS) $(LIBS)

shatest: shatest.o $(OBJS)
	$(CC) -o $@ shatest.o $(OBJS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

%_s.o: %.cpp
	$(CC) $(CFLAGS) -fpic -o $@ $<

sha.so: sha1_s.o
	$(CC) -o $@ -shared sha1_s.o $(LIBS)

sha-shared: sha.o sha.so
	$(CC) -o $@ sha.o ./sha.so $(LIBS)

clean:
	$(RM) *.o *.so sha shacmp shatest sha-shared
