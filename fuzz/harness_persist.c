#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

__AFL_FUZZ_INIT();

extern int ParseRequestBuffer(const uint8_t *data, size_t size);

int main(void) {
#ifdef __AFL_HAVE_MANUAL_CONTROL
    __AFL_INIT();
#endif
    unsigned char *buf = __AFL_FUZZ_TESTCASE_BUF;   /* разделяемая память */
    while (__AFL_LOOP(10000)) {                      /* цикл без fork() */
        int len = __AFL_FUZZ_TESTCASE_LEN;
        ParseRequestBuffer(buf, (size_t)len);
    }
    return 0;
}
