#include "arena.h"

Arena arena_create(size_t capacity)
{
    Arena arena = {0};

    arena.start = malloc(capacity);
    if (!arena.start)
        return arena;

    arena.capacity = capacity;

    return arena;
}

void *arena_alloc(Arena *arena, size_t size)
{
    if (!arena || !arena->start)
        return NULL;

    if (arena->used + size > arena->capacity)
        return NULL;

    char *ptr = arena->start + arena->used;

    arena->used += size;

    return (void *)ptr;
}

void arena_destroy(Arena *arena)
{
    if (!arena)
        return;

    free(arena->start);

    arena->start = NULL;
    arena->used = 0;
    arena->capacity = 0;
}