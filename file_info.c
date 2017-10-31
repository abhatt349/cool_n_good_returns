#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>


int fsize (char *s) {
  struct stat f;
  stat(s, &f);
  return stat.st_size;
}




int main () {
  int f = open("test.txt", O_CREAT | O_WRONLY, 0666);
  char *s = "this is text";
  write (f, s, sizeof(s));
  close(f);
  printf("%d\n", fsize("test.txt"));
  return 0;
}
