#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libvsbsdl/.libs/libvsbsdl.1.dylib && test -f ./pyvsbsdl/.libs/pyvsbsdl.so
then
	install_name_tool -change /usr/local/lib/libvsbsdl.1.dylib ${PWD}/libvsbsdl/.libs/libvsbsdl.1.dylib ./pyvsbsdl/.libs/pyvsbsdl.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

