CPP=g++ --std=c++11 -Wall

all :  test


test : test.o Teaupla.o Zeca.o Oueurj.o
	$(CPP) -o test test.o Teaupla.o Zeca.o Oueurj.o
testTeaupla.o : test.cpp Teaupla.hpp Zeca.hpp Oueurj.hpp
	$(CPP) -c test.cpp
Teaupla.o : Teaupla.cpp Teaupla.hpp Zeca.hpp Oueurj.hpp
	$(CPP) -c Teaupla.cpp
Zeca.o : Zeca.cpp Zeca.hpp
	$(CPP) -c Zeca.cpp
Oueurj.o : Oueurj.cpp Oueurj.hpp
	$(CPP) -c Oueurj.cpp
clean :
	rm *.o
