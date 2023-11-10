AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCLOCALE_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBCSPLIT_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBCFILE_CPPFLAGS@ \
	@LIBCPATH_CPPFLAGS@ \
	@LIBBFIO_CPPFLAGS@ \
	@LIBFCACHE_CPPFLAGS@ \
	@LIBFDATA_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBVSBSDL_DLL_EXPORT@

lib_LTLIBRARIES = libvsbsdl.la

libvsbsdl_la_SOURCES = \
	libvsbsdl.c \
	libvsbsdl_debug.c libvsbsdl_debug.h \
	libvsbsdl_definitions.h \
	libvsbsdl_disklabel.c libvsbsdl_disklabel.h \
	libvsbsdl_error.c libvsbsdl_error.h \
	libvsbsdl_extern.h \
	libvsbsdl_io_handle.c libvsbsdl_io_handle.h \
	libvsbsdl_libbfio.h \
	libvsbsdl_libcdata.h \
	libvsbsdl_libcerror.h \
	libvsbsdl_libclocale.h \
	libvsbsdl_libcnotify.h \
	libvsbsdl_libcthreads.h \
	libvsbsdl_libfcache.h \
	libvsbsdl_libfdata.h \
	libvsbsdl_notify.c libvsbsdl_notify.h \
	libvsbsdl_partition.c libvsbsdl_partition.h \
	libvsbsdl_partition_entry.c libvsbsdl_partition_entry.h \
	libvsbsdl_sector_data.c libvsbsdl_sector_data.h \
	libvsbsdl_support.c libvsbsdl_support.h \
	libvsbsdl_types.h \
	libvsbsdl_unused.h \
	libvsbsdl_volume.c libvsbsdl_volume.h \
	vsbsdl_disklabel.h \
	vsbsdl_partition_entry.h

libvsbsdl_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	@LIBCTHREADS_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBBFIO_LIBADD@ \
	@LIBFCACHE_LIBADD@ \
	@LIBFDATA_LIBADD@ \
	@PTHREAD_LIBADD@

libvsbsdl_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libvsbsdl_definitions.h.in \
	libvsbsdl.rc \
	libvsbsdl.rc.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f libvsbsdl_definitions.h
	-rm -f libvsbsdl.rc
	-rm -f Makefile

sources-local: $(BUILT_SOURCES)

splint-local:
	@echo "Running splint on libvsbsdl ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libvsbsdl_la_SOURCES)

