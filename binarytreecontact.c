#include "binarytreecontact.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define HOBBY_LENGTH 50
#define HOBBY_COUNT 5

typedef enum {
    MALE, FEMALE, OTHER
} Gender;

typedef struct Person {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    int age;
    float height;
    double weight;
    Gender gender;
    char hobbies[HOBBY_COUNT][HOBBY_LENGTH]; // Array that can store up to 5 hobbies
    struct Person *mother;
    struct Person *father;
    struct Person *left;
    struct Person *right;
} Person;

// A function that works like printf but automatically adds a newline at the end.
void printf_newline(const char *format, ...) {
    va_list args;
    va_start(args, format);     // Initialize the variable argument list
    vprintf(format, args);      // Call vprintf with the variable arguments
    va_end(args);               // Clean up the variable argument list

    printf("\n");               // Add a newline at the end
}

void generateRandomName(char *name, int length) {
    // Define vowels and consonants
    char vowels[] = "aeiou";
    char consonants[] = "bcdfghjklmnpqrstvwxyz";

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            // Choose a consonant for even indices
            name[i] = consonants[rand() % (sizeof(consonants) - 1)];
        } else {
            // Choose a vowel for odd indices
            name[i] = vowels[rand() % (sizeof(vowels) - 1)];
        }
    }

    name[0] = toupper(name[0]); // Convert the first character to uppercase
    name[length] = '\0'; // Add null character at the end of the string
}

void generateRandomPhone(char *phone) {
    for (int i = 0; i < PHONE_LENGTH - 1; i++) {
        if (i == 0) {
            phone[i] = '+';
        } else if (i == 5 || i == 10) {
            phone[i] = '-';
        } else {
            // Convert numbers from 0 to 9 to characters and store them
            phone[i] = '0' + (rand() % 10);
        }
    }
    phone[PHONE_LENGTH - 1] = '\0';
}

Person *creatPerson(char *name, char *phone) {
    Person *person = (Person *) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // set values of person
    int size = sizeof(name) / sizeof(int);
    strcpy(person->name, name);
    strcpy(person->phone, phone);
    person->left = NULL;
    person->right = NULL;

    return person;
}

Person *addPerson(Person *root, char *name, char *phone) {
    // If the tree is empty, create a new person and return it as the new root.
    if (root == NULL) {
        return creatPerson(name, phone);
    }
    // If the name is lexicographically smaller than the current node's name,
    if (strcmp(name, root->name) < 0) {
        root->left = addPerson(root->left, name, phone);
    }
        // If the name is lexicographically larger than the current node's name,
    else if (strcmp(name, root->name) > 0) {
        root->right = addPerson(root->right, name, phone);
    }
    // If the name already exists, do not allow duplicate entries.
    return root;
}

