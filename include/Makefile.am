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
	-rm -f libvsbsdl.h
	-rm -f libvsbsdl/definitions.h
	-rm -f libvsbsdl/features.h
	-rm -f libvsbsdl/types.h
	-rm -f Makefile

