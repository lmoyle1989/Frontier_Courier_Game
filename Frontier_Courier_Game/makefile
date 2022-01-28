#Lucas Moyle
#12/10/2019
#CS162 Fall 2019
#Makefile for Final Project - Space Game

output: MainFinal.o Menu.o ClassSpace.o ClassPlayer.o ClassMap.o ClassForest.o ClassMountain.o ClassDesert.o
	g++ -std=c++0x MainFinal.o Menu.o ClassSpace.o ClassPlayer.o ClassMap.o ClassForest.o ClassMountain.o ClassDesert.o -o main

Menu.o: Menu.cpp Menu.hpp
	g++ -c -std=c++0x Menu.cpp 

MainFinal.o: MainFinal.cpp
	g++ -c -std=c++0x MainFinal.cpp

ClassSpace.o: ClassSpace.hpp ClassSpace.cpp
	g++ -c -std=c++0x ClassSpace.cpp

ClassPlayer.o: ClassPlayer.hpp ClassPlayer.cpp
	g++ -c -std=c++0x ClassPlayer.cpp

ClassMap.o: ClassMap.hpp ClassMap.cpp
	g++ -c -std=c++0x ClassMap.cpp

ClassForest.o: ClassForest.hpp ClassForest.cpp
	g++ -c -std=c++0x ClassForest.cpp

ClassMountain.o: ClassMountain.hpp ClassMountain.cpp
	g++ -c -std=c++0x ClassMountain.cpp

ClassDesert.o: ClassDesert.cpp ClassDesert.hpp
	g++ -c -std=c++0x ClassDesert.cpp

clean:
	rm *.o main

