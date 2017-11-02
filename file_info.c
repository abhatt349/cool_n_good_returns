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
  return f.st_size;
}

int fperms (char *s) {
  struct stat f;
  stat(s, &f);
  return f.st_mode;
}

char *ftime (char *s) {
  struct stat f;
  stat(s, &f);
  return ctime(&f.st_atime);
}




int main () {
  umask(0);
  int f = open("test.txt", O_CREAT | O_WRONLY, 0666);
  char *s = "this is text\n";
  write (f, s, strlen(s));
  close(f);
  printf("test.txt is %d bytes\n", fsize("test.txt"));
  printf("File permissions: %o\n", fperms("test.txt"));
  printf("Last time accessed: %s\n", ftime("test.txt"));
  return 0;
}
