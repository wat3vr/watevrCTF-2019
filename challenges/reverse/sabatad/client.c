#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define PORT 1337
#define SA struct sockaddr

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

void grab_random_entry(int sockfd){
  time_t t;
  char name[200];
  char entries[5];
  char req[200] = "Fetch from file with index";
  char file[200] = "/home/ctf/database.txt";
  int amount;
  int n,i,j,k,l;
  char raw[200] = "________________________________________________________________________________________________________________________________________________________________________________";

  printf("%s", "Please enter name: ");
  fgets(name, 50, stdin);
  strtok(name, "\n");
  srand((unsigned) time(&t));
  printf("thanks, %s\n", name);
  n = 0;
  i = 0;
  j = 0;
  k = 0;
  l = 0;
  for(n = 0; 100; n += 3){
    if(i < strlen(req)){
      raw[n] = req[i];
      i += 1;
    }
    else{
      break;
    }
  }
  for(n = 1; 100; n += 3){
    if(j < strlen(name)){
      raw[n] = name[j];
      j += 1;
    }
    else{
      break;
    }
  }
  for(n = 2; 100; n += 3){
    if(k < strlen(file)){
      raw[n] = file[k];
      k += 1;
    }
    else{
      break;
    }
  }
  for(n = 0; n < 151; n++){
    raw[n] = rot13(raw[n]);
  }
  sprintf(entries, "%d", (int)(rand() % 100));
  raw[151] = entries[0];
  raw[152] = entries[1];
  raw[153] = entries[3];
  raw[154] = '\n';
  raw[155] = '\x00';
  write(sockfd, raw, sizeof(raw));
  bzero(raw, sizeof(raw));
  read(sockfd, raw, sizeof(raw));
  printf("Database returned: %s\n", raw);
}

int main(void){
  int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("%s\n", "Failed to create socket to database");
        exit(0);
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0){
      printf("%s\n", "Failed to connect to database");
      exit(0);
    }
    grab_random_entry(sockfd);
    close(sockfd);
}
