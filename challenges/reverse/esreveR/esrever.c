#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int first(long int k){
  int res = k ^ 343873487834;
  int res2 = 0;
  res = res ^ 4;
  res = res * 3;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
long int second(long int k){
  int res = k ^ 982109213881982;
  int res2 = 0;
  res = res ^ 4;
  res = res * 3;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
long int third(long int k){
  int res = k ^ 9893493384987937;
  int res2 = 0;
  res = res ^ 4;
  res = res * 3;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
long int forth(long int k){
  int res = k ^ 16377823623;
  int res2 = 0;
  res = res ^ 4;
  res = res * 3;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
long int fifth(long int k){
  int res = k ^ 45989839498283742;
  int res2 = 0;
  res = res ^ 4;
  res = res * 3;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
long int sixth(long int k){
  int res = k ^ 34878429897;
  int res2 = 0;
  res = res ^ 4;
  res = res * 3;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
long int seventh(long int k){
  int res = k ^ 458782344294245;
  int res2 = 0;
  res = res ^ 4;
  res = res * 8;
  res2 = res;
  res = res2 + k;
  res = k + k - res;
  return res;
}
long int eight(long int k){
  int res = k ^ 94875675884;
  int res2 = 0;
  res = res ^ 4;
  res = res * 3;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
long int ninth(long int k){
  int res = k ^ 498799754749;
  int res2 = 0;
  res = res ^ 4;
  res = res * 3;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
long int tenth(long int k){
  int res = k ^ 345345728984;
  int res2 = 3;
  res = res ^ 8;
  res = res * 2;
  res2 = res;
  res = res2 - k;
  res = k + k + res;
  return res;
}
void flush(){
  fflush(stdin);
  fflush(stdout);
}
long int check_it(
  long int flag0, long int flag1, long int flag2, long int flag3, long int flag4, long int flag5, long int flag6, long int flag7, long int flag8, long int flag9, long int flag10, long int flag11, long int flag12, long int flag13, long int flag14,
  long int flag15, long int flag16, long int flag17, long int flag18, long int flag19, long int flag20, long int flag21, long int flag22, long int flag23, long int flag24, long int flag25, long int flag26, long int flag27, long int flag28,
  long int flag29, long int flag30, long int flag31, long int flag32, long int flag33, long int flag34, long int flag35, long int flag36, long int flag37, long int flag38, long int flag39, long int flag40, long int flag41, long int flag42,
  long int flag43, long int flag44, long int flag45, long int flag46, long int flag47, long int flag48, long int flag49, long int flag50, long int flag51, long int flag52, long int flag53, long int flag54, long int flag55, char *inp)
{
  int woe = 1;
  if(flag0 != inp[0]){woe = 0;}
  if(flag1 != inp[1]){woe = 0;}
  if(flag2 != inp[2]){woe = 0;}
  if(flag3 != inp[3]){woe = 0;}
  if(flag4 != inp[4]){woe = 0;}
  if(flag5 != inp[5]){woe = 0;}
  if(flag6 != inp[6]){woe = 0;}
  if(flag7 != inp[7]){woe = 0;}
  if(flag8 != inp[8]){woe = 0;}
  if(flag9 != inp[9]){woe = 0;}
  if(flag10 != inp[10]){woe = 0;}
  if(flag11 != inp[11]){woe = 0;}
  if(flag12 != inp[12]){woe = 0;}
  if(flag13 != inp[13]){woe = 0;}
  if(flag14 != inp[14]){woe = 0;}
  if(flag15 != inp[15]){woe = 0;}
  if(flag16 != inp[16]){woe = 0;}
  if(flag17 != inp[17]){woe = 0;}
  if(flag18 != inp[18]){woe = 0;}
  if(flag19 != inp[19]){woe = 0;}
  if(flag20 != inp[20]){woe = 0;}
  if(flag21 != inp[21]){woe = 0;}
  if(flag22 != inp[22]){woe = 0;}
  if(flag23 != inp[23]){woe = 0;}
  if(flag24 != inp[24]){woe = 0;}
  if(flag25 != inp[25]){woe = 0;}
  if(flag26 != inp[26]){woe = 0;}
  if(flag27 != inp[27]){woe = 0;}
  if(flag28 != inp[28]){woe = 0;}
  if(flag29 != inp[29]){woe = 0;}
  if(flag30 != inp[30]){woe = 0;}
  if(flag31 != inp[31]){woe = 0;}
  if(flag32 != inp[32]){woe = 0;}
  if(flag33 != inp[33]){woe = 0;}
  if(flag34 != inp[34]){woe = 0;}
  if(flag35 != inp[35]){woe = 0;}
  if(flag36 != inp[36]){woe = 0;}
  if(flag37 != inp[37]){woe = 0;}
  if(flag38 != inp[38]){woe = 0;}
  if(flag39 != inp[39]){woe = 0;}
  if(flag40 != inp[40]){woe = 0;}
  if(flag41 != inp[41]){woe = 0;}
  if(flag42 != inp[42]){woe = 0;}
  if(flag43 != inp[43]){woe = 0;}
  if(flag44 != inp[44]){woe = 0;}
  if(flag45 != inp[45]){woe = 0;}
  if(flag46 != inp[46]){woe = 0;}
  if(flag47 != inp[47]){woe = 0;}
  if(flag48 != inp[48]){woe = 0;}
  if(flag49 != inp[49]){woe = 0;}
  if(flag50 != inp[50]){woe = 0;}
  if(flag51 != inp[51]){woe = 0;}
  if(flag52 != inp[52]){woe = 0;}
  if(flag53 != inp[53]){woe = 0;}
  if(flag54 != inp[54]){woe = 0;}
  return woe;
}

long int check_pwd(char *inp, int long e, int long d, int long c, int long b, int long a){
  //a = -1709993534
  //b = 1556067285
  //c = -940414931
  //d = 194
  //e = 1115522582
  long int flag0 = -1709993547 ^ a;
  long int flag1 = -1709993565 ^ a;
  long int flag2 = -1709993546 ^ a;
  long int flag3 = -1709993561 ^ a;
  long int flag4 = -1709993548 ^ a;
  long int flag5 = -1709993552 ^ a;
  long int flag6 = -1709993543 ^ a;
  long int flag7 = -1709993561 ^ a;
  long int flag8 = -1709993551 ^ a;
  long int flag9 = -1709993552 ^ a;
  long int flag10 = -1709993561 ^ a;
  long int flag11 = -1709993548 ^ a;
  long int flag12 = -1709993561 ^ a;
  long int flag13 = -1709993552 ^ a;
  long int flag14 = -1709993571 ^ a;
  long int flag15 = -1709993552 ^ a;
  long int flag16 = -1709993561 ^ a;
  long int flag17 = -1709993548 ^ a;
  long int flag18 = -1709993561 ^ a;
  long int flag19 = -1709993552 ^ a;
  long int flag20 = 1556067238 ^ b;
  long int flag21 = 1556067248 ^ b;
  long int flag22 = 1556067249 ^ b;
  long int flag23 = 1556067210 ^ b;
  long int flag24 = 1556067244 ^ b;
  long int flag25 = 1556067258 ^ b;
  long int flag26 = 1556067232 ^ b;
  long int flag27 = 1556067233 ^ b;
  long int flag28 = 1556067232 ^ b;
  long int flag29 = 1556067255 ^ b;
  long int flag30 = 1556067248 ^ b;
  long int flag31 = 1556067323 ^ b;
  long int flag32 = 1556067254 ^ b;
  long int flag33 = 1556067258 ^ b;
  long int flag34 = 1556067256 ^ b;
  long int flag35 = -940414974 ^ c;
  long int flag36 = -940414886 ^ c;
  long int flag37 = -940414900 ^ c;
  long int flag38 = -940414887 ^ c;
  long int flag39 = -940414898 ^ c;
  long int flag40 = -940414907 ^ c;
  long int flag41 = -940414958 ^ c;
  long int flag42 = -940414885 ^ c;
  long int flag43 = -940414960 ^ c;
  long int flag44 = -940414876 ^ c;
  long int flag45 = -940414955 ^ c;
  long int flag46 = -940414908 ^ c;
  long int flag47 = -940414905 ^ c;
  long int flag48 = -940414897 ^ c;
  long int flag49 = -940414951 ^ c;
  long int flag50 = 152 ^ d;
  long int flag51 = 167 ^ d;
  long int flag52 = 1115522675 ^ e;
  long int flag53 = 1115522595 ^ e;
  long int flag54 = 1115522643 ^ e;
  long int flag55 = 1115522667 ^ e;
  int is_correct = 1;
  is_correct = ((a & 0xff)*(b & 0xff)*(c & 0xffff))-((c*d*e) & 0xffff) >> 8;
  int isreally = check_it(flag0, flag1, flag2, flag3, flag4, flag5, flag6, flag7, flag8, flag9, flag10, flag11, flag12, flag13, flag14, flag15, flag16, flag17, flag18, flag19, flag20, flag21, flag22, flag23, flag24, flag25, flag26, flag27, flag28, flag29, flag30, flag31, flag32, flag33, flag34, flag35, flag36, flag37, flag38, flag39, flag40, flag41, flag42, flag43, flag44, flag45, flag46, flag47, flag48, flag49, flag50, flag51, flag52, flag53, flag54, flag55, inp);
  if(isreally == 0){
    exit(0);
  }
  return is_correct;
}

int main(){
  long int b = 4584583;
  long int a = 2374827;
  long int c = 83468723;
  long int d = 34783;
  long int e = 38478494;
  long int h = 21232134;
  long int g = 34532341;
  long int i = 146756703;
  long int j = 9138987;
  long int f = 845845;
  while(f == 845845){
    a = first(b);
    b = second(c);
    c = third(d);
    d = forth(e);
    e = fifth(f);
    f = sixth(g);
    g = seventh(h);
    h = eight(i);
    i = ninth(j);
    printf("%s\n", "Welcome to Esrever! I hope you will \033[9menjoy\033[0mhate your stay here,");
    j = tenth(a);
    a = b+c-(d+e+j);
    a = first(b);
    b = second(c);
    c = third(d);
    d = forth(e);
    e = fifth(f);
    printf("%s\n", "Here at Esrever we really do like playing games,\nSo lets play a guessing game.");
    f = sixth(g);
    g = seventh(h);
    h = eight(i);
    e = b+d+(c-i+a);
    i = ninth(j);
    j = tenth(a);
    a = first(b);
    char abcd[25];
    abcd[3] = 'e';
    abcd[1] = 'a';
    abcd[6] = 'o';
    abcd[2] = 'k';
    abcd[10] = 'b';
    abcd[0] = 'M';
    abcd[5] = 'y';
    abcd[15] = 'g';
    abcd[4] = ' ';
    abcd[8] = 'r';
    abcd[9] = ' ';
    abcd[13] = 't';
    abcd[7] = 'u';
    abcd[12] = 's';
    abcd[18] = 's';
    abcd[19] = 's';
    abcd[16] = 'u';
    abcd[11] = 'e';
    abcd[20] = ':';
    abcd[14] = ' ';
    abcd[21] = ' ';
    abcd[17] = 'e';
    abcd[22] = 0;
    printf("%s", abcd);
    flush();
    b = second(c);
    c = third(d);
    d = forth(e);
    e = fifth(f);
    e = (e-(1942456670));
    f = sixth(g) ^ 3;
    g = seventh(h) ^ 43;
    h = eight(i);
    i = ninth(j);
    j = tenth(a);
    char inp[e];
    a = first(b);
    b = second(c) & 0xff;
    c = third(d);
    fgets(inp, e, stdin); //40
    d = forth(e);
    e = fifth(f);
    if(e != d){
      g = sixth(4521);
      if(g != inp){
        if(check_pwd(inp, a, b, c, g, j) != a*((j ^ i) - e)){
          printf("Congratulations! You reversed the reversed reverse!\n");
        }
      }
    }
    f = sixth(g);
    g = seventh(h) | 3;
    h = eight(i);
    i = ninth(j);
    j = tenth(a);
  }
}
