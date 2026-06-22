AUTOMAKE_OPTIONS = subdir-objects

AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
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

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages \
	test_tools

if HAVE_PYTHON_TESTS
check_AUTOTESTS += test_python_module
endif

check_SCRIPTS = \
	pyvsbsdl_test_partition.py \
	pyvsbsdl_test_support.py \
	pyvsbsdl_test_volume.py

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
	vsbsdl_test_extern.h \
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
	@LIBCERROR_LIBADD@ \
	@LIBINTL@

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
	vsbsdl_test_extern.h \
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

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_inputs_libvsbsdl.at: generate_test_inputs.sh
	$(SHELL) $(srcdir)/generate_test_inputs.sh $(PACKAGE_NAME) libvsbsdl

test_inputs_pyvsbsdl.at: generate_test_inputs.sh
	$(SHELL) $(srcdir)/generate_test_inputs.sh $(PACKAGE_NAME) pyvsbsdl

test_inputs_vsbsdlinfo.at: generate_test_inputs.sh
	$(SHELL) $(srcdir)/generate_test_inputs.sh $(PACKAGE_NAME) vsbsdlinfo

test_library: \
	package.m4 \
	test_inputs_libvsbsdl.at \
	test_library.at \
	test_macros.at

test_manpages: \
	package.m4 \
	test_manpages.at

test_python_module: \
	package.m4 \
	test_inputs_pyvsbsdl.at \
	test_macros.at \
	test_python_module.at

test_tools: \
	package.m4 \
	test_inputs_vsbsdlinfo.at \
	test_macros.at \
	test_tools.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	$(check_SCRIPTS) \
	generate_test_inputs.sh \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp \
	notify_stream.log \
	test_inputs_*.at

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