void inorderTraversal2(Person *root) {
    if (root != NULL) {
        inorderTraversal2(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        inorderTraversal2(root->right);
    }
}

// Function to search for a person by name in a binary search tree.
Person *searchPerson(Person *root, char *name, bool print) {
    // Base case: if root is NULL, the search ends without finding the person.
    if (root == NULL) {
        printf("Person not found.\n");
        return NULL;
    }
    // If the name matches, print the person's information.
    if (strcmp(root->name, name) == 0) {
        if (print) {
            printf("Name: %s, Phone: %s\n", root->name, root->phone);
            printf("Age: %d, Height: %.1f, Weight: %.2lf Gender: %u\n", root->age, root->height, root->weight,
                   root->gender);
            printf("Hobbies: ");
            for (int i = 0; i < HOBBY_COUNT; i++) {
                printf("%s, ", root->hobbies[i]);
            }
            printf("\n");
        }
        return root;
    }
        // If the given name is lexicographically smaller than the current node's name,
    else if (strcmp(name, root->name) < 0) {
        return searchPerson(root->left, name, print);
    }
        // If the given name is lexicographically larger than the current node's name,
    else if (strcmp(name, root->name) > 0) {
        return searchPerson(root->right, name, print);
    }
    // If none of the conditions are met, return NULL.
    return NULL;
}

void deleteAll(Person *root) {
    if (root != NULL) {
        deleteAll(root->left);
        deleteAll(root->right);
        free(root);
    }
}

Person *minPerson(Person *root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Person *deletePerson(Person *root, char *name) {
    if (strcmp(name, root->name) < 0) {
        root->left = deletePerson(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deletePerson(root->right, name);
    } else { // if person matched
        // root has one child
        if (root->left == NULL) {
            Person *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Person *temp = root->left;
            free(root);
            return temp;
        } else {
            // root has two child
            Person *temp = minPerson(root->right);
            strcpy(root->name, temp->name);
            strcpy(root->phone, temp->phone);
            // delete person at the right
            root->right = deletePerson(root->right, temp->name);
            return root;
        }
    }
    // no person searched
    return root;
}

void printTree(Person *root, int space) {
    if (root == NULL) return;

    space += 5; // Increase space per level

    // Output right subtree first
    printTree(root->right, space);

    // output current node
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%s\n", root->name);

    // output left subtree
    printTree(root->left, space);
}

void addPersonality(Person *target, char *name, int a, float h, double w, int g, char b[][HOBBY_LENGTH]) {
    if (target != NULL) {
        target->age = a;
        target->height = h;
        target->weight = w;
        switch (g) {
            case 0:
                target->gender = MALE;
                break;
            case 1:
                target->gender = FEMALE;
                break;
            case 2:
                target->gender = OTHER;
                break;
            default:
                printf("Invalid gender selected. Defaulting to OTHER.\n");
                target->gender = OTHER;
        }
        for (int i = 0; i < HOBBY_COUNT; i++) {
            strcpy(target->hobbies[i], b[i]);
        }
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Clear input buffer
}

int startTreeContact() {
    int selection = -1;
    int age = 0;
    float height = 0;
    double weight = 0;
    int genderInput = -1;
    char hobbies[HOBBY_LENGTH][NAME_LENGTH] = {0};
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    Person *root = NULL;
    do {
        printf("1: Add person\n");
        printf("2: Serach person\n");
        printf("3: Print person\n");
        printf("4: InorderTraversal\n");
        printf("5: Add 10 random person\n");
        printf("6: Add age, height, weight, hobby\n");
        printf("7: Add parents\n");
        printf("0: Programm Exit\n");
        printf("Eingabe:");
        scanf("%d", &selection);

        switch (selection) {
            case 0:
                deleteAll(root);
                return 0;
            case 1:
                printf("Name:");
                scanf("%49s", name);
                printf("Phone:");
                scanf("%14s", phone);
                root = addPerson(root, name, phone);
                break;
            case 2:
                printf("Name:");
                scanf("%49s", name);
                searchPerson(root, name, true);
                break;
            case 3:
                printTree(root, 0);
                break;
            case 4:
                inorderTraversal2(root);
                break;
            case 5:
                srand((unsigned int) time(NULL));
                for (int i = 0; i < 10; i++) {
                    generateRandomName(name, 6);
                    generateRandomPhone(phone);
                    root = addPerson(root, name, phone);
                }
                break;
            case 6:
                printf("Name:");
                scanf("%49s", name);
                clearInputBuffer();

                Person *target = searchPerson(root, name, false);
                if (target == NULL) {
                    printf("Try again.\n");
                    continue;
                }
                printf("Age:");
                scanf("%d", &age);
                clearInputBuffer();

                printf("Height:");
                scanf("%f", &height);
                clearInputBuffer();

                printf("Weight:");
                scanf("%lf", &weight);
                clearInputBuffer();

                printf("Select gender (0 for Male, 1 for Female, 2 for Other): ");
                scanf("%d", &genderInput);
                clearInputBuffer();

                printf("5 Hobby:\n");
                for (int i = 0; i < HOBBY_COUNT; i++) {
                    fgets(hobbies[i], HOBBY_LENGTH, stdin);
                    hobbies[i][strcspn(hobbies[i], "\n")] = '\0'; // Remove trailing newline
                }
                addPersonality(target, name, age, height, weight, genderInput, hobbies);
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                printf("Invalid value\n");
        }
    } while (selection);

    return 0;
}
