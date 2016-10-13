CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_orig = -O0
CFLAGS_opt  = -O0 -pthread -g -pg -D_REENTRANT -Isrc

ifdef THREAD
CFLAGS_opt  += -D THREAD_NUM=${THREAD}
endif

ifeq ($(strip $(DEBUG)),1)
CFLAGS_opt += -DDEBUG -g
endif

EXEC = phonebook_orig phonebook_opt \
	libthreadpool.so libthreadpool.a

all: $(EXEC)

SRCS_common = main.c

src/threadpool.o: src/threadpool.c src/threadpool.h

# Short-hand aliases
shared: libthreadpool.so
static: libthreadpool.a

libthreadpool.so: src/threadpool.c src/threadpool.h
	$(CC) -shared -fPIC ${CFLAGS} -o $@ $< ${LDLIBS}

src/libthreadpool.o: src/threadpool.c src/threadpool.h
	$(CC) -c -fPIC ${CFLAGS} -o $@ $<

libthreadpool.a: src/libthreadpool.o
	ar rcs $@ $^

file_align: file_align.c
	$(CC) $(CFLAGS_common) $^ -o $@

phonebook_orig: $(SRCS_common) phonebook_orig.c phonebook_orig.h
	$(CC) $(CFLAGS_common) $(CFLAGS_orig) \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_opt: $(SRCS_common) phonebook_opt.c phonebook_opt.h src/threadpool.o
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

run: $(EXEC)
	echo 3 | sudo tee /proc/sys/vm/drop_caches
	watch -d -t "./phonebook_orig && echo 3 | sudo tee /proc/sys/vm/drop_caches"

cache-test: $(EXEC)
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_orig
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_opt

output.txt: cache-test calculate
	./calculate

plot: output.txt 
	gnuplot scripts/runtime.gp

compare:
	gnuplot scripts/test.gp

calculate: calculate.c
	$(CC) $(CFLAGS_common) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o perf.* \
	      	calculate orig.txt opt.txt output.txt runtime.png file_align align.txt
