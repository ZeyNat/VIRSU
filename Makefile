CPP=g++ --std=c++11 -Wall

all :  jouer game

game : game.o
	$(CPP) -o game game.o
game.o : game.cpp board.hpp
	$(CPP) -c game.cpp
jouer : jouer.o Teaupla.o Zeca.o Oueurj.o Streumon.o
	$(CPP) -o jouer jouer.o Teaupla.o Zeca.o Oueurj.o Streumon.o
jouer.o : jouer.cpp Teaupla.hpp Zeca.hpp Oueurj.hpp Streumon.hpp Deplacable.hpp
	$(CPP) -c jouer.cpp
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
