CPP=g++ --std=c++11 -Wall

all :  test


test : test.o Teaupla.o Zeca.o
	$(CPP) -o test test.o Teaupla.o Zeca.o
testTeaupla.o : test.cpp Teaupla.hpp Zeca.hpp
	$(CPP) -c test.cpp
Teaupla.o : Teaupla.cpp Teaupla.hpp Zeca.hpp
	$(CPP) -c Teaupla.cpp
Zeca.o : Zeca.cpp Zeca.hpp
	$(CPP) -c Zeca.cpp
clean :
	rm *.o
