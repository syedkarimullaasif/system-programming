cc = g++
BIN = bin/
OBJ = obj/
INC = include/
SRC = src/
CFLAG = -c
OFLAG = -o
all:clean  build-server build-client

build-server: ${OBJ}func.o
	${CC} ${OFLAG} ${BIN}server27 ${SRC}server.cpp ${OBJ}func.o
$(OBJ)fun.o:
	${CC} ${CFLAG} ${OFLAG} ${OBJ}func.o ${SRC}func.cpp

build-client:
	${CC} ${OFLAG}  ${BIN}client27 ${SRC}client.cpp
       
start-server:
	./${BIN}server27
         
start-client:
	./${BIN}client27
clean:
	rm ${OBJ}Func.o  ${BIN}server27  ${BIN}client27
     
