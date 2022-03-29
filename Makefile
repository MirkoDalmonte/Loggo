CC=g++ 
CFLAGS=-Wall -no-pie

SRCS = main.cpp loggo.cpp
DEPS = 
OBJS = ${SRCS:.cpp=.o}

MAIN = Loggo

all: ${MAIN}

${MAIN}: ${OBJS} ${DEPS}
								${CC} ${CFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
								${CC} ${CFLAGS} -c $< -o $@


clean:
				rm -f ${MAIN} *.o ${OBJS}

run: Loggo
				./Loggo
