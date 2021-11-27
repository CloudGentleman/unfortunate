/*
 * unfortunate numeric operation support
 */

#include <stdlib.h>

typedef struct {
    unsigned char* __data;
    unsigned int size;
} large;

int large_init(large* num, unsigned int size) {
    // allocate memory for storage
    num -> __data = realloc(num -> __data, size);
    // check if allocation is successful
    if (num -> __data != NULL) {
        // update size
        num -> size = size;
        // clear space
        memset(num -> __data, 0, size);
        // 0 meaning successful
        return 0;
    } else {
        // empty
        num -> size = 0;
        // 1 meaning exception
        return 1;
    }
}

large large_new(unsigned int size) {
    // initialise
    large num;
    large_init(&num, size);
    return num;
}

void large_free(large* num) {
    // free allocated memory
    free(num -> __data);
    // clear struct
    num -> __data = NULL;
    num -> size = 0;
}

large large_add(large* left, large* right) {
    // choose the largest as the new size
    large result = large_new(
            (left -> size > right -> size) ? left -> size : right -> size);
    // tmpvar for scaling
    int push = 0;
    for (int i = 0; i < result.size; i++) {
        // add
        int tmp = (int)((i < left -> size) ? left -> __data[i] : 0)
            + (int)((i < right -> size) ? right -> __data[i] : 0);
        // store
        result.__data[i] = (unsigned char)(tmp % 256);
        // scale
        push = tmp / 256;
    }
    // overflow bit
    if (push) {
        // update size
        result.size++;
        // push scaling
        result.__data = realloc(result.__data, result.size);
        result.__data[result.size - 1] = (unsigned char)push;
    }
    return result;
}

void large_add_inplace(large* base, large* add) {
    base -> size = (base -> size > add -> size) ? base -> size : add -> size;
    // W.I.P
}

