# cowm - A tiling window manager for farmers and peasants
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c cowm.c util.c
OBJ = ${SRC:.c=.o}

all: options cowm

options:
	@echo cowm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

cowm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

# Before push
prep:
	rm -f config.h cowm ${OBJ} cowm-${VERSION}.tar.gz

clean:
	rm -f cowm ${OBJ} cowm-${VERSION}.tar.gz

dist: clean
	mkdir -p cowm-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		cowm.1 drw.h util.h ${SRC} cowm.png transient.c cowm-${VERSION}
	tar -cf cowm-${VERSION}.tar cowm-${VERSION}
	gzip cowm-${VERSION}.tar
	rm -rf cowm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f cowm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/cowm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < cowm.1 > ${DESTDIR}${MANPREFIX}/man1/cowm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/cowm.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/cowm\
		${DESTDIR}${MANPREFIX}/man1/cowm.1

.PHONY: all options clean dist install uninstall
