#########################################
# why isn't main.o included in .depend? #
#########################################

SRCS=main.cc graph_gen_alg.cc chunglu_gen.cc erdosrenyi_gen.cc kernels.cc util_fns.cc
OBJECTS=$(SRCS:.cc=.o)

CXX = g++

CXXFLAGS = -g -Wall -Wno-sign-compare -std=c++0x -O3

all: graph_embedding

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $<

graph_embedding: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM -MT $^ > ./.depend

clean:
	$(RM) *.o 

include .depend
