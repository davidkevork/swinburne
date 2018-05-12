#include <stdio.h>
#include <stdlib.h>

struct dog {
    char dog_name[256];
    int dog_id;
    int dog_age;
};

struct dog_array {
    int size;
    struct dog *ptr;
};

void add_dog_details(struct dog_array *sample);
void get_dog(struct dog *details);
void print_dog_details(struct dog_array *sample);

int main() {
    struct dog_array sample = {0, NULL};
    int options = 0;
    do {
        printf("\nEnter option: ");
        scanf("%i", &options);
        switch (options) {
            case 1:
                add_dog_details(&sample);
                break;
            case 2:
                print_dog_details(&sample);
                break;
            case 3:
                free(sample.ptr);
                break;
            default:
                options = 0;
                break;
        }
    } while (options != 3);
    return 0;
}

void add_dog_details(struct dog_array *sample) {
    struct dog *new_array;
    sample->size++;
    new_array = (struct dog*) realloc(sample->ptr, sample->size * sizeof(struct dog));
    if (new_array) {
        sample->ptr = new_array;
        get_dog(&sample->ptr[sample->size-1]);
    } else {
        printf("Out of memory! Cannot add dog details!\n");
        sample->size--;
    }
}

void get_dog(struct dog *details) {
    printf("Enter dog name: ");
    scanf("%s", details->dog_name);
    printf("Enter dog id: ");
    scanf("%i", &details->dog_id);
    printf("Enter dog age: ");
    scanf("%i", &details->dog_age);
}

void print_dog_details(struct dog_array *sample) {
    for (int i = 0; i < sample->size; ++i) {
        printf("Dog name: %s\nDog id: %d\nDog Age: %d\n\n",
                sample->ptr[i].dog_name, sample->ptr[i].dog_id, sample->ptr[i].dog_age);
    }
}
