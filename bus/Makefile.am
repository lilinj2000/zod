AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = bus
bus_SOURCES = \
	Config.cc \
	Server.cc \
	Main.cc

bus_CPPFLAGS =  \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(ZMQ_CPPFLAGS)

bus_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(ZMQ_LIBADD)


bus_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = Config.hh Log.hh Server.hh 

EXTRA_DIST = env.sh bus.cfg log.cfg

# proxydir = $(bindir)
# proxy_DATA = $(EXTRA_DIST)

