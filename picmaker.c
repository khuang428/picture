#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
  int r,g,b,i,j;
  int fd = open("pic.ppm", O_CREAT | O_TRUNC | O_RDWR, 0644);
  char info[15];

  sprintf(info, "P3 500 500 255\n");
  write(fd, info, strlen(info));

  for(i = 0;i < 500;i++){
    for(j = 0;j < 500;j++){
      r = (i % 256 + j % 128);
      g = (i % 128 + j % 64);
      b = (i % 64 + j % 32);
      sprintf(info, "%d %d %d\n", r, g, b);
      write(fd, info, strlen(info));
    }
  }

  close(fd);
}
