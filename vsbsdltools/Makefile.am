AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCLOCALE_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBCSPLIT_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBCFILE_CPPFLAGS@ \
	@LIBCPATH_CPPFLAGS@ \
	@LIBBFIO_CPPFLAGS@ \
	@LIBVSBSDL_DLL_IMPORT@

AM_LDFLAGS = @STATIC_LDFLAGS@

bin_PROGRAMS = \
	vsbsdlinfo

vsbsdlinfo_SOURCES = \
	info_handle.c info_handle.h \
	vsbsdltools_getopt.c vsbsdltools_getopt.h \
	vsbsdltools_i18n.h \
	vsbsdlinfo.c \
	vsbsdltools_libbfio.h \
	vsbsdltools_libcerror.h \
	vsbsdltools_libclocale.h \
	vsbsdltools_libcnotify.h \
	vsbsdltools_libuna.h \
	vsbsdltools_libvsbsdl.h \
	vsbsdltools_output.c vsbsdltools_output.h \
	vsbsdltools_signal.c vsbsdltools_signal.h \
	vsbsdltools_unused.h

vsbsdlinfo_LDADD = \
	@LIBBFIO_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	../libvsbsdl/libvsbsdl.la \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	@LIBINTL@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f Makefile

splint-local:
	@echo "Running splint on vsbsdlinfo ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(vsbsdlinfo_SOURCES)

