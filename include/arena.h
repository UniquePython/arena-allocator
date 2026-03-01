#ifndef ARENA_H
#define ARENA_H

#include <stdlib.h>

#define KiB(x) ((x) << 10)
#define MiB(x) ((x) << 20)
#define GiB(x) ((x) << 30)

typedef struct s_arena
{
    char *start;
    size_t used, capacity;
} Arena;

Arena arena_create(size_t capacity);
void *arena_alloc(Arena *arena, size_t size);
void arena_destroy(Arena *arena);

#endif