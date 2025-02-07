
CC = gcc
CFLAGS = -Wall -c #-g
PROG =  fbanner
STRIP = strip
LIBS = -leth -lm
MYINCLUDE = ./include
SOURCE  = fbanner-0.18.c fonttools.c
OBJECTS = $(SOURCE:.c=.o)
LOCAL_LIBETHDIR =
LOCAL_INCLUDE =

 
all: ${PROG}
 
${PROG}:  $(OBJECTS) $(LIBRARY)
	    $(CC) $(DEPFLAGS) $(SOURCE) -I$(MYINCLUDE)  $(LIBS) -o ${PROG}
		$(STRIP) $(PROG)
 
local:

.c.o:
	$(CC) $(CFLAGS) -I$(MYINCLUDE) $*.c

clean:
	    rm -f $(OBJECTS); cd $(MYLIBDIR); make clean


