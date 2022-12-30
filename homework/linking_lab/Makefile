SRCS = static_main.c
LIBSRCS = open.c close.c put.c get.c seek.c
TARG = kvs_static
CC = gcc
OPTS = -O
LIBS = -L. -lkvs
OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a
static : $(TARG)


SSRCS = dynamic_main.c
TARGET = kvs_dynamic
SLIBSRCS = open.c close.c get.c put.c seek.c
SOBJS = $(SSRCS:.c=.o)
SLOBJS = $(SLIBSRCS:.c=.o)
OPTION = -O -fPIC
SLARS = libkvs.so
dynamic : $(TARGET)




all: static dynamic


$(TARG) : $(OBJS) $(LARS)
    $(CC) -o $(TARG) $(OBJS) $(LIBS)

$(LARS) : $(LOBJS)
    ar rs $(LARS) $(LOBJS)

%.o: %.c
    $(CC) $(OPTS) -c $< -o $@

clean:
    rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG)
    rm -f $(SOBJS) $(LOBJS) $(SLARS) $(TARGET)

$(TARGET) : $(SOBJS) $(SLARS)
     $(CC) -o $(TARGET) $(SOBJS) $(LIBS) -L -lmyLibrary -ldl

$(SLARS) : $(SLOBJS)
     $(CC) -shared -fPIC -o  $(SLARS) $(SLOBJS)
