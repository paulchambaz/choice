VERSION = 0.0.1
PREFIX ?= /usr
BIN_DIR = ${PREFIX}/bin
MAN_DIR = ${PREFIX}/share/man/man1
INCS = -I ../include
LIBS =
CFLAGS += -std=c99 ${INCS} -DVERSION=\"${VERSION}\" -DNDBUG
INSTALL_CFLAGS += -std=c99 ${INCS} -DVERSION=\"${VERSION}\" -DNDBUG -Ofast
DEBUG_CFLAGS = ${CFLAGS} -UNDEBUG -O0 -g -ggdb -Wall -Wextra -Wno-unused-parameter
LDFLAGS += ${LIBS}
CC ?= cc
STRIP ?= strip
