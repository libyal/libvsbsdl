#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libvsbsdl/.libs/libvsbsdl.1.dylib" ] && [ -f ./pyvsbsdl/.libs/pyvsbsdl.so ]
then
    install_name_tool -change /usr/local/lib/libvsbsdl.1.dylib "${PWD}/libvsbsdl/.libs/libvsbsdl.1.dylib" ./pyvsbsdl/.libs/pyvsbsdl.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

