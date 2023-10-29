CC	= gcc
HELPER_FILES = generics.c
NODE_FILE = node0.c node1.c node2.c node3.c node4.c node5.c node6.c node7.c node8.c node9.c

all: dv

dv: dv.c
	${CC} ${HELPER_FILES} ${NODE_FILE} -O1 dv.c -o dv

clean:
	rm -f dv
