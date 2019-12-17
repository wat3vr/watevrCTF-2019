#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

typedef struct{
  char username[30];
  char password[30];
  int isAdmin;
}User;

User* user;

int userid = 0;
int totaluser = 0;
int username_lenght = 35;

void register_user(void){
  int username_lenght = 30;
  fflush(stdin);
  fflush(stdout);
  //printf("Username: ");
  //fflush(stdout);
  fgets((user+totaluser)->username, username_lenght, stdin);
  //printf("Password: ");
  //fflush(stdout);
  fflush(stdin);
  (user+totaluser)->isAdmin = 0;
  fgets((user+totaluser)->password, username_lenght, stdin);
  printf("Succesfully registered user: %s", (user+userid)->username);
  userid = totaluser;
  totaluser++;
}

void login_user(void){
  char opt;
  int i;
  printf("Username: ");
  fflush(stdout);
  fgets((user+totaluser)->username, username_lenght, stdin);
  printf("Password: ");
  fflush(stdout);
  fgets((user+totaluser)->password, username_lenght, stdin);
  strtok((user+totaluser)->username, "\n");
  strtok((user+totaluser)->password, "\n");
  for(i = 0; i < totaluser; i++){
    if(((strcmp("wat-admin", (user+i)->username) == 0) && (strcmp("wat-password", (user+i)->password) == 0)) && ((user+i)->isAdmin == 7823732)){
      printf("Succesfully logged in as user: %s", (user+1)->username);
      userid = i;
      return;
    }
  }
  printf("Incorrect credentials, would you like to register instead?\n");
  printf("[y/n]: ");
  fflush(stdout);
  opt = getchar();
  getchar();
  //free((user+userid)->username);
  //free((user+userid));
  if(opt == 'y'){
    register_user();
  }
}

void introduce(void){
  char opt;
  printf("%s\n", "-- Spott-i-fy terminal based application --");
  //printf("%s", "Register/Login [r/l]: ");
  fflush(stdout);
  opt = getchar();
  getchar();
  fflush(stdin);
  if(opt == 'r'){
    register_user();
  }
  else if(opt == 'l'){
    login_user();
  }
  strtok((user+userid)->username, "\n");
  //printf("Welcome, %s\n", (user+userid)->username);
  fflush(stdout);
}


/*
ALL CODE ABOVE IS FOR: registration and login
*/

typedef struct{
  char *category;
  char *artist;
  char *song1;
  char *song2;
  long *listeners;
  char *secret;
}Artist;

Artist artists[4];

void log_out(Artist* artists);

void menu(){
  //printf("%s\n", "For more information about available categories/artists/songs use wildcard *.");
  //printf("%s\n", "Syntax: Fetch [category] [artist] [song]");
  ;
}

char command_for_logout[8] = {'L', 'o', 'g', 'o', 'u', 't', 0};

