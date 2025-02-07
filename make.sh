#!/bin/bash

make clean
rm -fr Makefile
rm -fr .qmake.stash
rm -fr biblioteca.pro
rm -fr biblioteca.pro.user
rm -fr biblioteca.app

qmake -project

sed -i "" '8s/.*/QT += widgets/' biblioteca.pro

qmake
make