#include <stdio.h>
#include "cache.h"

#define MAX_MEMOIZED 100
#define ARRAY_SIZE (MAX_MEMOIZED+1)
#define NO_VALUE_YET -1
long_func_ptr _original_provider;
long _memoization_data[ARRAY_SIZE];

long cache_func(int of_num) {
    //printf(__FILE__ ":%2d   cache_func(%d) called\n",__LINE__,
        //of_num);

    if ( of_num > MAX_MEMOIZED )
        return (*_original_provider)(of_num);

    if ( _memoization_data[of_num] == NO_VALUE_YET )
    _memoization_data[of_num] = (*_original_provider)(of_num);

    return _memoization_data[of_num];
}

long_func_ptr init_cache(long_func_ptr real_provider) {
    for (int ix=0; ix<ARRAY_SIZE; ix++)
    _memoization_data[ix] = NO_VALUE_YET;

    _original_provider = real_provider;
    return cache_func;
}

