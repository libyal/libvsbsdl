if HAVE_PYTHON
AM_CFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCLOCALE_CPPFLAGS@ \
	@LIBCSPLIT_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBCFILE_CPPFLAGS@ \
	@LIBCPATH_CPPFLAGS@ \
	@LIBBFIO_CPPFLAGS@ \
	@LIBVSBSDL_DLL_IMPORT@

pyexec_LTLIBRARIES = pyvsbsdl.la

pyvsbsdl_la_SOURCES = \
	pyvsbsdl.c pyvsbsdl.h \
	pyvsbsdl_error.c pyvsbsdl_error.h \
	pyvsbsdl_file_object_io_handle.c pyvsbsdl_file_object_io_handle.h \
	pyvsbsdl_integer.c pyvsbsdl_integer.h \
	pyvsbsdl_libbfio.h \
	pyvsbsdl_libcerror.h \
	pyvsbsdl_libclocale.h \
	pyvsbsdl_libvsbsdl.h \
	pyvsbsdl_partition.c pyvsbsdl_partition.h \
	pyvsbsdl_partitions.c pyvsbsdl_partitions.h \
	pyvsbsdl_python.h \
	pyvsbsdl_unused.h \
	pyvsbsdl_volume.c pyvsbsdl_volume.h

pyvsbsdl_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	../libvsbsdl/libvsbsdl.la \
	@LIBCDATA_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBBFIO_LIBADD@

pyvsbsdl_la_CPPFLAGS = $(PYTHON_CPPFLAGS)
pyvsbsdl_la_LDFLAGS  = -module -avoid-version $(PYTHON_LDFLAGS)

endif

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f Makefile

