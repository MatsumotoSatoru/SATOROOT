TARGET = cube
COM    = c++
CFLAGS = -Wall
OBJS   = $(TARGET).o

all:$(TARGET)

$(TARGET):$(OBJS)
	$(COM) $(CFLAGS) $(TARGET).cpp -o $^
$(OBJS):$(TARGET).cpp
	$(COM) -c $<
clean:
	rm -f *.o
