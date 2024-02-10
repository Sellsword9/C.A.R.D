#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main()
{
  char buffer[BUFFER_SIZE];
  FILE *file;

  // Open file in binary write mode
  file = fopen("output/output.txt", "wb");

  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  printf("Enter text to write into the file (press Ctrl+D to finish):\n");

  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, stdin)) > 0)
  {
    // Write buffer to the file
    fwrite(buffer, 1, bytes_read, file);
  }

  printf("Text successfully written to file.\n");

  // Close the file
  fclose(file);

  return 0;
}