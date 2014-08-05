#include <stdio.h>

struct item {
    char name[20];
    char type;
}; /* define a record */

struct mob {
    int level;
    char class;
    char name[20];
    char race[20];
    int hp;
    int dam;
}; /* define a record */

struct player {
    int level;
    char class;
    char name[20];
    char race[20];
    int hp;
    int dam;
}; /* define a record */

union content {
    struct player player;
    struct mob mob;
    struct item item;
}; /* define a record */

struct tile {
    char type;
    union content content; 
}; /* define a record */

struct room {
    char name[20];
    struct tile tiles[25];
}; /* define a record */

struct level {
  struct room rooms[50];   
}; /* define a record */

int populate_dungeon()
{
    printf("Populating dungeon...\n");
    return 0;
}

int main()
{
    struct player mc;
    mc.level = 1;
    mc.class = 'f';
    fgets ( mc.name, 20, stdin );
    printf(" level=%i\n class=%c\n name=%s\n", mc.level, mc.class, mc.name);
    struct level l1;
    struct room l1r1;
    l1r1.name = 'f';
    struct tile l1r1t1;
    l1r1t1.content.player = mc;
    room.tiles[0] = l1r1t1;
    level.rooms[0] = l1r1;

    return 0;
}
