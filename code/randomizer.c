#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_int(int min, int max)
{
  return min + rand() % (max - min + 1);
}

void generate_fake_phone(char *phone)
{
  sprintf(phone, "%d%d%d-%d%d%d-%d%d%d%d",
          random_int(2, 9), random_int(0, 9), random_int(0, 9),
          random_int(2, 9), random_int(0, 9), random_int(0, 9),
          random_int(0, 9), random_int(0, 9), random_int(0, 9), random_int(0, 9));
}

void generate_fake_name(char *name)
{
  char *first_names[] = {"John", "Jane", "Michael", "Emily", "David", "Sarah", "James", "Mary", "Robert", "Jennifer"};
  char *last_names[] = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
  sprintf(name, "%s %s", first_names[random_int(0, 9)], last_names[random_int(0, 9)]);
}

void generate_fake_direction(char *direction)
{
  char *streets[] = {"Main St", "Elm St", "Oak St", "Maple Ave", "Cedar Ln", "Pine St", "Washington St", "Lake Rd", "Park Ave", "Sunset Blvd"};
  sprintf(direction, "%d %s, %s, %s",
          random_int(100, 9999), streets[random_int(0, 9)],
          "Cityville", "State");
}

int main()
{
  srand(time(NULL));

  char phone[15], name[50], direction[100];
  generate_fake_phone(phone);
  generate_fake_name(name);
  generate_fake_direction(direction);

  printf("Fake Name: %s\n", name);
  printf("Fake Phone: %s\n", phone);
  printf("Fake Direction: %s\n", direction);

  return 0;
}
