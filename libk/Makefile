# Copyright (C) 2026 obrigani team
# SPDX-License-Identifier: GPL-3.0-only

include config.def.mk
-include config.mk

CPPFLAGS := $(CPPFLAGS) -D__is_libc
LIBK_CPPFLAGS := $(CPPFLAGS) -D__is_libk

OBJS := \
	string/strlen.c \
	string/memmove.c \
	string/memcmp.c \
	string/memset.c \
	string/memcpy.c

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
	rm -f $(BINARIES) *.a
	rm -f $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) $(LIBK_OBJS:.o=.d) *.d */*.d */*/*.d

.PHONY: install
install: install-headers install-libs

.PHONY: install-headers
install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

.PHONY: install-libs
install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINARIES) $(DESTDIR)$(LIBDIR)

# -include $(OBJS:.o=.d)
# -include $(LIBK_OBJS:.o=.d)
