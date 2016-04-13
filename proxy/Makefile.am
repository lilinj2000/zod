AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = proxy
proxy_SOURCES = \
	Config.cc \
	Server.cc \
	Main.cc

proxy_CPPFLAGS =  \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(ZMQ_CPPFLAGS) \
		$(CZMQ_CPPFLAGS)

proxy_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(CZMQ_LIBADD)


proxy_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = Config.hh Log.hh Server.hh 

EXTRA_DIST = env.sh proxy.cfg log.cfg

proxydir = $(bindir)
proxy_DATA = $(EXTRA_DIST)

