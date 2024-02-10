#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main()
{
  char buffer[BUFFER_SIZE];
  FILE *file;
  file = fopen("output/output.txt", "wb");

  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  printf("C.A.R.D is working. Press Ctrl+C at any time to stop.\n");

  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, stdin)) > 0)
  {
    fwrite(buffer, 1, bytes_read, file);
  }

  printf("Text successfully written to file.\n");

  fclose(file);

  return 0;
}
