#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void super_secret_function(){
  FILE *f;
  char c;
  f = fopen("/home/ctf/flag.txt", "r");
  if(f == NULL){
      printf("Cannot open flag.txt\n");
  }
  c = fgetc(f);
  while(c != EOF){
      printf ("%c", c);
      c = fgetc(f);
  }
  fflush(stdout);
  fclose(f);
}

void exit_f(int sign){
	exit(0);
}

int main(){
  signal(SIGALRM, exit_f);
  alarm(5);
  char input[50];
  printf("Hello and welcome to \e[3mour\e[23m voting application!\n");
  printf("We noticed that there occured a slight buffer overflow in the previous version.\n");
  printf("Now we never return, so the problem should be solved? Right?\n");
  printf("Today you are the one who decides what we will vote about.\n\n");
  printf("Topic: ");

  fflush(stdin);
  fflush(stdout);
  scanf("%[^\n]%*c", input);
  printf(input);

  printf("\nWill be the voting topic of today!\n");
  exit(0);
}
