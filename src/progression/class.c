#include "../include/library.h"

char *first_class_choosing_function()
{
    printf("Before beginning your journey please choose your class:");
    printf("\n1.Warrior -> Skill: Lunge\n2.Mage -> Skill: Bolt\n3.Thief -> Skill: Guts\n");
    printf("Print the number before the class you want!");
    while(1) {
        char c = getchar();
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
            case '4':
                printf("Choose again!\n");
                break;
        }
    }

}