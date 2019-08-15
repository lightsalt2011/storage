#include "int2str.h"

#ifdef DEBUG
#define LOOP_COUNT 1
#else
#define LOOP_COUNT 10000
#endif

#define U16_NUMBER  12345
#define INT_NUMBER  INT32_MAX

int main(int argc, char** argv)
{
    char buff[32] = {0}, *p;
    uint64_t start, stop;
    int i;
    size_t n;

    InitU16StrMap();

    printf("---u16tostr----\nconvert: %u\n", 3);
    start = rte_rdtsc();
    for (i = 0; i < LOOP_COUNT; i++) {
        p = buff;
        APPFMT_CharToBuf('3', p);
    }
    stop = rte_rdtsc();
    printf("str: %s, "FMT64"\n", buff, stop - start);

    start = rte_rdtsc();
    for (i = 0; i < LOOP_COUNT; i++) {
        p = buff;
        APPFMT_U8ToBuf(g_u16StrMap, 3, p);
    }
    stop = rte_rdtsc();
    printf("str: %s, "FMT64"\n", buff, stop - start);

    printf("---u16tostr----\nconvert: %u\n", 12345);
    memset(buff, 0, sizeof(buff));
    start = rte_rdtsc();
    for (i = 0; i < LOOP_COUNT; i++) {
        p = buff;
        APPFMT_StrToBuf("12345", 5, p);
    }
    stop = rte_rdtsc();
    printf("str: %s, "FMT64"\n", buff, stop - start);

    start = rte_rdtsc();
    for (i = 0; i < LOOP_COUNT; i++) {
        p = buff;
        APPFMT_U16ToBuf(g_u16StrMap, 12345, p);
    }
    stop = rte_rdtsc();
    printf("str: %s, "FMT64"\n", buff, stop - start);

    printf("---int2hex---\nconvert: %d\n", INT_NUMBER);
    start = rte_rdtsc();
    for (i = 0; i < LOOP_COUNT; i++) {
        n = Int2Hex(hexArray, INT_NUMBER, buff);
    }
    stop = rte_rdtsc();
    printf("str: 0x%s, n: %zu, "FMT64"\n", buff, n, stop - start);

    start = rte_rdtsc();
    for (i = 0; i < LOOP_COUNT; i++) {
        n = Int2Hex2(INT_NUMBER, buff);
    }
    stop = rte_rdtsc();
    printf("str: 0x%s, n: %zu, "FMT64"\n", buff, n, stop - start);

    return 0;
}
