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
                memcpy(class, "Warrior", 7);
                class[7] = '\0';
                return class;
            case '2':
                class = malloc(5);
                memcpy(class, "Mage", 4);
                class[4] = '\0';
                return class;
            case '3':
                class = malloc(6);
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