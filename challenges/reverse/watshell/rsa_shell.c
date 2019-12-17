#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

char buffer[1024];
const int MAX_DIGITS = 50;
int i,j = 0;

__int128 p;
__int128 q;

struct s_1{
  __int128 modulus;
  __int128 exponent;
};

struct s_2{
  __int128 modulus;
  __int128 exponent;
};

__int128 f_0(long long a, long long b){
  __int128 c;
  while ( a != 0 ) {
    c = a; a = b%a;  b = c;
  }
  return b;
}


__int128 f_1(long long a, long long b)
{
 __int128 x = 0, y = 1, u = 1, v = 0, gcd = b, m, n, q, r;
 while (a!=0) {
   q = gcd/a; r = gcd % a;
   m = x-u*q; n = y-v*q;
   gcd = a; a = r; x = u; y = v; u = m; v = n;
   }
   return y;
}

long long f_2(long long b, long long e, long long m)
{
  if (b < 0 || e < 0 || m <= 0){
    //printf("%lld\n%lld\n%lld\n", b, e, m);
    exit(1);
  }
  b = b % m;
  if(e == 0) return 1;
  if(e == 1) return b;
  if( e % 2 == 0){
    return ( f_2(b * b % m, e/2, m) % m );
  }
  if( e % 2 == 1){
    return ( b * f_2(b, (e-1), m) % m );
  }

}

// Calling this function will generate a ma_1lic and ma_2ate key and store them in the pointers
// it is given.
void f_3(struct s_1 *ma_1, struct s_2 *ma_2){

  //long long p = 1481213527;
  //long long q = 1743314891;

  __int128 e = powl(2, 8) + 1;
  __int128 d = 0;
  char prime_buffer[MAX_DIGITS];
  __int128 max = 0;
  __int128 phi_max = 0;

  max = p*q;
  phi_max = (p-1)*(q-1);

  d = f_1(phi_max,e);
  while(d < 0){
    d = d+phi_max;
  }

  //printf("primes are %lld and %lld\n",(long long)p, (long long )q);

  ma_1->modulus = max;
  ma_1->exponent = e;

  ma_2->modulus = max;
  ma_2->exponent = d;
}

long long *f_4(char *am, unsigned __int128 am_s, struct s_1 *ma_1){
  long long *ae_1 = malloc(sizeof(long long)*am_s);
  if(ae_1 == NULL){
    exit(0);
    //return NULL;
  }
  __int128 i = 0;
  for(i=0; i < am_s; i++){
    ae_1[i] = f_2(am[i], ma_1->exponent, ma_1->modulus);
  }
  //printf("%lld\n", ae_1[0]);
  return ae_1;
}

char *f_5(const long long *am, const unsigned __int128 am_s, const struct s_2 *ma_2){
  if(am_s % sizeof(long long) != 0){
     //"Error: am_s is not divisible by %d, so cannot be output of rsa_encrypt\n", (int)sizeof(long long));
     exit(0);
  }
  // We allocate space to do the decryption (temp) and space for the output as a char array
  // (decrypted)
  char *decrypted = malloc(am_s/sizeof(long long));
  char *temp = malloc(am_s);
  if((decrypted == NULL) || (temp == NULL)){
     //"Error: Heap allocation failed.\n");
    exit(0);
  }
  // Now we go through each 8-byte chunk and decrypt it.
  __int128 i = 0;
  for(i=0; i < am_s/8; i++){
    temp[i] = f_2(am[i], ma_2->exponent, ma_2->modulus);
  }
  // The result should be a number in the char range, which gives back the original byte.
  // We put that into decrypted, then return.
  for(i=0; i < am_s/8; i++){
    decrypted[i] = temp[i];
  }
  free(temp);
  return decrypted;
}

int f_8(int base, int exponent){
  int result=1;
  for (exponent; exponent>0; exponent--){
    result = result * base;
  }
  return result;
}


void f_6(void){
  long long p_i1, p_i2;
  int num = 54;
  __int128 temp_1 = f_1(num, 27);
  long long numbers[6] = {f_8(temp_1, 0)-temp_1, f_8(temp_1, 1)-(temp_1-1), f_8(temp_1, 2)-(temp_1-2), f_8(temp_1, 3)-(temp_1-3), f_8(temp_1, 4)-(temp_1-4), f_8(temp_1, 5)-(temp_1-5)}; //0, 1, 2, 3, 4, 5
  p_i1 = f_0(f_8(f_8(numbers[3], numbers[2]), numbers[2])*numbers[3], f_8(f_8(numbers[3], numbers[2]), numbers[2])*numbers[4])+10;//91
  p_i2 = numbers[1]*(num-2);//52
  p = f_0(p_i1, p_i2); // 13
}

void f_7(void){
  long long p_i1, p_i2;
  int num = 52;
  __int128 temp_1 = f_1(num+2, 27);
  long long numbers[6] = {f_8(temp_1, 0)-temp_1, f_8(temp_1, 1)-(temp_1-1), f_8(temp_1, 2)-(temp_1-2), f_8(temp_1, 3)-(temp_1-3), f_8(temp_1, 4)-(temp_1-4), f_8(temp_1, 5)-(temp_1-5)}; //0, 1, 2, 3, 4, 5
  p_i1 = f_0(f_8(f_8(3, 2), 2)*numbers[3], f_8(f_8(3, 2), 2)*numbers[4])+10;//91
  p_i2 = numbers[1]*num;//52
  q = f_0(p_i1, p_i2)-numbers[2]; //11
}

void sig(int sign){
	exit(0);
}

int main(void){
  signal(SIGALRM, sig);
  alarm(60);
  struct s_1 ma_1[1];
  struct s_2 ma_2[1];
  int i = 0;
  char mess[500];
  char delim[] = " ";
  long long ae_1[25];
  int ai_0 = 0;

  f_6();
  f_7();
  //char am[] = "/bin/sh";
  printf("%s\n", "Welcome to watshell, we ofcourse use our own super secure cryptographic functions to ensure user privacy!");
  printf("%s", "Command: ");
  fflush(stdout);
  fgets(mess, 500, stdin);
  int init_size = strlen(mess);
  char *ptr = strtok(mess, delim);

  while(ptr != NULL && ai_0 != 25){
    ae_1[ai_0] = atol(ptr);
    ai_0++;
    //printf("%lld %s\n", ae_1[ai_0], ptr);
    ptr = strtok(NULL, delim);
  }
  f_3(ma_1, ma_2);
  //long long *ae_1 = rsa_encrypt(am, sizeof(am), ma_1);
  //printf("ae_1:\n");
  //for(i=0; i < strlen(am); i++){
  //  printf("%lld\n", (long long)ae_1[i]);
  //}
  char *decrypted = f_5(ae_1, 8*ai_0+8, ma_2);
  //system(decrypted);
  char flag[75];
  if(strcmp(decrypted, "give_me_the_flag_please") == 0){
    FILE *in = fopen("/home/ctf/flag.txt", "r");
    if(in == NULL){
      printf("The file does not exist!");
    }
    fgets(flag, 74, in);
    printf("Alright, alright %s\n", flag);
    fclose(in);
  }
  //free(ae_1);

  free(decrypted);
  return 0;
}
