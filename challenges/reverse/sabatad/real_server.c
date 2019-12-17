#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

int rot13(int c){
  if('a' <= c && c <= 'z'){
    return rot13b(c,'a');
  } else if ('A' <= c && c <= 'Z') {
    return rot13b(c, 'A');
  } else {
    return c;
  }
}

int rot13b(int c, int basis){
  c = (((c-basis)+13)%26)+basis;
  return c;
}

void database(){
  char request[50];
  char name[50];
  char file_r[50];
  char index_c[6];
  int index = 0;

  char raw[200];
  int n, i, j, k, l;

  char line[256];
  char sendback[256];
  FILE *fptr;

  while(strcmp(request, "terminate") != 0){
    fflush(stdin);
    fflush(stdout);
    bzero(raw, 200);
    bzero(request, 50);
    bzero(index_c,6);

    fgets(raw, 200, stdin);
    i = 0;
    j = 0;
    k = 0;
    l = 0;

    for(n = 0; n < 155; n++){
      raw[n] = rot13(raw[n]);
      if((n > 150) && (n < 155)){
        index_c[l] = raw[n];
        l++;
      }
      else if(n > 155){
        break;
      }
      else if((n % 3 == 0)){
        if(raw[n] != '_')
          request[i] = raw[n];
        i++;
      }
      else if((n % 3 == 1)){
        if(raw[n] != '_')
          name[j] = raw[n];
        j++;
      }
      else if((n % 3 == 2)){
        if(raw[n] != '_')
          file_r[k] = raw[n];
        k++;
      }
    }
    index = atoi(index_c);
    if((strcmp("watevr-admin", name) != 0) || (strcmp("/home/ctf/flag.txt", file_r) == 0)){
      printf("%s\n", "Unauthorized access! This has been logged.");
      exit(0);
    }
    fflush(stdout);
    if(strcmp("Fetch from file with index", request) == 0){
      glob_t globbuf;
      glob(file_r, 0, NULL, &globbuf);
      if((fptr = fopen(globbuf.gl_pathv[0], "r")) == NULL){
        printf("%s\n", "Tried to open non-existing file!");
      }
      else{
        i = 0;
        while(fgets(line, sizeof(line), fptr) != NULL){
          if(i == index){
            break;
          }
          else{
            i++;
          }
        }
        globfree(&globbuf);
        printf("Found %s\n", line);
        fclose(fptr);
      }
    }
  }
  printf("%s\n", "Terminated connection");
}

void sig(int sign){
	exit(0);
}

int main(void){
  signal(SIGALRM, sig);
  alarm(20);
  database();
}