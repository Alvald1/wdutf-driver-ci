FROM aflplusplus/aflplusplus:latest
COPY harness_afl.c driver_portable.c /src/
WORKDIR /src
RUN afl-clang-fast -fsanitize=address -g -o /fuzz/harness harness_afl.c driver_portable.c
ENTRYPOINT ["afl-fuzz", "-i", "/corpus", "-o", "/findings", "--", "/fuzz/harness", "@@"]
