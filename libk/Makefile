# Copyright (C) 2026 obrigani team
# SPDX-License-Identifier: GPL-3.0-only

include config.def.mk
-include config.mk

CPPFLAGS := $(CPPFLAGS) -D__is_libc -I../common
LIBK_CPPFLAGS := $(CPPFLAGS) -D__is_libk

OBJS := \
	string/strlen.c \
	string/memmove.c \
	string/memcmp.c \
	string/memset.c \
	string/memcpy.c \
	stdio/printf.c \
	stdio/putchar.c \
	stdio/puts.c \
	stdlib/abort.c

LIBK_OBJS=$(OBJS:.c=.libk.o)

BINARIES = libk.a

.SUFFIXES: .o .libk.o .c .S

.PHONY: all
all: $(BINARIES)

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

.S.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

.c.libk.o:
	$(CC) -MD -c $< -o $@ $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)

.S.libk.o:
	$(CC) -MD -c $< -o $@ $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)

.PHONY: clean
clean:
	rm -v -f $(BINARIES) *.a
	rm -v -f $(LIBK_OBJS) 
	rm -v -f $(LIBK_OBJS:.o=.d)

.PHONY: install
install: install-headers install-libs

.PHONY: install-headers
install-headers:
	mkdir -v -p $(DESTDIR)$(INCLUDEDIR)
	cp -v -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

.PHONY: install-libs
install-libs: $(BINARIES)
	mkdir -v -p $(DESTDIR)$(LIBDIR)
	cp -v $(BINARIES) $(DESTDIR)$(LIBDIR)

# -include $(OBJS:.o=.d)
# -include $(LIBK_OBJS:.o=.d)
