include config.mk

SRC = ../source/*.c

choice: clean
	@echo "Building choice"
	@${CC} -o choice ${CFLAGS} ${SRC} ${LDFLAGS}

debug: clean
	@echo "Building debug"
	@echo "Flags :  ${DEBUG_CFLAGS}"
	@echo "Libs :   ${LD_FLAGS}"
	@echo "Source : ${SRC}"
	@${CC} -o debug ${DEBUG_CFLAGS} ${SRC} ${LDFLAGS}

install:
	@echo "Installing choice"
	@echo "Flags  :" ${INSTALL_CFLAGS}
	@echo "Libs   :" ${LDFLAGS}
	@echo "Source :" ${SRC}
	@${CC} -o choice ${INSTALL_CFLAGS} ${SRC} ${LDFLAGS}
	@${STRIP} choice
	@echo "Installing executable file to ${BIN_DIR}"
	@cp -f choice ${BIN_DIR}/choice
	@chmod 755 ${BIN_DIR}/choice
	@echo "Installing manual to ${MAN_DIR}"
	@mkdir -p ${MAN_DIR}
	@sed "s/VERSION/${VERSION}/g" < ../choice.1 > ${MAN_DIR}/choice.1
	@chmod 644 ${MAN_DIR}/choice.1
	@rm -f choice

uninstall:
	@echo "Removing executable files from ${BIN_DIR}"
	@rm -f ${BIN_DIR}/choice
	@echo "Removing manual from ${MAN_DIR}"
	@rm -f ${MAN_DIR}/choice.1

clean:
	@echo "Cleaning"
	@rm -f choice
	@rm -f debug
