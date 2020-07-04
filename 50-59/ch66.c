#include <stdint.h>
#include <stdio.h>
#include <math.h>

uint64_t find_x(uint64_t D) {
    uint64_t min_res = 1000, min_x = 0, val;

    for (uint64_t x = 1; x < 10000; x++) {
        for (uint64_t y = 1; y < 10000; y++) {
            if ((x*x) > (D * y * y)) {
                val = x*x - D * y * y;
            } else {
                val = D * y * y - x*x;
            }

            if (val > 0 && val < min_res) {
                //printf("D=%lu, new min: %lu, x=%lu\n", D, val, x);
                min_res = val;
                min_x = x;
            }
        }
    }

    if (min_res == 1000 && min_x == 0) {
        printf("BAD no sol :( D = %lu\n", D);
    }

    printf("Minval : %lu, D=%lu, x=%lu\n", min_res, D, min_x);

    return min_x;

}

int main(void) {

    uint64_t D_max = 1000, maxx = 0;

    for (uint64_t D = 1; D < D_max; D++) {

        if (sqrt(D) * sqrt(D) != D) {

            uint64_t x = find_x(D);
            //printf("D = %lu, got x=%lu\n", D,x);

            if (x > maxx) {
                maxx = x;
                printf("New max : D=%lu, x=%lu\n", D, x);
            }
        }

    }

}
