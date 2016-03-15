AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = forwarder
forwarder_SOURCES = \
	Config.cc \
	Server.cc \
	Main.cc

forwarder_CPPFLAGS =  \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(ZMQ_CPPFLAGS)

forwarder_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(ZMQ_LIBADD)


forwarder_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = Config.hh Log.hh Server.hh 

EXTRA_DIST = env.sh forwarder.cfg log.cfg

# proxydir = $(bindir)
# proxy_DATA = $(EXTRA_DIST)

