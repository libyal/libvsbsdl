#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libvsbsdl/.libs/libvsbsdl.1.dylib && test -f ./pyvsbsdl/.libs/pyvsbsdl.so;
then
	install_name_tool -change /usr/local/lib/libvsbsdl.1.dylib ${PWD}/libvsbsdl/.libs/libvsbsdl.1.dylib ./pyvsbsdl/.libs/pyvsbsdl.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

