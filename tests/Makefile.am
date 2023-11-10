AUTOMAKE_OPTIONS = subdir-objects

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
	@LIBVSBSDL_DLL_IMPORT@

if HAVE_PYTHON_TESTS
TESTS_PYVSBSDL = \
	test_python_module.sh
endif

TESTS = \
	test_library.sh \
	test_tools.sh \
	test_vsbsdlinfo.sh \
	$(TESTS_PYVSBSDL)

check_SCRIPTS = \
	pyvsbsdl_test_partition.py \
	pyvsbsdl_test_support.py \
	pyvsbsdl_test_volume.py \
	test_library.sh \
	test_manpage.sh \
	test_python_module.sh \
	test_runner.sh \
	test_tools.sh \
	test_vsbsdlinfo.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	vsbsdl_test_disklabel \
	vsbsdl_test_error \
	vsbsdl_test_io_handle \
	vsbsdl_test_notify \
	vsbsdl_test_partition \
	vsbsdl_test_partition_entry \
	vsbsdl_test_sector_data \
	vsbsdl_test_support \
	vsbsdl_test_tools_info_handle \
	vsbsdl_test_tools_output \
	vsbsdl_test_tools_signal \
	vsbsdl_test_volume

vsbsdl_test_disklabel_SOURCES = \
	vsbsdl_test_disklabel.c \
	vsbsdl_test_functions.c vsbsdl_test_functions.h \
	vsbsdl_test_libbfio.h \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_memory.c vsbsdl_test_memory.h \
	vsbsdl_test_unused.h

vsbsdl_test_disklabel_LDADD = \
	@LIBBFIO_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_error_SOURCES = \
	vsbsdl_test_error.c \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_unused.h

vsbsdl_test_error_LDADD = \
	../libvsbsdl/libvsbsdl.la

vsbsdl_test_io_handle_SOURCES = \
	vsbsdl_test_io_handle.c \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_memory.c vsbsdl_test_memory.h \
	vsbsdl_test_unused.h

vsbsdl_test_io_handle_LDADD = \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_notify_SOURCES = \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_notify.c \
	vsbsdl_test_unused.h

vsbsdl_test_notify_LDADD = \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_partition_SOURCES = \
	vsbsdl_test_functions.c vsbsdl_test_functions.h \
	vsbsdl_test_getopt.c vsbsdl_test_getopt.h \
	vsbsdl_test_libbfio.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_memory.c vsbsdl_test_memory.h \
	vsbsdl_test_partition.c \
	vsbsdl_test_rwlock.c vsbsdl_test_rwlock.h

vsbsdl_test_partition_LDADD = \
	@LIBBFIO_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	../libvsbsdl/libvsbsdl.la \
	@LIBCTHREADS_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	@PTHREAD_LIBADD@

vsbsdl_test_partition_entry_SOURCES = \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_memory.c vsbsdl_test_memory.h \
	vsbsdl_test_partition_entry.c \
	vsbsdl_test_unused.h

vsbsdl_test_partition_entry_LDADD = \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_sector_data_SOURCES = \
	vsbsdl_test_functions.c vsbsdl_test_functions.h \
	vsbsdl_test_libbfio.h \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_memory.c vsbsdl_test_memory.h \
	vsbsdl_test_sector_data.c \
	vsbsdl_test_unused.h

vsbsdl_test_sector_data_LDADD = \
	@LIBBFIO_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_support_SOURCES = \
	vsbsdl_test_functions.c vsbsdl_test_functions.h \
	vsbsdl_test_getopt.c vsbsdl_test_getopt.h \
	vsbsdl_test_libbfio.h \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_libclocale.h \
	vsbsdl_test_libcnotify.h \
	vsbsdl_test_libuna.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_memory.c vsbsdl_test_memory.h \
	vsbsdl_test_support.c \
	vsbsdl_test_unused.h

vsbsdl_test_support_LDADD = \
	@LIBBFIO_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_tools_info_handle_SOURCES = \
	../vsbsdltools/info_handle.c ../vsbsdltools/info_handle.h \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_memory.c vsbsdl_test_memory.h \
	vsbsdl_test_tools_info_handle.c \
	vsbsdl_test_unused.h

vsbsdl_test_tools_info_handle_LDADD = \
	@LIBBFIO_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_tools_output_SOURCES = \
	../vsbsdltools/vsbsdltools_output.c ../vsbsdltools/vsbsdltools_output.h \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_tools_output.c \
	vsbsdl_test_unused.h

vsbsdl_test_tools_output_LDADD = \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_tools_signal_SOURCES = \
	../vsbsdltools/vsbsdltools_signal.c ../vsbsdltools/vsbsdltools_signal.h \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_tools_signal.c \
	vsbsdl_test_unused.h

vsbsdl_test_tools_signal_LDADD = \
	../libvsbsdl/libvsbsdl.la \
	@LIBCERROR_LIBADD@

vsbsdl_test_volume_SOURCES = \
	vsbsdl_test_functions.c vsbsdl_test_functions.h \
	vsbsdl_test_getopt.c vsbsdl_test_getopt.h \
	vsbsdl_test_libbfio.h \
	vsbsdl_test_libcerror.h \
	vsbsdl_test_libclocale.h \
	vsbsdl_test_libcnotify.h \
	vsbsdl_test_libuna.h \
	vsbsdl_test_libvsbsdl.h \
	vsbsdl_test_macros.h \
	vsbsdl_test_memory.c vsbsdl_test_memory.h \
	vsbsdl_test_rwlock.c vsbsdl_test_rwlock.h \
	vsbsdl_test_unused.h \
	vsbsdl_test_volume.c

vsbsdl_test_volume_LDADD = \
	@LIBBFIO_LIBADD@ \
	@LIBCPATH_LIBADD@ \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCSPLIT_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	../libvsbsdl/libvsbsdl.la \
	@LIBCTHREADS_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	@PTHREAD_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f Makefile

