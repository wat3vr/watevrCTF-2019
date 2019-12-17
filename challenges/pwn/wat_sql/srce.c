#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

typedef struct{
  char activationcode[30];
  int isAuthorized;
} Auth_s;


// GLOBAL
pthread_t k_0;
pthread_t k_1;

char e_0[128];
char e_1[10];
int e_2;

int a_0 = 0;
char a_1[20];
char a_2[200];

int a_3 = 0;

Auth_s *auth_user;

// GLOBAL

void * f_4(void){
  char c_2[200];
  int c_9= 0;

  FILE *q_0;
  q_0 = fopen(e_0, "r");

  while(fgets(c_2, sizeof(c_2), q_0) != NULL){
    if(c_9== e_2){
      break;
    }
    else{
      c_9++;
    }
  }
  strtok(c_2, "\n");
  printf("Data: %s\n", c_2);
  fclose(q_0);
  a_0 = 0;
}

void * f_3(void){
  a_0 = 0;
  FILE * q_0;
  FILE * q_1;
  char c_0[100];
  int c_1 = 0;
  fflush(stdin);

  if(access("/home/ctf/replace.tmp", F_OK) != -1 ) {
    remove("/home/ctf/replace.tmp");
  }

  q_0 = fopen(e_0, "r");
  q_1 = fopen("replace.tmp", "w");
  if (q_0 == NULL || q_1 == NULL){
    printf("%s\n", "Unable to open file.");
    return;
  }
  while ((fgets(c_0, 100, q_0)) != NULL){
        /* If current c_2 is c_2 to replace */
        if (c_1 == e_2)
            fputs(a_2, q_1);
        else
            fputs(c_0, q_1);
        c_1++;
  }
  fclose(q_0);
  fclose(q_1);
  remove(e_0);

  rename("/home/ctf/replace.tmp", e_0);
}

void f_2(void){
  printf("%s", "database to read from: ");
  fflush(stdout);
  fgets(e_0, 100, stdin);
  strtok(e_0, "\n");
  if(((strstr(e_0, "flag") == NULL) && (strstr(e_0, "*") == NULL) && (strstr(e_0, "?") == NULL)) || a_0){
    a_0 = 1;
    if(access(e_0, F_OK ) == -1){
      printf("%s\n", "Tried to open non-existing database");
      return;
    }
  }
  else{
    printf("%s\n", "You are not allowed access to that database!");
    a_0 = 0;
    return;
  }
  printf("%s", "database to read: ");
  fflush(stdout);
  fgets(e_1, 7, stdin);
  e_2 = atoi(e_1)+1;
  pthread_create(&k_1, NULL, f_4, NULL);
  pthread_join(k_1, NULL);
  a_0 = 0;
}

void f_1(void){
  printf("%s", "database to write to: ");
  fflush(stdout);
  fgets(e_0, 100, stdin);
  strtok(e_0, "\n");
  if(((strstr(e_0, "flag") == NULL) && (strstr(e_0, "*") == NULL) && (strstr(e_0, "?") == NULL)) || a_0){
    a_0 = 1;
    if(access(e_0, F_OK ) == -1){
      printf("%s\n", "Tried to open non-existing database");
      return;
    }
  }
  else{
    printf("%s\n", "You are not allowed access to that database!");
    a_0 = 0;
    return;
  }
  printf("%s", "Database to write to: ");
  fflush(stdout);
  fgets(e_1, 8, stdin);
  printf("%s", "Data to write: ");
  fflush(stdout);
  fgets(a_2, 200, stdin);
  e_2 = atoi(e_1);
  pthread_create(&k_0, NULL, f_3, NULL);
}

void f_0(){
  while(1 == 1){
    printf("%s", "Query: ");
    fflush(stdout);
    fgets(a_1, 20, stdin);
    if(strstr(a_1, "read") != NULL){
      a_3++;
      if(a_3 > 2){
        printf("You have exhausted the request limit for your wat-sql demo!");
        __asm__ __volatile__("\
            push gets\n\
            push $0\n\
            push 0x0000000000401276\n\
            ret\n\
        ");
      }
      f_2();
    }
    else if(strstr(a_1, "write") != NULL){
      f_1();
      a_3++;
      if(a_3 > 2){
        printf("You have exhausted the request limit for your wat-sql demo!");
        __asm__ __volatile__("\
            push gets\n\
            push $0\n\
            push 0x0000000000401276\n\
            ret\n\
        ");
      }
    }
    else{
      printf("%s\n", "Unrecognised command!");
    }
  }
}

void exitfunc(int sig){
	exit(0);
}

void validate_demo_activation_code(void){
  printf("%s", "Demo activation code: ");
  fflush(stdout);
  fgets(auth_user->activationcode, 36, stdin);
  if(strcmp("watevr-sql2019-demo-code-admin", auth_user->activationcode) == 0 && auth_user->isAuthorized == 0x796573){
    printf("%s\n", "Demo access granted!");
  }
  else{
    printf("%s\n", "Demo access not granted!");
  }
}

int main(){
  auth_user = (Auth_s *) malloc(0x20);
  auth_user->isAuthorized == 0x41414141;
  signal(SIGALRM, exitfunc);
  alarm(40);
  validate_demo_activation_code();
  if(auth_user->isAuthorized == 0x796573){
    printf("%s\n", "Welcome to wat-sql!");
    printf("%s\n", "This project was made as an extention to the super successful project, sabataD!");
    printf("%s\n", "Valid queries are read, write. You are only allowed to access /home/ctf/database.txt!");
    __asm__ __volatile__("\
        push gets\n\
        push $0\n\
        push exit\n\
        push $0x000000000040115f\n\
        ret\n\
    ");
  }
  exit(0);
}
