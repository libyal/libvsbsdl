# Note that we cannot use: AUTOMAKE_OPTIONS = subdir-objects
# subdir-objects will compile the source files to a single version of Python.
# Since subdir-objects is being deprecated we copy the source files instead.
am__installdirs = "$(DESTDIR)$(pyexecdir2)"
pyexecdir = $(pyexecdir2)

if HAVE_PYTHON2
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

am_pyvsbsdl_la_rpath = -rpath $(pyexecdir2)

BUILT_SOURCES = \
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

pyexec_LTLIBRARIES = pyvsbsdl.la

nodist_pyvsbsdl_la_SOURCES = $(BUILT_SOURCES)

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

pyvsbsdl_la_CPPFLAGS = $(PYTHON2_CPPFLAGS)
pyvsbsdl_la_LDFLAGS  = -module -avoid-version $(PYTHON2_LDFLAGS)

$(BUILT_SOURCES):
	/bin/cp -f $(top_srcdir)/pyvsbsdl/$@ $@

endif

MAINTAINERCLEANFILES = \
	Makefile.in

clean-local:
	/bin/rm -f pyvsbsdl*.[ch]

distclean: clean
	/bin/rm -f Makefile

