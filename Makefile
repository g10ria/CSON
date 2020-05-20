compile=gcc
buildDir=bin
headersDir=headers

_deps = hashmapLite.h hashfunctions.h
deps = $(patsubst %,$(headersDir)/%,$(_deps))

obj = hashmapLite.o hashfunctions.o main.o

%.o: %.c
	$(compile) -c -o $@ $<

main: $(obj)
	$(compile) -o ${buildDir}/$@.bin $^ -I/$(headersDir)