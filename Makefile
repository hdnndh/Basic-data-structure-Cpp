.PHONY:clean

time:
	@chmod 755 .
	@g++ -std=c++11 timing.cpp pointerqueue.cpp pointerlist.cpp loctree.cpp lcrstree.cpp arraylist.cpp arraystack.cpp pointerstack.cpp -o timing.o
	@./timing.o

pointerlist:
	@chmod 755 .
	@g++ -std=c++11 plisttest.cpp pointerlist.cpp -o ptest.o
	@./ptest.o

loctree:
	@chmod 755 .
	@g++ -std=c++11 loctreetest.cpp pointerlist.cpp pointerqueue.cpp lcrstree.cpp loctree.cpp -o locttest.o
	@./locttest.o

lcrstree:
	@chmod 755 .
	@g++ -std=c++11 lcrstreetest.cpp pointerlist.cpp pointerqueue.cpp loctree.cpp lcrstree.cpp -o lcrstest.o
	@./lcrstest.o

mergelists:
	@chmod 755 .
	@g++ -std=c++11 mergelist.cpp pointerlist.cpp arraylist.cpp -o mlist.o
	@./mlist.o

concatlist:
	@chmod 755 .
	@g++ -std=c++11 concatlist.cpp pointerlist.cpp arraylist.cpp -o clist.o
	@./clist.o

levelorder:
	@chmod 755 .
	@g++ -std=c++11 levelorder.cpp pointerlist.cpp pointerqueue.cpp loctree.cpp lcrstree.cpp -o lvorder.o
	@./lvorder.o

arith:
	@chmod 755 .
	@g++ -std=c++11 arith.cpp pointerstack.cpp loctree.cpp lcrstree.cpp pointerlist.cpp pointerqueue.cpp -o arith.o
	@./arith.o

arraylist:
	@chmod 755 .
	@g++ -std=c++11 alisttest.cpp arraylist.cpp -o atest.o
	@./atest.o

pointerqueue:
	@chmod 755 .
	@g++ -std=c++11 pqtest.cpp pointerqueue.cpp -o pqtest.o
	@./pqtest.o

arraystack:
	@chmod 755 .
	@g++ -std=c++11 astacktest.cpp arraystack.cpp -o astest.o
	@./astest.o

travconv:
	@chmod 755 .
	@g++ -std=c++11 travconv.cpp loctree.cpp lcrstree.cpp pointerlist.cpp pointerqueue.cpp -o travconv.o
	@./travconv.o


clean:
	@\rm -f *.o
