#ifndef CACHE_H
#define CACHE_H


typedef long (*long_func_ptr)(int param);

long cache_func(int of_num);
long_func_ptr init_cache(long_func_ptr real_provider);

#endif