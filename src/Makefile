.PHONY: all calc

FLAGS=-std=c++17
GTEST=-lgtest -lpthread -lgtest_main
SOURCE=model/*.cc controller/*.cc model/matrix/*.cc
HEADERS=model/*.h
TESTS=tests/*_test.cc
EXECUTABLE=model.out
UNAME:=$(shell uname -s) 

ifeq ($(UNAME),Linux ) 
	GXX=g++
	OPEN_CMD=xdg-open # команда для открытия отчета
	ADD_LIB=-lm -lrt -lpthread #-lsubunit # дополнительные библиотеки
	BREW=/home/darkwolf/homebrew
	SYSTEM=-D OS_LINUX
endif
ifeq ($(UNAME),Darwin ) 
	GXX= g++
	OPEN_CMD=open
	ADD_LIB=
	BREW=${HOME}/homebrew
	SYSTEM=-D OS_MAC
endif

all: clean test

style:
	clang-format -style=google -i $(TESTS) $(SOURCE) $(HEADERS) 3DViewer_2/*cpp 3DViewer_2/*.h

test: clean
	$(GXX) $(SYSTEM) $(SOURCE) $(FLAGS) $(TESTS) $(ADD_LIB) -o $(EXECUTABLE) $(GTEST)
	./$(EXECUTABLE)

mem: test
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --tool=memcheck ./$(EXECUTABLE)

build:
	-mkdir build
	-cd build && qmake ../3DViewer_2/3DViewer_2.pro
	-cd build && make

clean:
	rm -rf *.a $(EXECUTABLE) *.o
	rm -rf html latex build dist

install: uninstall build
	mv build/3DViewer_2.app ~/Desktop 

uninstall:
	rm -rf build 
	rm -rf ~/Desktop/3DViewer_2.app

dvi:
	doxygen DviConf
	${OPEN_CMD} html/index.html

dist: build
	mkdir dist
	cp -R build/3DViewer_2.app dist
	cd dist && tar -cvzf 3DViewer_2.tgz 3DViewer_2.app
	rm -rf dist/3DViewer_2.app
