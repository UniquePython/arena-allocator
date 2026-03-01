#include "arena.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
    Arena arena = arena_create(KiB(1));
    int *a_ptr = (int *)arena_alloc(&arena, sizeof(int));
    int *b_ptr = (int *)arena_alloc(&arena, sizeof(int));
    int *c_ptr = (int *)arena_alloc(&arena, sizeof(int));

    *a_ptr = 10;
    *b_ptr = 20;
    *c_ptr = 30;

    printf("a=%i\n", *a_ptr);
    printf("b=%i\n", *b_ptr);
    printf("c=%i\n", *c_ptr);

    assert(arena.used == 3 * sizeof(int));

    return 0;
}