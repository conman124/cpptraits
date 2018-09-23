objects = main.o catdog.o

traits : $(objects)
	g++ -o traits $(objects)

catdog.o : catdog.hpp
main.o : catdog.hpp

.PHONY : clean
clean :
	rm traits $(objects)