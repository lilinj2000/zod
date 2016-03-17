AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = streamer
streamer_SOURCES = \
	Config.cc \
	Server.cc \
	Main.cc

streamer_CPPFLAGS =  \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(ZMQ_CPPFLAGS)

streamer_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(ZMQ_LIBADD)


streamer_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = Config.hh Log.hh Server.hh 

EXTRA_DIST = env.sh streamer.cfg log.cfg

streamerdir = $(bindir)
streamer_DATA = $(EXTRA_DIST)

