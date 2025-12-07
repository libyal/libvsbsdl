#!/bin/sh
# Script to build a MacOS pkg
#
# Version: 20241015

set -e

make install DESTDIR=${PWD}/osx-pkg
mkdir -p ${PWD}/osx-pkg/usr/share/doc/libvsbsdl
cp AUTHORS COPYING COPYING.LESSER NEWS README ${PWD}/osx-pkg/usr/share/doc/libvsbsdl

VERSION=`sed '5!d; s/^  \[//;s/\],$//' configure.ac`
pkgbuild --root osx-pkg --identifier com.github.libyal.libvsbsdl --version ${VERSION} --ownership recommended ../libvsbsdl-${VERSION}.pkg

