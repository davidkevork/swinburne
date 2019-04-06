#include <stdio.h>

struct Animal {
  char name[255];
  int id;
  int age;  
};

struct Animal read_animal() {
  struct Animal temp;
  printf("Enter animal name: ");
  scanf("%s", temp.name);
  printf("Enter animal id: ");
  scanf("%i", &temp.id);
  printf("Enter animal age: ");
  scanf("%i", &temp.age);
  while(temp.age < 0) {
    printf("Re-enter animal age: ");
    scanf("%i", &temp.age);
  }
  printf("\n");
  return temp;
}

void print_animal(struct Animal animal) {
  printf("%s (%i) %i\n", animal.name, animal.id, animal.age);
  animal.age < 5 ? printf("yound animal\n") : printf("old animal\n");
}

float average_animal_age(struct Animal animal[], int size) {
  float avg = 0;
  for (int i = 0; i < size; i++) { avg += animal[i].age; }
  return avg / size;
}

int animal_index_search(struct Animal animal[], int id, int size) {
  for (int i = 0; i < size; i++) { if (animal[i].id == id) return i; }
  return -1;
}
 
int main(int argc, char const *argv[]) {
  struct Animal animal_array1[4], animal_array2[8];
  printf("-- Enter Array 1 Animal Data –-\n\n");
  for (int i = 0; i < 4; i++) { animal_array1[i] = read_animal(); }
  printf("-- Enter Array 2 Animal Data –-\n\n");
  for (int i = 0; i < 8; i++) { animal_array2[i] = read_animal(); }
  printf("-- Animal Array 1 --\n\n");
  for (int i = 0; i < 4; i++) { print_animal(animal_array1[i]); }
  printf("-- Animal Array 2 --\n\n");
  for (int i = 0; i < 8; i++) { print_animal(animal_array2[i]); }
  printf("Average: %f\n", average_animal_age(animal_array2, 8));
  int i = animal_index_search(animal_array2, 101, 8);
  i == -1 ? printf("array 2 does not contain an animal with id 101\n") : print_animal(animal_array2[i]);
  return 0;
}
