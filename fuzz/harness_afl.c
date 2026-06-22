#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
extern int ParseRequestBuffer(const uint8_t *data, size_t size);
int main(int argc, char **argv) {
    if (argc < 2) return 0;
    FILE *f = fopen(argv[1], "rb");
    if (!f) return 0;
    static uint8_t buf[4096];
    size_t n = fread(buf, 1, sizeof(buf), f);
    fclose(f);
    ParseRequestBuffer(buf, n);
    return 0;
}
