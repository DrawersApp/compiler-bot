#!/bin/bash
set -x -e
cd lib
git submodule init
git submodule update
cd restclient-cpp
./autogen.sh
./configure
sudo make install
direc=`pwd`
cd /tmp
sudo apt-get install wget
wget http://camaya.net/download/gloox-1.0.14.tar.bz2
sudo apt-get install libgloox-dev
make
make install
cd $direc
cd ../..
make all
