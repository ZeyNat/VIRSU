CPP=g++ --std=c++11 -Wall

all :  test game

game : game.o
	$(CPP) -o game game.o
game.o : game.cpp board.hpp
	$(CPP) -c game.cpp
test : test.o Teaupla.o Zeca.o Oueurj.o Streumon.o
	$(CPP) -o test test.o Teaupla.o Zeca.o Oueurj.o Streumon.o
test.o : test.cpp Teaupla.hpp Zeca.hpp Oueurj.hpp Streumon.hpp Deplacable.hpp
	$(CPP) -c test.cpp
Teaupla.o : Teaupla.cpp Teaupla.hpp Zeca.hpp Oueurj.hpp Streumon.hpp Deplacable.hpp
	$(CPP) -c Teaupla.cpp
Zeca.o : Zeca.cpp Zeca.hpp
	$(CPP) -c Zeca.cpp
Oueurj.o : Oueurj.cpp Oueurj.hpp Deplacable.hpp
	$(CPP) -c Oueurj.cpp
Streumon.o : Streumon.cpp Streumon.hpp Deplacable.hpp
	$(CPP) -c Streumon.cpp
clean :
	rm *.o
