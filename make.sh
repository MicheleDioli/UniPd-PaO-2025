#!/bin/bash

make clean
rm -fr Makefile
rm -fr .qmake.stash
rm -fr biblioteca.pro
rm -fr biblioteca.pro.user
rm -fr biblioteca.app

qmake -project

if [[ "$OSTYPE" == "darwin"* ]]; then
    sed -i "" '8s/.*/QT += widgets/' biblioteca.pro
else
    sed -i '8s/.*/QT += widgets/' biblioteca.pro  
fi

qmake
make
