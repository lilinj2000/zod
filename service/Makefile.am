AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libzod.la
libzod_la_SOURCES = \
		PubServiceImpl.cc \
		SubServiceImpl.cc

libzod_la_CPPFLAGS = -I$(top_srcdir) \
			$(BOOST_CPPFLAGS) \
			$(SOIL_CPPFLAGS) \
			$(ZMQ_CPPFLAGS)

libzod_la_LIBADD = \
		$(BOOST_LIBADD) \
		$(SOIL_LIBADD) \
		$(ZMQ_LIBADD)

libzod_la_LDFLAGS = \
	-no-undefined -version-info \
	$(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-release $(LT_RELEASE)

# header files
noinst_HEADERS = PubServiceImpl.hh

EXTRA_DIST = 

