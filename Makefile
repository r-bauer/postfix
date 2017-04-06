# makefile for infix calculator using generic stack 

IDIR=./include
SDIR=./src
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=./lib

LIBS=-lm

_DEPS=	stackapp.h \
	stackdrv.h \
	stackgen.h \
	main.h 

DEPS=$(addprefix $(IDIR)/, $(_DEPS))

_OBJ=	main.o \
	stackdrv.o \
	stackapp.o \
	stackgen.o

#OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))
OBJ=$(addprefix $(ODIR)/, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

postfix: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: $(OBJ)

$(OBJ): | $(ODIR)

$(ODIR):
	mkdir -p $(ODIR)

.PHONY:	clean

clean: 
	rm -fr $(ODIR) postfix* *~ $(IDIR)/*~ $(SDIR)/*~

