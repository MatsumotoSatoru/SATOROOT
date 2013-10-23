TARGET = show

COM    = c++
CFLAGS = -Wall
OBJS   = $(TARGET).o

all:$(TARGET)

$(TARGET):$(OBJS)
	$(COM) $(CFLAGS) -o $(TARGET) $(OBJS)
.cpp.o:
	$(CC) $(CFLAGS) -c $<
$(TARGET).o :

clean:
	rm -f *.o
