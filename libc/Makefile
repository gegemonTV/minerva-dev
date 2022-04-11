DEFAULT_HOST!=../default-host.sh
HOST?=DEFAULT_HOST
HOSTARCH!=../target-triplet-to-arch.sh $(HOST)

CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
CPPFLAGS:=$(CPPFLAGS) -D__is_libc -Iinclude
LIBK_CFLAGS:=$(CFLAGS)
LIBK_CPPFLAGS:=$(CPPFLAGS) -D__is_libk

ARCHDIR=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(ARCH_CPPFLAGS)
LIBK_CFLAGS:=$(LIBK_CFLAGS) $(KERNEL_ARCH_CFLAGS)
LIBK_CPPFLAGS:=$(LIBK_CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)

FREEOBJS=\
$(ARCH_FREEOBJS) \
stdio/printf.o \
stdio/putchar.o \
stdio/puts.o \
stdlib/abort.o \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memset.o \
string/strlen.o \
ctype/isalnum.o \
ctype/isalpha.o \
ctype/iscntrl.o \
ctype/isdigit.o \
ctype/isgraph.o \
ctype/islower.o \
ctype/isprint.o \
ctype/ispunct.o \
ctype/isspace.o \
ctype/isupper.o \
ctype/isxdigit.o \
ctype/tolower.o \
ctype/toupper.o \
ctype/xctype.o \
ctype/xtolower.o \
ctype/xtoupper.o \
errno/errno.o \
float/xfloat.o \
locale/localeco.o \
locale/setlocal.o \
locale/xdeflocal.o \
locale/xfmtval.o \
locale/xfreeloc.o \
locale/xgetloc.o \
locale/xloctab.o \
locale/xlocterm.o \
locale/xmakeloc.o \
locale/xreadloc.o \
locale/xsetloc.o \
locale/xstate.o \
math/acos.o \
math/asin.o \
math/atan.o \
math/atan2.o \
math/ceil.o \
math/cos.o \
math/cosh.o \
math/exp.o \
math/fabs.o \
math/floor.o \
math/fmod.o \
math/frexp.o \
math/ldexp.o \
math/log.o \
math/log10.o \
math/modf.o \
math/pow.o \
math/sin.o \
math/sinh.o \
math/sqrt.o \
math/tan.o \
math/tanh.o \
math/xasin.o \
math/xatan.o \
math/xdint.o \
math/xdnorm.o \
math/xdscale.o \
math/xdtento.o \
math/xdtest.o \
math/xdunscale.o \
math/xexp.o \
math/xldunsca.o \
math/xlog.o \
math/xpoly.o \
math/xsin.o \
math/xvals.o \
assert/xassert.o \


HOSTEDOBJS=\
$(ARCH_HOSTEDOBJS) \

OBJS=\
$(FREEOBJS) \
$(HOSTEDOBJS) \

LIBK_OBJS=$(FREEOBJS:.o=.libk.o)

#BINARIES=libc.a libk.a # Not ready for libc yet.
BINARIES=libk.a

.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .libk.o .c .S

all: $(BINARIES)

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)

.c.S:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

.c.libk.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)

.S.libk.o:
	$(CC) -MD -c $< -o $@ $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)

clean:
	rm -f $(BINARIES) *.a
	rm -f $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) $(LIBK_OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINARIES) $(DESTDIR)$(LIBDIR)

-include $(OBJS:.o=.d)
-include $(LIBK_OBJS:.o=.d)
