#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  printf("pid %d\n", (int)getpid());
  int rc = fork();
  if(rc < 0){
    exit(1);
  } else if(rc == 0){
    printf("i am child, pid %d\n", (int)getpid());
  } else {
    int wc = wait(NULL);
    printf("i am parent of pid %d, pid %d\n", rc, (int)getpid());
  }
  return 0;
}
