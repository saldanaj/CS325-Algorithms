
CXX = g++
CXXFLAGS = -std=c++0x

main: main.o iohelper.o city.o edge.o christofides.o 2Opt.o 
	${CXX} ${CXXFLAGS} main.o iohelper.o city.o edge.o christofides.o 2Opt.o -o tsp

main.o: main.cpp
	${CXX} -c main.cpp

iohelper.o: iohelper.hpp iohelper.cpp
	${CXX} -c iohelper.cpp

city.o: city.hpp city.cpp
	${CXX} -c city.cpp

edge.o: edge.hpp edge.cpp
	${CXX} -c edge.cpp

christofides.o: christofides.hpp christofides.cpp
	${CXX} -c christofides.cpp

2Opt.o: 2Opt.hpp 2Opt.cpp
	${CXX} -c 2Opt.cpp

clean:
	rm *o tsp