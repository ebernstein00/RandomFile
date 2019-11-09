#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(){
  int fd1 = open("/dev/random", O_RDONLY);
  int fd2 = open("file.txt", O_RDWR | O_CREAT, 0644);
  return 0;
