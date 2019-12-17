#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>

void authenticate(char* alphabet,char* flag, int len){
  alphabet = "abcdefghijklmnopqrstuvwxyz_! ";
  char password[len+1];
  char congratulate[40] = {
    alphabet[22], alphabet[14], alphabet[14], alphabet[14], alphabet[14], alphabet[14], alphabet[14], alphabet[14], alphabet[22], alphabet[22], alphabet[14], alphabet[14], alphabet[14], alphabet[14], alphabet[14], alphabet[14], alphabet[14], alphabet[22],alphabet[28],
    alphabet[2], alphabet[14], alphabet[13], alphabet[6], alphabet[17], alphabet[0], alphabet[19], alphabet[20], alphabet[11], alphabet[0], alphabet[19], alphabet[8], alphabet[14], alphabet[13], alphabet[18], alphabet[27], alphabet[28], alphabet[23], alphabet[3],'\0'
  };

  printf("%s", "Input password: ");
  fflush(stdout);
  fgets(password, len+1, stdin);
  strtok(password, "\n");

  for(int i = 0; i < len; i++){
    char tmp1[2] = {password[i], '\0'};
    char tmp2[2] = {flag[i] ^ i, '\0'};
    if(strcmp(tmp1, tmp2) != 0){
      printf("%s\n", "Sorry, incorrect password!");
      exit(0);
    }
  }
  printf("%s\n", congratulate);
}

int createProgram(int b1, int b2, int b3, int b4){
  if((b1 ^ 1) & 0xff == 0){
    if((b2 ^ 1) & 0xff != 0){
      if((b3 ^ 1) & 0xff != 0){
        if((b4 ^ 1) & 0xff == 0){
          printf(";)\n");
          return 0;
        }
      }
    }
  }
  char password[51];
  char *a = "wabcdefglhijkmqnoprvstuzxy_!{}.1234567890 ";
  char flag[51];
  flag[0] = a[0] ^ 0;
  flag[2] = a[21] ^ 2;
  flag[3] = a[5] ^ 3;
  flag[6] = a[28] ^ 6;
  flag[13] = a[26] ^ 13;
  flag[8] = a[9] ^ 8;
  flag[5] = a[18] ^ 5;
  flag[11] = a[12] ^ 11;
  flag[1] = a[1] ^ 1;
  flag[10] = a[15] ^ 10;
  flag[9] = a[34] ^ 9;
  flag[12] = a[35] ^ 12;
  flag[47] = a[5] ^ 47;
  flag[16] = a[3] ^ 16;
  flag[15] = a[34] ^ 15;
  flag[4] = a[19] ^ 4;
  flag[20] = a[7] ^ 20;
  flag[23] = a[16] ^ 23;
  flag[32] = a[1] ^ 32;
  flag[24] = a[18] ^ 24;
  flag[14] = a[9] ^ 14;
  flag[18] = a[31] ^ 18;
  flag[21] = a[26] ^ 21;
  flag[31] = a[9] ^ 31;
  flag[22] = a[6] ^ 22;
  flag[7] = a[21] ^ 7;
  flag[34] = a[12] ^ 34;
  flag[17] = a[12] ^ 17;
  flag[19] = a[15] ^ 19;
  flag[40] = a[18] ^ 40;
  flag[26] = a[20] ^ 26;
  flag[33] = a[3] ^ 33;
  flag[25] = a[26] ^ 25;
  flag[29] = a[22] ^ 29;
  flag[27] = a[40] ^ 27;
  flag[42] = a[16] ^ 42;
  flag[37] = a[7] ^ 37;
  flag[28] = a[11] ^ 28;
  flag[39] = a[16] ^ 39;
  flag[35] = a[10] ^ 35;
  flag[36] = a[15] ^ 36;
  flag[48] = a[1] ^ 48;
  flag[30] = a[26] ^ 30;
  flag[51] = '\0';
  flag[43] = a[11] ^ 43;
  flag[44] = a[22] ^ 44;
  flag[45] = a[30] ^ 45;
  flag[38] = a[6] ^ 38;
  flag[50] = a[29] ^ 50;
  flag[49] = a[13] ^ 49;
  flag[41] = a[20] ^ 41;
  flag[46] = a[21] ^ 46;
  authenticate(a, flag, 51);
  return 1;
}

void isBeingDebugged(){
  char *alphabet = "abcdefghijklmnopqrstuvwxyz_!{} ";
  char flag[35];
  flag[7] = alphabet[26] ^ 7;
  flag[2] = alphabet[11] ^ 2;
  flag[1] = alphabet[14] ^ 1;
  flag[0] = alphabet[11] ^ 0;
  flag[9] = alphabet[7] ^ 9;
  flag[4] = alphabet[24] ^ 4;
  flag[8] = alphabet[19] ^ 8;
  flag[3] = alphabet[26] ^ 3;
  flag[16] = alphabet[8] ^ 16;
  flag[10] = alphabet[14] ^ 10;
  flag[5] = alphabet[14] ^ 5;
  flag[6] = alphabet[20] ^ 6;
  flag[19] = alphabet[22] ^ 19;
  flag[11] = alphabet[20] ^ 11;
  flag[22] = alphabet[26] ^ 22;
  flag[15] = alphabet[26] ^ 15;
  flag[12] = alphabet[6] ^ 12;
  flag[20] = alphabet[0] ^ 20;
  flag[13] = alphabet[7] ^ 13;
  flag[18] = alphabet[26] ^ 18;
  flag[14] = alphabet[19] ^ 14;
  flag[34] = alphabet[28] ^ 34;
  flag[24] = alphabet[7] ^ 24;
  flag[29] = alphabet[0] ^ 29;
  flag[35] = alphabet[29] ^ 35;
  flag[21] = alphabet[18] ^ 21;
  flag[27] = alphabet[26] ^ 27;
  flag[23] = alphabet[19] ^ 23;
  flag[25] = alphabet[0] ^ 25;
  flag[30] = alphabet[18] ^ 30;
  flag[17] = alphabet[19] ^ 17;
  flag[32] = '\0';
  flag[26] = alphabet[19] ^ 26;
  flag[31] = alphabet[24] ^ 31;
  flag[28] = alphabet[4] ^ 28;
  authenticate(alphabet, flag, 32);
  createProgram((int)1, (int)0, (int)0, (int)1);
  exit(0);
}

void isNotBeingDebugged(){
  createProgram((int)0, (int)1, (int)1, (int)0);
}

int main(){
    if(ptrace(PTRACE_TRACEME, 0, 1, 0) < 0){
      isBeingDebugged();
    }
    else{
      isNotBeingDebugged();
    }
    exit(0);
}
