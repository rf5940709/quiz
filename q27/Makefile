CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99
PERF = stat -r 5 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses

EXEC = main
all: $(EXEC)

main: main.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

perf_main: $(EXEC)
	perf $(PERF) ./main

perf_clear:
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
clean:
	$(RM) $(EXEC) *.o perf.*
