CXX=g++
CXXFLAGS=-Wall -g3
LDFLAGS=-lm
# OBJECTOS=funciones.o utilitario.o
DEL=rm -fr

main: main.cpp $(OBJECTOS)
	$(CXX) $(CXXFLAGS) -o app main.cpp $(OBJECTOS) $(LDFLAGS)

clean:
	$(DEL) *.o app bin/

.PHONY: dist
dist: clean main
	mkdir -p bin
	cp -r app bin/
	