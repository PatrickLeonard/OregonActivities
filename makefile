CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

ODIR = obj

DEPS = main.h Link.h LinkList.h Linear.h Doubly.h Circular.h Activity.h 

_OBJ = main.o Link.o LinkList.o Linear.o Doubly.o Circular.o Activity.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(LFLAGS)

statholder: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o *~ statholder