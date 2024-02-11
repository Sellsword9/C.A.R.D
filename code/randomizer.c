#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *first_names[] = {"John", "Jane", "Michael", "Emily", "David", "Sarah", "James", "Mary", "Robert", "Jennifer"};
char *last_names[] = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
char *streets[] = {"Main St", "Elm St", "Oak St", "Maple Ave", "Cedar Ln", "Pine St", "Washington St", "Lake Rd", "Park Ave", "Sunset Blvd"};
unsigned int xorshift_state = 123456789;

void set_seed(unsigned int seed)
{
  xorshift_state = seed;
}

unsigned int xorshift32()
{
  xorshift_state ^= xorshift_state << 13;
  xorshift_state ^= xorshift_state >> 17;
  xorshift_state ^= xorshift_state << 5;
  return xorshift_state;
}

int random_int(int min, int max)
{
  unsigned int range = (unsigned int)(max - min + 1);
  return (int)(min + xorshift32() % range);
}
void generate_fake_phone(char *phone)
{
  sprintf(phone, "%d-%d-%d",
          random_int(100, 999),
          random_int(100, 999),
          random_int(100, 999));
}

void generate_fake_name(char *name)
{
  sprintf(name, "%s %s", first_names[random_int(0, 9)], last_names[random_int(0, 9)]);
}

void generate_fake_direction(char *direction)
{
  sprintf(direction, "%d %s, %s, %s",
          random_int(100, 9999), streets[random_int(0, 9)],
          "Cityville", "State");
}

int main()
{
  int i = 0;
  srand(time(NULL));
  char phone[15], name[50], direction[100];
  while (i < __INT_MAX__ - 1)
  {
    i++;
    generate_fake_phone(phone);
    generate_fake_name(name);
    generate_fake_direction(direction);
    printf("Name: %s\n", name);
    printf("  Phone: %s\n", phone);
    printf("  Direction: %s\n", direction);
  }
  return 0;
}
