PROGRAM = little
OBJS = main.o other.o
CXXFLAGS = -g -std=c++2a

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm $(OBJS) $(PROGRAM)

run:
	./$(PROGRAM)