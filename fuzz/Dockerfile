FROM aflplusplus/aflplusplus:latest
COPY harness_afl.c harness_persist.c driver_portable.c /src/
WORKDIR /src
RUN mkdir -p /fuzz /corpus /findings && \
    printf 'A' > /corpus/seed1 && \
    printf 'C' > /corpus/seed2 && \
    afl-clang-fast -fsanitize=address -g -o /fuzz/harness_fork    harness_afl.c     driver_portable.c && \
    afl-clang-fast -fsanitize=address -g -o /fuzz/harness_persist harness_persist.c driver_portable.c
