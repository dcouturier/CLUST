bin_PROGRAMS = clust

clust_SOURCES = main.c 
clust_LDADD = libCLUST.la $(UST_LIBS)
clust_CFLAGS = $(UST_CFLAGS)

lib_LTLIBRARIES = libCLUST.la
libCLUST_la_SOURCES = clust.c clust.h clust_tp.h
libCLUST_la_LIBADD = $(UST_LIBS)
libCLUST_la_CFLAGS = $(UST_CFLAGS)