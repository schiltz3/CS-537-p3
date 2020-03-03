#include "rand.h"
#include "types.h"

uint big_seed = 1;

int xv6_rand (void)
{   
    uint x = big_seed;
    x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
    int small_seed = 0;
    small_seed = big_seed % XV6_RAND_MAX;
    big_seed = x;
    return small_seed;
}

void xv6_srand (unsigned int seed)
{
     big_seed = seed;
}