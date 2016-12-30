/*
 * SurgeScript
 * A lightweight programming language for computer games and interactive apps
 * Copyright (C) 2016  Alexandre Martins <alemartf(at)gmail(dot)com>
 *
 * util/ssarray.h
 * SurgeScript expandable arrays
 */

#include "util.h"

/*
 * SSARRAY()
 * declares an array of a certain type
 */
#define SSARRAY(type, arr)                    type* arr; size_t arr##_len, arr##_cap;

/*
 * ssarray_init()
 * initializes the array
 */
#define ssarray_init(arr)                     (arr##_len = 0, arr##_cap = 4, arr = ssmalloc(arr##_cap * sizeof(*arr)))

/*
 * ssarray_release()
 * releases the array
 */
#define ssarray_release(arr)                  (arr##_len = arr##_cap = 0, arr = (arr ? ssfree(arr) : NULL))

/*
 * ssarray_push()
 * pushes element 'x' into the array, returning the new length of the array
 */
#define ssarray_push(arr, x)                  \
    (*(((arr##_len >= arr##_cap) ? (arr = ssrealloc(arr, (arr##_cap *= 2) * sizeof(*(arr)))) : arr) + (arr##_len)) = (x), ++arr##_len)

/*
 * ssarray_remove()
 * removes the index-th element from the array. Must give index >= 0
 */
 #define ssarray_remove(arr, index)           \
    do { for(int j = (index) + 1; j < (arr##_len); j++) { memmove((arr) + j - 1, (arr) + j, sizeof(*(arr))); } if(arr##_len > (index)) arr##_len--; } while(0)

/*
 * ssarray_length()
 * returns the length of the array
 */
#define ssarray_length(arr)                   (arr##_len)
