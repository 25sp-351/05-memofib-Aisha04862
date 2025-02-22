#include <stdio.h>
#include "cache.h"

// a type for this flavor of provider
typedef long (*long_func_ptr)(int param);

long_func_ptr fibonacci_provider;


long fibonacci(int of_num) {  
     //printf(__FILE__ ":%2d   fibonacci(%d) called\n", __LINE__, of_num);  
    if (of_num < 2)  
        return of_num;  
    return (*fibonacci_provider)(of_num - 1) + (*fibonacci_provider)(of_num - 2);  
}

// BEGIN MAIN
int main(int argc, char *argv[]) {
    int test_val;

    if (argc < 2
            || 1 != sscanf(argv[1], "%d", &test_val)
            || test_val < 0)
        return 1;

//PROGRAM INITIALIZATION
    fibonacci_provider = init_cache(fibonacci);

    

    for (int ix = test_val; ix > 0; ix--) {
        printf("The Fibonacci of %d is %ld\n", ix, (*fibonacci_provider)(ix));
    }
 
    return 0;
}