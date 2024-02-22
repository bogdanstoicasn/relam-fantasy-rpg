#include "load.h"

/*
    Generate the T1 class
*/
char *first_class_choosing_function()
{
    printf("Before beginning your journey please choose your class:");
    printf("\n1.Warrior -> Skill: Lunge\n2.Mage -> Skill: Bolt\n3.Thief -> Skill: Guts\n");
    printf("Introduce the number before the class you want!\n");
    while(1) {
        char c = getchar();

        // clean the buffer
        int remaining_buffer;
        while((remaining_buffer = getchar()) != '\n' && remaining_buffer != EOF);

        char *class;
        switch(c) {
            case '1':
                class = malloc(PADDING_8);
                if (!class)
                    DIE(1, "error allocating memory for class");
                memcpy(class, "Warrior", 7);
                class[7] = '\0';
                return class;
            case '2':
                class = malloc(5);
                if (!class)
                    DIE(1, "error allocating memory for class");
                memcpy(class, "Mage", 4);
                class[4] = '\0';
                return class;
            case '3':
                class = malloc(6);
                if (!class)
                    DIE(1, "error allocating memory for class");
                memcpy(class, "Thief", 5);
                class[5] = '\0';
                return class;
            default:
                fflush(stdout);
                printf("Choose again!\n");
                break;
        }
    }

}

// CLASS UTILITIES
/*
    Loads the classes in the database
*/
void read_class_data(database *game_database, FILE *fptr)
{
    char buff[PADDING_128];
    if (!fgets(buff, PADDING_128, fptr))
        DIE(1, "error reading from file");

    size_t number = atoi(buff);

    game_database->classes_data.number = number;
    game_database->classes_data.classes = malloc(number * sizeof(class_info));


    for (size_t i = 0; i < number; ++i) {
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Name: %[^\n]", game_database->classes_data.classes[i].class_name);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Tier: %ld", &game_database->classes_data.classes[i].class_tier);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Health: %ld", &game_database->classes_data.classes[i].class_stats.health);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Attack: %ld", &game_database->classes_data.classes[i].class_stats.attack);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Magic: %ld", &game_database->classes_data.classes[i].class_stats.magic);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Defense: %ld", &game_database->classes_data.classes[i].class_stats.defense);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Resistance: %ld", &game_database->classes_data.classes[i].class_stats.resistance);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Dodge: %ld", &game_database->classes_data.classes[i].class_stats.dodge);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading from file");
        sscanf(buff, "Class Passives: %ld", &game_database->classes_data.classes[i].passives);

        for (size_t j = 0; j < game_database->classes_data.classes[i].passives; ++j) {
            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading from file");
            strcpy(game_database->classes_data.classes[i].class_passives[j], buff);
        }
    }
}

/*
    Print all the classes in the database
*/
void print_all_classes(class_database data)
{
    for (size_t i = 0; i < data.number; ++i) {
        printf("Class Name: %s\n", data.classes[i].class_name);
        printf("Class Tier: %ld\n", data.classes[i].class_tier);
        printf("Class Health: %ld\n", data.classes[i].class_stats.health);
        printf("Class Attack: %ld\n", data.classes[i].class_stats.attack);
        printf("Class Magic: %ld\n", data.classes[i].class_stats.magic);
        printf("Class Defense: %ld\n", data.classes[i].class_stats.defense);
        printf("Class Resistance: %ld\n", data.classes[i].class_stats.resistance);
        printf("Class Dodge: %ld\n", data.classes[i].class_stats.dodge);
        printf("Class Passives: %ld\n", data.classes[i].passives);
        for (size_t j = 0; j < data.classes[i].passives; ++j) {
            printf("Class Passive: %s\n", data.classes[i].class_passives[j]);
        }
    }

}
// CLASS UTILITIES