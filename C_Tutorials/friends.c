#include <stdio.h>
#include <string.h>

struct Friends{
  char name[16];
  int age;
  char gender[8];
  char fav_color[16];
};

typedef struct Friends Friends;

void print_friend(struct Friends f);

int main(){
  Friends f_1 = { "Francis", 23, "Male", "Yellow" };
  Friends f_2 = { "Patience", 21, "Female", "Green" };
  Friends f_3 = { "Imelda", 19, "Female", "Lilac"};

  strcpy(f_1.name, "Francisca");
  strcpy(f_1.gender, "Female");

  print_friend(f_1);
  print_friend(f_2);
  print_friend(f_3);

  return 0;
}

void print_friend(struct Friends f){
  printf("%s is a %d year old %s and likes %s color \n", 
  f.name, f.age, f.gender, f.fav_color);
}