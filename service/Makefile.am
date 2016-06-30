AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libzod.la
libzod_la_SOURCES = \
		Service.cc \
		RecvService.cc \
		PubServiceImpl.cc \
		SubServiceImpl.cc \
		PushServiceImpl.cc \
		PullServiceImpl.cc

libzod_la_CPPFLAGS = -I$(top_srcdir) \
			$(BOOST_CPPFLAGS) \
			$(SOIL_CPPFLAGS) \
			$(ZMQ_CPPFLAGS) \
			$(CZMQ_CPPFLAGS)

libzod_la_LIBADD = \
		$(BOOST_LIBADD) \
		$(SOIL_LIBADD) \
		$(CZMQ_LIBADD)

libzod_la_LDFLAGS = \
	-no-undefined -version-info \
	$(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-release $(LT_RELEASE)

# header files
noinst_HEADERS = Log.hh Service.hh RecvService.hh \
		PubServiceImpl.hh SubServiceImpl.hh \
		PushServiceImpl.hh PullServiceImpl.hh

EXTRA_DIST = 

