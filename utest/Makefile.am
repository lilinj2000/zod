AUTOMAKE_OPTIONS = foreign

# TESTS = unittest.sh
check_PROGRAMS = unittest

unittest_SOURCES = \
	PullServiceTest.cc \
	SubServiceTest.cc

unittest_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(READERWRITERQUEUE_CPPFLAGS) \
		$(RAPIDJSON_CPPFLAGS) \
		$(FMT_CPPFLAGS) \
		$(SPDLOG_CPPFLAGS) \
		$(GTEST_CPPFLAGS) \
		$(COVERAGE_CXXFLAGS)

unittest_LDADD = \
	$(GTEST_LIBADD) \
	../service/libzod.la \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(FMT_LIBADD) \
	$(COVERAGE_LDFLAGS)

unittest_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = 

EXTRA_DIST = env.sh unittest.sh
