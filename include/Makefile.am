include_HEADERS = \
	libvsbsdl.h

pkginclude_HEADERS = \
	libvsbsdl/codepage.h \
	libvsbsdl/definitions.h \
	libvsbsdl/error.h \
	libvsbsdl/extern.h \
	libvsbsdl/features.h \
	libvsbsdl/types.h

EXTRA_DIST = \
	libvsbsdl.h.in \
	libvsbsdl/definitions.h.in \
	libvsbsdl/features.h.in \
	libvsbsdl/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libvsbsdl.h
	/bin/rm -f libvsbsdl/definitions.h
	/bin/rm -f libvsbsdl/features.h
	/bin/rm -f libvsbsdl/types.h
	/bin/rm -f Makefile

