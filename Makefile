assign2 : assign2.o function.o
	g++ -o assign2 -g assign2.o function.o

assign2.o : assign2.cc
	g++ -c -Wall -Werror assign2.cc

function.o : function.cc
	g++ -c -Wall -Werror function.cc

clean :
	-rm assign2 *.o
