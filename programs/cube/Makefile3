TARGET = main
TARGET2= sub
HEAD   = head

COM    = c++
CFLAGS = -Wall
OBJS   = $(TARGET).o $(TARGET2).o

all:$(TARGET)

$(TARGET):$(OBJS)
	$(COM) $(CFLAGS) -o $(TARGET) $(OBJS)
.cpp.o:
	$(CC) $(CFLAGS) -c $<
$(TARGET).o : $(HEAD).h  # main.cppの依存ファイルは head.h
$(TARGET2).o: $(HEAD).h # main.cppの依存ファイルは head.h

clean:
	rm -f *.o