void wildcard_print(int type, int index, Artist* artists){
  if(index == -1 && ((user+userid)->isAdmin != 0x776174)){
    switch(type){
      case 0:
        printf("  %s\n", (artists+0)->category);
        printf("  %s\n", (artists+1)->category);
        printf("  %s\n", (artists+2)->category);
        printf("  %s\n", (artists+3)->category);
        break;
      case 1:
        printf("  %s\n", (artists+0)->artist);
        printf("  %s\n", (artists+1)->artist);
        printf("  %s\n", (artists+2)->artist);
        printf("  %s\n", (artists+3)->artist);
        break;
      case 3:
        printf("  %s\n", (artists+0)->song1);
        printf("  %s\n", (artists+1)->song1);
        printf("  %s\n", (artists+2)->song1);
        printf("  %s\n", (artists+3)->song1);
        break;
      case 4:
        printf("  %ld\n", (artists+0)->listeners[0]);
        printf("  %ld\n", (artists+1)->listeners[0]);
        printf("  %ld\n", (artists+2)->listeners[0]);
        printf("  %ld\n", (artists+3)->listeners[0]);
        break;
      default:
        return;
    }
  }
  else if(index == -1 && ((user+userid)->isAdmin == 0x776174)){
     switch(type){
      case 0:
        printf("  %s\n", (artists+0)->category);
        printf("  %s\n", (artists+1)->category);
        printf("  %s\n", (artists+2)->category);
        printf("  %s\n", (artists+3)->category);
        printf("  %s\n", (artists+4)->category);
        break;
      case 1:
        printf("  %s\n", (artists+0)->artist);
        printf("  %s\n", (artists+1)->artist);
        printf("  %s\n", (artists+2)->artist);
        printf("  %s\n", (artists+3)->artist);
        printf("  %s\n", (artists+4)->artist);
        break;
      case 3:
        printf("  %s\n", (artists+0)->song1);
        printf("  %s\n", (artists+1)->song1);
        printf("  %s\n", (artists+2)->song1);
        printf("  %s\n", (artists+3)->song1);
        printf("  %s\n", (artists+4)->song1);
        break;
      case 4:
        printf("  %ld\n", (artists+0)->listeners[0]);
        printf("  %ld\n", (artists+1)->listeners[0]);
        printf("  %ld\n", (artists+2)->listeners[0]);
        printf("  %ld\n", (artists+3)->listeners[0]);
        printf("  %ld\n", (artists+4)->listeners[0]);
        break;
      default:
        return;
    }
  }
  else{
    switch(type){
      case 0:
        printf("%s", (artists+index)->category);
        break;
      case 1:
        printf("%s", (artists+index)->artist);
        break;
      case 3:
        printf("%s", (artists+index)->song1);
        break;
      case 4:
        printf("%ld", (artists+index)->listeners[0]);
        break;
      default:
        return;
    }
  }
}

void make_request(char* arg, char* cat, char* art, char* song, Artist* artists){
  int i, j;
  if(strcmp("Fetch", arg) == 0){
    if(strcmp("*", cat) == 0){
      //category wildcard
      printf("Available categories:\n"),
      wildcard_print(0, -1, artists);
    }
    else if((user+userid)->isAdmin != 7823732){
      for(i = 0; i < 4; i++){
        if(strcmp(cat, (artists+i)->category) == 0){
          if(strlen(art) > 0){
            if(strcmp(art, (artists+i)->artist) == 0){
              strtok(song, "\n");
              if(strcmp(song, (artists+i)->song1) == 0){
                printf("Listeners:");
                printf("  %ld\n", (artists+i)->listeners[0]);
              }
              else if(strcmp(song, (artists+i)->song2) == 0){
                printf("Listeners:");
                printf("  %ld\n", (artists+i)->listeners[1]);
              }
              else{
                printf("Songs:\n");
                printf("  %s\n", (artists+i)->song1);
                printf("  %s\n", (artists+i)->song2);
              }
            }
            else{
              printf("Artist:\n");
              printf("  %s\n", (artists+i)->artist);
            }
          }
          else{
            printf("Artist:\n");
            printf("  %s\n", (artists+i)->artist);
          }
        }
      }
    }
    else if((user+userid)->isAdmin == 7823732){
      for(i = 0; i < 5; i++){
        if(strcmp(cat, (artists+i)->category) == 0){
          if(strlen(art) > 0){
            if(strcmp(art, (artists+i)->artist) == 0){
              strtok(song, "\n");
              if(strcmp(song, (artists+i)->song1) == 0){
                printf("Listeners:");
                printf("  %ld\n", (artists+i)->listeners[0]);
              }
              else if(strcmp(song, (artists+i)->song2) == 0){
                printf("Listeners:");
                printf("  %ld\n", (artists+i)->listeners[1]);
                printf("Secret:");
                printf("  %s\n", (artists+i)->secret);
              }
              else{
                printf("Songs:\n");
                printf("  %s\n", (artists+i)->song1);
                printf("  %s\n", (artists+i)->song2);
              }
            }
            else{
              printf("Artist:\n");
              printf("  %s\n", (artists+i)->artist);
            }
          }
          else{
            printf("Artist:\n");
            printf("  %s\n", (artists+i)->artist);
          }
        }
      }
    }
  }
  else{
    strtok(arg, "\n");
    if(strcmp(arg, command_for_logout) == 0){
      log_out(artists);
    }
  }
}

