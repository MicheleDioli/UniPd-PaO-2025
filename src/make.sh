#!/bin/bash

make clean
rm -fr Makefile
rm -fr .qmake.stash
rm -fr src.pro
rm -fr src.pro.user
rm -fr src.app

qmake -project

if [[ "$OSTYPE" == "darwin"* ]]; then
    sed -i "" '8s/.*/QT += widgets/' src.pro
else
    sed -i '8s/.*/QT += widgets/' src.pro  
fi

qmake
make
