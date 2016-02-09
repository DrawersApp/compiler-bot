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
curl -O http://camaya.net/download/gloox-1.0.14.tar.bz2
tar -xzvf gloox-1.0.14.tar.bz2
cd gloox-1.0.14
./configure
make
make install
cd $direc
cd ../..
make all
