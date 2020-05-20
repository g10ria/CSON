compile=gcc
buildDir=bin
headersDir=headers

_deps = ${headersDir}/hashmapLite.h
deps = $(patsubst %,$(headersDir)/%,$(_deps))

obj = hashmapLite.o

%.o: %.c
	$(compile) -c -o $@ $<

hashmapLite: $(obj)
	$(compile) -o ${buildDir}/$@.bin $^ -I/$(headersDir)