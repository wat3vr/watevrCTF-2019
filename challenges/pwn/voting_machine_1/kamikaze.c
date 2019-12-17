#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <signal.h>

void super_secret_function(){
  FILE *f;
  char c;
  f = fopen("/home/ctf/flag.txt", "r");
  if(f == NULL){
      printf("Cannot open flag.txt\n");
      exit(1);
  }
  c = fgetc(f);
  while(c != EOF){
      printf ("%c", c);
      c = fgetc(f);
  }
  fclose(f);
  exit(0);
}

void sig(int sign){
	exit(0);
}

int main(){
  signal(SIGALRM, sig);
  alarm(40);
  char input[2];
  printf("Hello and welcome to \e[3mour\e[23m voting application!\n");
  printf("Today's vote will be regarding the administration of\n");
  printf("watevr CTF.\n");
  printf("the voting range is 0 to 10. 0 being the worst possible and 10 being the best possible.\n");
  printf("Thanks!\n");
  printf("Vote: ");
  fflush(stdout);
  gets(input);
  printf("Thanks for voting!\n");
  return 0;
}
