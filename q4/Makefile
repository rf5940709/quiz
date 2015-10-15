CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99
PERF = stat -r 5 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

perf_recursive: $(EXEC)
	perf $(PERF) ./recursive

perf_iterative: $(EXEC)
	perf $(PERF) ./iterative

perf_clear:
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
clean:
	$(RM) $(EXEC) *.o perf.*
