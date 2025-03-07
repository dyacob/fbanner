
CC = gcc
CFLAGS = -c
LEX = flex
PROG =  fbanner
STRIP = strip
LIBS = -leth -ll -lm  # it is critical that -leth precedes -ll
MYLIBDIR = ./lib-src
MYINCLUDE = ./include
SOURCE  = fbanner-0.16.c fonttools.c
OBJECTS = $(SOURCE:.c=.o)
LIBRARY = libeth.a
#DEPFLAGS = -DSUPPORT_DOS
#DEPFLAGS = -DSUPPORT_TEX

 
all: ${PROG}
 
${PROG}:  $(OBJECTS) $(LIBRARY)
	    $(CC) $(DEPFLAGS) $(SOURCE) -I$(MYINCLUDE) -L$(MYLIBDIR) $(LIBS) -o ${PROG}
		$(STRIP) $(PROG)
 

$(LIBRARY):
	(cd $(MYLIBDIR); make)


.c.o:
	$(CC) $(CFLAGS) -I$(MYINCLUDE) $*.c

clean:
	    rm -f $(OBJECTS); cd $(MYLIBDIR); make clean


