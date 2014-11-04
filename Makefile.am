SUBDIRS = src

# requires gnulib
ChangeLog:
	if test -d $(top_srcdir)/.git; then                             \
          sh /usr/share/gnulib/build-aux/gitlog-to-changelog > $@;             \
        fi

dist: ChangeLog

.PHONY: ChangeLog