void fetch_request(Artist* artists){
  int option, i, j, cont = 1;
  char query_arg[32];
  char query_cat[32];
  char query_art[32];
  char query_song[32];
  char tmp;
  int wild = 0;
  int normalize = 1;

  while(cont == 1){
    wild = 0;
    tmp = 0;
    memset(query_arg,0,32);
    memset(query_cat,0,32);
    memset(query_art,0,32);
    memset(query_song,0,32);
    fflush(stdout);
    fflush(stdin);
    if(normalize == 1){
      //printf("Query: ");
      normalize = 0;
    }
    else{
      normalize++;
    }
    fflush(stdout);
    for(i = 0; i < 4 && !wild; i++){
      j = 0;
      while((tmp = getchar()) != ' '){
        switch(i){
          case 0:
            query_arg[j] = tmp;
            break;
          case 1:
            query_cat[j] = tmp;
            break;
          case 2:
            query_art[j] = tmp;
          case 3:
            query_song[j] = tmp;
          default:
            break;
        }
        if(tmp == '*' || tmp == '\n'){
          wild = 1;
          fflush(stdin);
          break;
        }
        else{
          j++;
        }
      }
      switch(i){
        case 0:
          query_arg[j+1] = 0;
          break;
        case 1:
          query_cat[j+1] = 0;
          break;
        case 2:
          query_art[j+1] = 0;
        case 3:
          query_song[j+1] = 0;
        default:
          break;
      }
    }
    //printf("%s\n", query_arg);
    //printf("%s\n", query_cat);
    //printf("%s\n", query_art);
    //printf("%s\n", query_song);
    make_request(query_arg, query_cat, query_art, query_song, artists);
    fflush(stdout);
  }
}
int database_entry(void){
  Artist* artists = malloc(5*sizeof(*artists));
  int i;
  for(i = 0; i < 5; i++){
  //  artists[i].category = (char*) malloc(30*sizeof(char));
  //  artists[i].artist = (char*) malloc(8*30);
  //  artists[i].songs = (char**) malloc(2*8*30);
    artists[i].listeners = (long*)malloc(2* sizeof(long));
  }

  artists->category = strdup("Jazz");
  (artists+1)->category = strdup("Pop");
  (artists+2)->category = strdup("Metal");
  (artists+3)->category = strdup("Reggae");
  (artists+4)->category = strdup("watpop");

  artists->artist = strdup("Mingus");
  (artists+1)->artist = strdup("Malone");
  (artists+2)->artist = strdup("Metallica");
  (artists+3)->artist = strdup("Marley");
  (artists+4)->artist = strdup("KNAAN");

  artists->song1 = strdup("Moanin'");
  (artists+1)->song1 = strdup("Circles");
  (artists+2)->song1 = strdup("Matters");
  (artists+3)->song1 = strdup("Jamming");
  (artists+4)->song1 = strdup("Flag");

  (artists->song2) = strdup("Hat");
  (artists+1)->song2 = strdup("Sunflower");
  (artists+2)->song2 = strdup("Sandman");
  (artists+3)->song2 = strdup("Love");
  (artists+4)->song2 = strdup("𝓯𝓵𝓪𝓰");
  //(artists+4)->secret = strdup("watevr{#####################}");

  artists->listeners[0] = 5299503;
  (artists+1)->listeners[0] = 400792686;
  (artists+2)->listeners[0] = 399045826;
  (artists+3)->listeners[0] = 191297205;
  (artists+4)->listeners[0] = 13371337;

  artists->listeners[1] = 53457429;
  (artists+1)->listeners[1] = 1211980336;
  (artists+2)->listeners[1] = 427853415;
  (artists+3)->listeners[1] = 189906840;
  (artists+4)->listeners[1] = 13371337;
  (artists+4)->secret = strdup("watevr{######################################################}");
  introduce();
  fetch_request(artists);
}

void log_out(Artist* artists){
  printf("Goodbye, %s\n", (user+userid)->username);
  introduce();
  free((user+userid-1)->username);
  free((user+userid-1));
}

void sig(int sign){
	exit(0);
}

int main(void){
  signal(SIGALRM, sig);
  alarm(60);
  user = malloc(6*sizeof(User));
  //menu();
  database_entry();
  free(user);
}
