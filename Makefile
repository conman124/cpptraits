CXXFLAGS = -std=c++11

objects = main.o catdog.o

traits : $(objects)
	g++ -o traits $(objects)

catdog.o : catdog.hpp cat.hpp dog.hpp traits.hpp
main.o : catdog.hpp cat.hpp dog.hpp

.PHONY : clean
clean :
	rm traits $(objects)