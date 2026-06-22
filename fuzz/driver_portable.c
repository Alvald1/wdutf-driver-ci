#include <stdint.h>
#include <stddef.h>
#include <string.h>

int ParseRequestBuffer(const uint8_t *data, size_t size) {
    char cmd[8];
    if (size < 1) return -1;
    if (data[0] == 'C') {
        memcpy(cmd, data + 1, size - 1);
        return (int)cmd[0];
    }
    return 0;
}
