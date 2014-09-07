#include <stdio.h>
#include <string.h>
/*
 * TODO: Remove the hard coded data and include a way to read data from flat storage
 * TODO: Create a way for a name to get a prefix that is dependent on the type of mechanic and the item level
 *
 *
 */

/* quality */

typedef enum{
        NORMAL,
        MAGICAL,
        RARE,
        SET,
        LEGENDARY,
        END_OF_QUALITY=256
    } quality_t;

struct squality {
    quality_t quality;
    char *name;
};

typedef struct squality aquality[];

const aquality qualities = {
    {NORMAL, "normal"},
    {MAGICAL, "magical"},
    {RARE, "rare"},
    {SET, "set"},
    {LEGENDARY, "legendary"}
};

/* suffix */

typedef enum{
    NOSUFFIX,
    OFCRUELTY,
    OFSLAUGHTER,
    OFCARNAGE,
    END_OF_SUFFIX=256
} suffix_t;

struct ssuffix {
    suffix_t suffix;
    char *name;
    int mechanic; /* program logic will need to determine its kind */
};

typedef struct ssuffix asuffix[];

const asuffix suffixes = {
    {NOSUFFIX, "none", 0}, /* arbitrary numbers for testing purposes */
    {OFCRUELTY, "of Cruelty", 10}, /* Deal extra damage */ 
    {OFSLAUGHTER, "of Slaughter", 9}, /* Gain life after each kill */
    {OFCARNAGE, "of Carnage", 8} /* Gain life after each hit */
};

/* prefix */

typedef enum{
    NOPREFIX,
    ADVENTURER,
    EXPLORER,
    MARAUDER,
    REPTILIAN,
    END_OF_PREFIX=256
} prefix_t;

struct sprefix {
    prefix_t prefix;
    char *name;
    int mechanic; /* program logic will need to determine its kind */
};

typedef struct sprefix aprefix[];

const aprefix prefixes = {
    {NOPREFIX, "none", 0},
    {ADVENTURER, "adventurer", 10}, /* arbitrary numbers for testing purposes */
    {EXPLORER, "explorer", 9},
    {MARAUDER, "marauder", 8},
    {REPTILIAN, "reptilian", 7},
    {END_OF_PREFIX, NULL, 0}
};

struct gear {
    int required_level;
    int item_level;
    int buy_value;
    int sell_value;
    int durability_current;
    int durability_max;
    char *name;
    char *item_slot;
    int performance_metric;
    float gear_tier;
    int attribute_strength;
    int attribute_dexterity;
    int attribute_intellect;
    int attribute_vitality;
    int sockets; /* denotes how many gems can be socketted into this item */
    char *availability; /* denotes which classes can use this item */
    quality_t quality;
    prefix_t prefix;
};

void string_repr_prefix(char *s, prefix_t p){
    int i = 1, j = 0;
    while(i){
        /* this data model implementation requires an end_of_prefix terminator */
        /* this allows for safely looping despite the fact that the size of the array is not kept */
        if(prefixes[j].prefix == END_OF_PREFIX){
            i = 0;
        }
        else if(prefixes[j].prefix == p){
            strcpy(s, prefixes[j].name);
            i = 0;
        }else{
            j++;
        }
    }
}
        
// progress rate - for ability scores
// progress rate - for damage

void print_gear(struct gear g){
    printf("This weapon has the following stats:\nRequired Level: %d\n"
            "Item Level: %d\nBuy Value: %d\nSell Value: %d\nDurability: %d/%d\n"
            "Name: %s\nItem Slot: %s\nPerformance Metric: %d\nGear Tier: %2.1f\n"
            "Strength: %d\nDexterity: %d\nIntellect: %d\nVitality: %d\n"
            "Sockets: %d\nAvailability: %s\n",
            g.required_level, g.item_level, g.buy_value, g.sell_value,
            g.durability_current, g.durability_current, g.name, g.item_slot,
            g.performance_metric, g.gear_tier, g.attribute_strength,
            g.attribute_dexterity, g.attribute_intellect, g.attribute_vitality,
            g.sockets, g.availability);
}

int main(void){
    struct gear g = {.required_level = 1, .item_level = 1, .buy_value = 100,
        .sell_value = 10, .durability_current = 55, .durability_max = 55,
        .name = "Cloth Tunic", .item_slot = "Body", .performance_metric = 1,
        .gear_tier = 0.5, .attribute_strength = 0, .attribute_dexterity = 0,
        .attribute_intellect = 0, .attribute_vitality = 0, .sockets = 0,
        .availability = "all"};
    print_gear(g);
    char *prefix;
    string_repr_prefix(prefix, g.prefix);
    printf("Prefix: %s\n", prefix);

    
    return 0;
}

