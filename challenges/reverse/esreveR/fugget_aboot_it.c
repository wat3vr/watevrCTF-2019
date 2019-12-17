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
    long int flag0, long int flag1, long int flag2, long int flag3, long int flag4, long int flag5, long int flag6, long int flag7, long int flag8, long int flag9, long int flag10, long int flag11, long int flag12, long int flag13, long int flag14, long int flag15,
    long int flag16, long int flag17, long int flag18, long int flag19, long int flag20, long int flag21, long int flag22, long int flag23, long int flag24, long int flag25, long int flag26, long int flag27, long int flag28, long int flag29, long int flag30, long int flag31,
    long int flag32, long int flag33, long int flag34, long int flag35, long int flag36, long int flag37, long int flag38, long int flag39, long int flag40, long int flag41, long int flag42, long int flag43, long int flag44, long int flag45, long int flag46, long int flag47,
     long int flag48, long int flag49, long int flag50, long int flag51, long int flag52, long int flag53, long int flag54, long int flag55, long int flag56, long int flag57, long int flag58, long int flag59, long int flag60, long int flag61, long int flag62, long int flag63,
      long int flag64, long int flag65, long int flag66, long int flag67, long int flag68, long int flag69, long int flag70, long int flag71, long int flag72, long int flag73, long int flag74, long int flag75, long int flag76, long int flag77, long int flag78, long int flag79,
       long int flag80, long int flag81, long int flag82, long int flag83, long int flag84, long int flag85, long int flag86, long int flag87, long int flag88, long int flag89, long int flag90, long int flag91, long int flag92, long int flag93, long int flag94, long int flag95,
        long int flag96, long int flag97, long int flag98, long int flag99, long int flag100, long int flag101, long int flag102, long int flag103, long int flag104, long int flag105,
       long int flag106, long int flag107, long int flag108, long int flag109, long int flag110, long int flag111, long int flag112, long int flag113, long int flag114, long int flag115, long int flag116, long int flag117, long int flag118, long int flag119, long int flag120, long int flag121, long int flag122, long int flag123, long int flag124, long int flag125, long int flag126, long int flag127, long int flag128, long int flag129, long int flag130, long int flag131, long int flag132, long int flag133, long int flag134, long int flag135, long int flag136, long int flag137, long int flag138, long int flag139, long int flag140, long int flag141, long int flag142, long int flag143, long int flag144, long int flag145, long int flag146, long int flag147, long int flag148, long int flag149, long int flag150, long int flag151, long int flag152, long int flag153, long int flag154, long int flag155, long int flag156, long int flag157, long int flag158, long int flag159, long int flag160, long int flag161, long int flag162, long int flag163, long int flag164, long int flag165, long int flag166, long int flag167, long int flag168, long int flag169, long int flag170, long int flag171, long int flag172, long int flag173, long int flag174, long int flag175, long int flag176, long int flag177, long int flag178, long int flag179, long int flag180, long int flag181, long int flag182, long int flag183, long int flag184, long int flag185, long int flag186, long int flag187, long int flag188, long int flag189, long int flag190, long int flag191, long int flag192, long int flag193, long int flag194, long int flag195, long int flag196, long int flag197, long int flag198, long int flag199, long int flag200, long int flag201, long int flag202, long int flag203, long int flag204, long int flag205, long int flag206, long int flag207, long int flag208, long int flag209, long int flag210, long int flag211, long int flag212, long int flag213, long int flag214, long int flag215, long int flag216, long int flag217, long int flag218, long int flag219, long int flag220, long int flag221, long int flag222, long int flag223, long int flag224, long int flag225, long int flag226, long int flag227, long int flag228, long int flag229, long int flag230, long int flag231, long int flag232, long int flag233, long int flag234, long int flag235, long int flag236, long int flag237, long int flag238, long int flag239, long int flag240, long int flag241, long int flag242, long int flag243, long int flag244, long int flag245, long int flag246, long int flag247, long int flag248, long int flag249, long int flag250, long int flag251, long int flag252, long int flag253, long int flag254, long int flag255, long int flag256, long int flag257, long int flag258, long int flag259, long int flag260, long int flag261, long int flag262, long int flag263, long int flag264, long int flag265, long int flag266, long int flag267, long int flag268, long int flag269, long int flag270, long int flag271, long int flag272, long int flag273, long int flag274, long int flag275, long int flag276, long int flag277, long int flag278, long int flag279, long int flag280, long int flag281, long int flag282, long int flag283, long int flag284, long int flag285, long int flag286, long int flag287, long int flag288, long int flag289, long int flag290, long int flag291, long int flag292, long int flag293, long int flag294, long int flag295, long int flag296, long int flag297, long int flag298, long int flag299, long int flag300, long int flag301, long int flag302, long int flag303, long int flag304, long int flag305, long int flag306, long int flag307, long int flag308, long int flag309, long int flag310, long int flag311, long int flag312, long int flag313, long int flag314, long int flag315, long int flag316, long int flag317, long int flag318, long int flag319, long int flag320, long int flag321, long int flag322, long int flag323, long int flag324, long int flag325, long int flag326, long int flag327, long int flag328, long int flag329, long int flag330, long int flag331, long int flag332, long int flag333, long int flag334, long int flag335, long int flag336, long int flag337, long int flag338, long int flag339, long int flag340, long int flag341, long int flag342, long int flag343, long int flag344, long int flag345, long int flag346, long int flag347, long int flag348, long int flag349, long int flag350, long int flag351, long int flag352, long int flag353, long int flag354, long int flag355, long int flag356, long int flag357, long int flag358, long int flag359, long int flag360, long int flag361, long int flag362, long int flag363, long int flag364, long int flag365, long int flag366, long int flag367, long int flag368, long int flag369, long int flag370, long int flag371, long int flag372, long int flag373, long int flag374, long int flag375, long int flag376, long int flag377, long int flag378, long int flag379, long int flag380, long int flag381, long int flag382, long int flag383, long int flag384, long int flag385, long int flag386, long int flag387, long int flag388, long int flag389, long int flag390, long int flag391, long int flag392, long int flag393, long int flag394, char *inp)
{
  int woe = 1;
  printf("%s\n", inp);
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
  if(flag55 != inp[55]){woe = 0;}
  if(flag56 != inp[56]){woe = 0;}
  if(flag57 != inp[57]){woe = 0;}
  if(flag58 != inp[58]){woe = 0;}
  if(flag59 != inp[59]){woe = 0;}
  if(flag60 != inp[60]){woe = 0;}
  if(flag61 != inp[61]){woe = 0;}
  if(flag62 != inp[62]){woe = 0;}
  if(flag63 != inp[63]){woe = 0;}
  if(flag64 != inp[64]){woe = 0;}
  if(flag65 != inp[65]){woe = 0;}
  if(flag66 != inp[66]){woe = 0;}
  if(flag67 != inp[67]){woe = 0;}
  if(flag68 != inp[68]){woe = 0;}
  if(flag69 != inp[69]){woe = 0;}
  if(flag70 != inp[70]){woe = 0;}
  if(flag71 != inp[71]){woe = 0;}
  if(flag72 != inp[72]){woe = 0;}
  if(flag73 != inp[73]){woe = 0;}
  if(flag74 != inp[74]){woe = 0;}
  if(flag75 != inp[75]){woe = 0;}
  if(flag76 != inp[76]){woe = 0;}
  if(flag77 != inp[77]){woe = 0;}
  if(flag78 != inp[78]){woe = 0;}
  if(flag79 != inp[79]){woe = 0;}
  if(flag80 != inp[80]){woe = 0;}
  if(flag81 != inp[81]){woe = 0;}
  if(flag82 != inp[82]){woe = 0;}
  if(flag83 != inp[83]){woe = 0;}
  if(flag84 != inp[84]){woe = 0;}
  if(flag85 != inp[85]){woe = 0;}
  if(flag86 != inp[86]){woe = 0;}
  if(flag87 != inp[87]){woe = 0;}
  if(flag88 != inp[88]){woe = 0;}
  if(flag89 != inp[89]){woe = 0;}
  if(flag90 != inp[90]){woe = 0;}
  if(flag91 != inp[91]){woe = 0;}
  if(flag92 != inp[92]){woe = 0;}
  if(flag93 != inp[93]){woe = 0;}
  if(flag94 != inp[94]){woe = 0;}
  if(flag95 != inp[95]){woe = 0;}
  if(flag96 != inp[96]){woe = 0;}
  if(flag97 != inp[97]){woe = 0;}
  if(flag98 != inp[98]){woe = 0;}
  if(flag99 != inp[99]){woe = 0;}
  if(flag100 != inp[100]){woe = 0;}
  if(flag101 != inp[101]){woe = 0;}
  if(flag102 != inp[102]){woe = 0;}
  if(flag103 != inp[103]){woe = 0;}
  if(flag104 != inp[104]){woe = 0;}
  if(flag105 != inp[105]){woe = 0;}
  if(flag106 != inp[106]){woe = 0;}
  if(flag107 != inp[107]){woe = 0;}
  if(flag108 != inp[108]){woe = 0;}
  if(flag109 != inp[109]){woe = 0;}
  if(flag110 != inp[110]){woe = 0;}
  if(flag111 != inp[111]){woe = 0;}
  if(flag112 != inp[112]){woe = 0;}
  if(flag113 != inp[113]){woe = 0;}
  if(flag114 != inp[114]){woe = 0;}
  if(flag115 != inp[115]){woe = 0;}
  if(flag116 != inp[116]){woe = 0;}
  if(flag117 != inp[117]){woe = 0;}
  if(flag118 != inp[118]){woe = 0;}
  if(flag119 != inp[119]){woe = 0;}
  if(flag120 != inp[120]){woe = 0;}
  if(flag121 != inp[121]){woe = 0;}
  if(flag122 != inp[122]){woe = 0;}
  if(flag123 != inp[123]){woe = 0;}
  if(flag124 != inp[124]){woe = 0;}
  if(flag125 != inp[125]){woe = 0;}
  if(flag126 != inp[126]){woe = 0;}
  if(flag127 != inp[127]){woe = 0;}
  if(flag128 != inp[128]){woe = 0;}
  if(flag129 != inp[129]){woe = 0;}
  if(flag130 != inp[130]){woe = 0;}
  if(flag131 != inp[131]){woe = 0;}
  if(flag132 != inp[132]){woe = 0;}
  if(flag133 != inp[133]){woe = 0;}
  if(flag134 != inp[134]){woe = 0;}
  if(flag135 != inp[135]){woe = 0;}
  if(flag136 != inp[136]){woe = 0;}
  if(flag137 != inp[137]){woe = 0;}
  if(flag138 != inp[138]){woe = 0;}
  if(flag139 != inp[139]){woe = 0;}
  if(flag140 != inp[140]){woe = 0;}
  if(flag141 != inp[141]){woe = 0;}
  if(flag142 != inp[142]){woe = 0;}
  if(flag143 != inp[143]){woe = 0;}
  if(flag144 != inp[144]){woe = 0;}
  if(flag145 != inp[145]){woe = 0;}
  if(flag146 != inp[146]){woe = 0;}
  if(flag147 != inp[147]){woe = 0;}
  if(flag148 != inp[148]){woe = 0;}
  if(flag149 != inp[149]){woe = 0;}
  if(flag150 != inp[150]){woe = 0;}
  if(flag151 != inp[151]){woe = 0;}
  if(flag152 != inp[152]){woe = 0;}
  if(flag153 != inp[153]){woe = 0;}
  if(flag154 != inp[154]){woe = 0;}
  if(flag155 != inp[155]){woe = 0;}
  if(flag156 != inp[156]){woe = 0;}
  if(flag157 != inp[157]){woe = 0;}
  if(flag158 != inp[158]){woe = 0;}
  if(flag159 != inp[159]){woe = 0;}
  if(flag160 != inp[160]){woe = 0;}
  if(flag161 != inp[161]){woe = 0;}
  if(flag162 != inp[162]){woe = 0;}
  if(flag163 != inp[163]){woe = 0;}
  if(flag164 != inp[164]){woe = 0;}
  if(flag165 != inp[165]){woe = 0;}
  if(flag166 != inp[166]){woe = 0;}
  if(flag167 != inp[167]){woe = 0;}
  if(flag168 != inp[168]){woe = 0;}
  if(flag169 != inp[169]){woe = 0;}
  if(flag170 != inp[170]){woe = 0;}
  if(flag171 != inp[171]){woe = 0;}
  if(flag172 != inp[172]){woe = 0;}
  if(flag173 != inp[173]){woe = 0;}
  if(flag174 != inp[174]){woe = 0;}
  if(flag175 != inp[175]){woe = 0;}
  if(flag176 != inp[176]){woe = 0;}
  if(flag177 != inp[177]){woe = 0;}
  if(flag178 != inp[178]){woe = 0;}
  if(flag179 != inp[179]){woe = 0;}
  if(flag180 != inp[180]){woe = 0;}
  if(flag181 != inp[181]){woe = 0;}
  if(flag182 != inp[182]){woe = 0;}
  if(flag183 != inp[183]){woe = 0;}
  if(flag184 != inp[184]){woe = 0;}
  if(flag185 != inp[185]){woe = 0;}
  if(flag186 != inp[186]){woe = 0;}
  if(flag187 != inp[187]){woe = 0;}
  if(flag188 != inp[188]){woe = 0;}
  if(flag189 != inp[189]){woe = 0;}
  if(flag190 != inp[190]){woe = 0;}
  if(flag191 != inp[191]){woe = 0;}
  if(flag192 != inp[192]){woe = 0;}
  if(flag193 != inp[193]){woe = 0;}
  if(flag194 != inp[194]){woe = 0;}
  if(flag195 != inp[195]){woe = 0;}
  if(flag196 != inp[196]){woe = 0;}
  if(flag197 != inp[197]){woe = 0;}
  if(flag198 != inp[198]){woe = 0;}
  if(flag199 != inp[199]){woe = 0;}
  if(flag200 != inp[200]){woe = 0;}
  if(flag201 != inp[201]){woe = 0;}
  if(flag202 != inp[202]){woe = 0;}
  if(flag203 != inp[203]){woe = 0;}
  if(flag204 != inp[204]){woe = 0;}
  if(flag205 != inp[205]){woe = 0;}
  if(flag206 != inp[206]){woe = 0;}
  if(flag207 != inp[207]){woe = 0;}
  if(flag208 != inp[208]){woe = 0;}
  if(flag209 != inp[209]){woe = 0;}
  if(flag210 != inp[210]){woe = 0;}
  if(flag211 != inp[211]){woe = 0;}
  if(flag212 != inp[212]){woe = 0;}
  if(flag213 != inp[213]){woe = 0;}
  if(flag214 != inp[214]){woe = 0;}
  if(flag215 != inp[215]){woe = 0;}
  if(flag216 != inp[216]){woe = 0;}
  if(flag217 != inp[217]){woe = 0;}
  if(flag218 != inp[218]){woe = 0;}
  if(flag219 != inp[219]){woe = 0;}
  if(flag220 != inp[220]){woe = 0;}
  if(flag221 != inp[221]){woe = 0;}
  if(flag222 != inp[222]){woe = 0;}
  if(flag223 != inp[223]){woe = 0;}
  if(flag224 != inp[224]){woe = 0;}
  if(flag225 != inp[225]){woe = 0;}
  if(flag226 != inp[226]){woe = 0;}
  if(flag227 != inp[227]){woe = 0;}
  if(flag228 != inp[228]){woe = 0;}
  if(flag229 != inp[229]){woe = 0;}
  if(flag230 != inp[230]){woe = 0;}
  if(flag231 != inp[231]){woe = 0;}
  if(flag232 != inp[232]){woe = 0;}
  if(flag233 != inp[233]){woe = 0;}
  if(flag234 != inp[234]){woe = 0;}
  if(flag235 != inp[235]){woe = 0;}
  if(flag236 != inp[236]){woe = 0;}
  if(flag237 != inp[237]){woe = 0;}
  if(flag238 != inp[238]){woe = 0;}
  if(flag239 != inp[239]){woe = 0;}
  if(flag240 != inp[240]){woe = 0;}
  if(flag241 != inp[241]){woe = 0;}
  if(flag242 != inp[242]){woe = 0;}
  if(flag243 != inp[243]){woe = 0;}
  if(flag244 != inp[244]){woe = 0;}
  if(flag245 != inp[245]){woe = 0;}
  if(flag246 != inp[246]){woe = 0;}
  if(flag247 != inp[247]){woe = 0;}
  if(flag248 != inp[248]){woe = 0;}
  if(flag249 != inp[249]){woe = 0;}
  if(flag250 != inp[250]){woe = 0;}
  if(flag251 != inp[251]){woe = 0;}
  if(flag252 != inp[252]){woe = 0;}
  if(flag253 != inp[253]){woe = 0;}
  if(flag254 != inp[254]){woe = 0;}
  if(flag255 != inp[255]){woe = 0;}
  if(flag256 != inp[256]){woe = 0;}
  if(flag257 != inp[257]){woe = 0;}
  if(flag258 != inp[258]){woe = 0;}
  if(flag259 != inp[259]){woe = 0;}
  if(flag260 != inp[260]){woe = 0;}
  if(flag261 != inp[261]){woe = 0;}
  if(flag262 != inp[262]){woe = 0;}
  if(flag263 != inp[263]){woe = 0;}
  if(flag264 != inp[264]){woe = 0;}
  if(flag265 != inp[265]){woe = 0;}
  if(flag266 != inp[266]){woe = 0;}
  if(flag267 != inp[267]){woe = 0;}
  if(flag268 != inp[268]){woe = 0;}
  if(flag269 != inp[269]){woe = 0;}
  if(flag270 != inp[270]){woe = 0;}
  if(flag271 != inp[271]){woe = 0;}
  if(flag272 != inp[272]){woe = 0;}
  if(flag273 != inp[273]){woe = 0;}
  if(flag274 != inp[274]){woe = 0;}
  if(flag275 != inp[275]){woe = 0;}
  if(flag276 != inp[276]){woe = 0;}
  if(flag277 != inp[277]){woe = 0;}
  if(flag278 != inp[278]){woe = 0;}
  if(flag279 != inp[279]){woe = 0;}
  if(flag280 != inp[280]){woe = 0;}
  if(flag281 != inp[281]){woe = 0;}
  if(flag282 != inp[282]){woe = 0;}
  if(flag283 != inp[283]){woe = 0;}
  if(flag284 != inp[284]){woe = 0;}
  if(flag285 != inp[285]){woe = 0;}
  if(flag286 != inp[286]){woe = 0;}
  if(flag287 != inp[287]){woe = 0;}
  if(flag288 != inp[288]){woe = 0;}
  if(flag289 != inp[289]){woe = 0;}
  if(flag290 != inp[290]){woe = 0;}
  if(flag291 != inp[291]){woe = 0;}
  if(flag292 != inp[292]){woe = 0;}
  if(flag293 != inp[293]){woe = 0;}
  if(flag294 != inp[294]){woe = 0;}
  if(flag295 != inp[295]){woe = 0;}
  if(flag296 != inp[296]){woe = 0;}
  if(flag297 != inp[297]){woe = 0;}
  if(flag298 != inp[298]){woe = 0;}
  if(flag299 != inp[299]){woe = 0;}
  if(flag300 != inp[300]){woe = 0;}
  if(flag301 != inp[301]){woe = 0;}
  if(flag302 != inp[302]){woe = 0;}
  if(flag303 != inp[303]){woe = 0;}
  if(flag304 != inp[304]){woe = 0;}
  if(flag305 != inp[305]){woe = 0;}
  if(flag306 != inp[306]){woe = 0;}
  if(flag307 != inp[307]){woe = 0;}
  if(flag308 != inp[308]){woe = 0;}
  if(flag309 != inp[309]){woe = 0;}
  if(flag310 != inp[310]){woe = 0;}
  if(flag311 != inp[311]){woe = 0;}
  if(flag312 != inp[312]){woe = 0;}
  if(flag313 != inp[313]){woe = 0;}
  if(flag314 != inp[314]){woe = 0;}
  if(flag315 != inp[315]){woe = 0;}
  if(flag316 != inp[316]){woe = 0;}
  if(flag317 != inp[317]){woe = 0;}
  if(flag318 != inp[318]){woe = 0;}
  if(flag319 != inp[319]){woe = 0;}
  if(flag320 != inp[320]){woe = 0;}
  if(flag321 != inp[321]){woe = 0;}
  if(flag322 != inp[322]){woe = 0;}
  if(flag323 != inp[323]){woe = 0;}
  if(flag324 != inp[324]){woe = 0;}
  if(flag325 != inp[325]){woe = 0;}
  if(flag326 != inp[326]){woe = 0;}
  if(flag327 != inp[327]){woe = 0;}
  if(flag328 != inp[328]){woe = 0;}
  if(flag329 != inp[329]){woe = 0;}
  if(flag330 != inp[330]){woe = 0;}
  if(flag331 != inp[331]){woe = 0;}
  if(flag332 != inp[332]){woe = 0;}
  if(flag333 != inp[333]){woe = 0;}
  if(flag334 != inp[334]){woe = 0;}
  if(flag335 != inp[335]){woe = 0;}
  if(flag336 != inp[336]){woe = 0;}
  if(flag337 != inp[337]){woe = 0;}
  if(flag338 != inp[338]){woe = 0;}
  if(flag339 != inp[339]){woe = 0;}
  if(flag340 != inp[340]){woe = 0;}
  if(flag341 != inp[341]){woe = 0;}
  if(flag342 != inp[342]){woe = 0;}
  if(flag343 != inp[343]){woe = 0;}
  if(flag344 != inp[344]){woe = 0;}
  if(flag345 != inp[345]){woe = 0;}
  if(flag346 != inp[346]){woe = 0;}
  if(flag347 != inp[347]){woe = 0;}
  if(flag348 != inp[348]){woe = 0;}
  if(flag349 != inp[349]){woe = 0;}
  if(flag350 != inp[350]){woe = 0;}
  if(flag351 != inp[351]){woe = 0;}
  if(flag352 != inp[352]){woe = 0;}
  if(flag353 != inp[353]){woe = 0;}
  if(flag354 != inp[354]){woe = 0;}
  if(flag355 != inp[355]){woe = 0;}
  if(flag356 != inp[356]){woe = 0;}
  if(flag357 != inp[357]){woe = 0;}
  if(flag358 != inp[358]){woe = 0;}
  if(flag359 != inp[359]){woe = 0;}
  if(flag360 != inp[360]){woe = 0;}
  if(flag361 != inp[361]){woe = 0;}
  if(flag362 != inp[362]){woe = 0;}
  if(flag363 != inp[363]){woe = 0;}
  if(flag364 != inp[364]){woe = 0;}
  if(flag365 != inp[365]){woe = 0;}
  if(flag366 != inp[366]){woe = 0;}
  if(flag367 != inp[367]){woe = 0;}
  if(flag368 != inp[368]){woe = 0;}
  if(flag369 != inp[369]){woe = 0;}
  if(flag370 != inp[370]){woe = 0;}
  if(flag371 != inp[371]){woe = 0;}
  if(flag372 != inp[372]){woe = 0;}
  if(flag373 != inp[373]){woe = 0;}
  if(flag374 != inp[374]){woe = 0;}
  if(flag375 != inp[375]){woe = 0;}
  if(flag376 != inp[376]){woe = 0;}
  if(flag377 != inp[377]){woe = 0;}
  if(flag378 != inp[378]){woe = 0;}
  if(flag379 != inp[379]){woe = 0;}
  if(flag380 != inp[380]){woe = 0;}
  if(flag381 != inp[381]){woe = 0;}
  if(flag382 != inp[382]){woe = 0;}
  if(flag383 != inp[383]){woe = 0;}
  if(flag384 != inp[384]){woe = 0;}
  if(flag385 != inp[385]){woe = 0;}
  if(flag386 != inp[386]){woe = 0;}
  if(flag387 != inp[387]){woe = 0;}
  if(flag388 != inp[388]){woe = 0;}
  if(flag389 != inp[389]){woe = 0;}
  if(flag390 != inp[390]){woe = 0;}
  if(flag391 != inp[391]){woe = 0;}
  if(flag392 != inp[392]){woe = 0;}
  if(flag393 != inp[393]){woe = 0;}
  if(flag394 != inp[394]){woe = 0;}
  return woe;
}

long int check_pwd(char *inp, int long e, int long d, int long c, int long b, int long a){
  //a = -1709993534
  //b = 1556067285
  //c = -940414931
  //d = 194
  //e = 1115522582
  long int flag30 = -1709993552 ^ a;
  long int flag329 = 1115522658 ^ e;
  long int flag375 = 1115522657 ^ e;
  long int flag370 = 1115522616 ^ e;
  long int flag103 = 1556067210 ^ b;
  long int flag165 = -940414881 ^ c;
  long int flag231 = -940414911 ^ c;
  long int flag221 = -940414900 ^ c;
  long int flag284 = 167 ^ d;
  long int flag163 = -940414888 ^ c;
  long int flag44 = -1709993555 ^ a;
  long int flag48 = -1709993545 ^ a;
  long int flag93 = 1556067248 ^ b;
  long int flag349 = 1115522671 ^ e;
  long int flag368 = 1115522676 ^ e;
  long int flag39 = -1709993552 ^ a;
  long int flag358 = 1115522617 ^ e;
  long int flag95 = 1556067210 ^ b;
  long int flag356 = 1115522604 ^ e;
  long int flag110 = 1556067244 ^ b;
  long int flag316 = 1115522661 ^ e;
  long int flag294 = 176 ^ d;
  long int flag135 = 1556067248 ^ b;
  long int flag170 = -940414882 ^ c;
  long int flag184 = -940414904 ^ c;
  long int flag243 = 183 ^ d;
  long int flag376 = 1115522679 ^ e;
  long int flag223 = -940414887 ^ c;
  long int flag365 = 1115522659 ^ e;
  long int flag325 = 1115522633 ^ e;
  long int flag192 = -940414904 ^ c;
  long int flag125 = 1556067248 ^ b;
  long int flag279 = 163 ^ d;
  long int flag199 = -940414882 ^ c;
  long int flag61 = -1709993561 ^ a;
  long int flag43 = -1709993562 ^ a;
  long int flag340 = 1115522687 ^ e;
  long int flag58 = -1709993571 ^ a;
  long int flag98 = 1556067235 ^ b;
  long int flag160 = -940414862 ^ c;
  long int flag315 = 171 ^ d;
  long int flag324 = 1115522658 ^ e;
  long int flag381 = 1115522656 ^ e;
  long int flag50 = -1709993546 ^ a;
  long int flag158 = -940414898 ^ c;
  long int flag328 = 1115522680 ^ e;
  long int flag319 = 1115522671 ^ e;
  long int flag116 = 1556067233 ^ b;
  long int flag148 = 1556067235 ^ b;
  long int flag132 = 1556067210 ^ b;
  long int flag35 = -1709993552 ^ a;
  long int flag174 = -940414887 ^ c;
  long int flag24 = -1709993561 ^ a;
  long int flag190 = -940414881 ^ c;
  long int flag225 = -940414887 ^ c;
  long int flag2 = -1709993546 ^ a;
  long int flag326 = 1115522687 ^ e;
  long int flag239 = 182 ^ d;
  long int flag364 = 1115522681 ^ e;
  long int flag180 = -940414885 ^ c;
  long int flag350 = 1115522633 ^ e;
  long int flag229 = -940414900 ^ c;
  long int flag22 = -1709993546 ^ a;
  long int flag84 = 1556067261 ^ b;
  long int flag63 = -1709993552 ^ a;
  long int flag339 = 1115522633 ^ e;
  long int flag112 = 1556067232 ^ b;
  long int flag137 = 1556067239 ^ b;
  long int flag67 = -1709993552 ^ a;
  long int flag68 = -1709993551 ^ a;
  long int flag81 = 1556067251 ^ b;
  long int flag172 = -940414903 ^ c;
  long int flag25 = -1709993571 ^ a;
  long int flag245 = 176 ^ d;
  long int flag277 = 187 ^ d;
  long int flag49 = -1709993571 ^ a;
  long int flag168 = -940414904 ^ c;
  long int flag19 = -1709993551 ^ a;
  long int flag197 = -940414904 ^ c;
  long int flag183 = -940414882 ^ c;
  long int flag131 = 1556067251 ^ b;
  long int flag208 = -940414904 ^ c;
  long int flag226 = -940414910 ^ c;
  long int flag342 = 1115522633 ^ e;
  long int flag41 = -1709993561 ^ a;
  long int flag344 = 1115522680 ^ e;
  long int flag283 = 170 ^ d;
  long int flag150 = 1556067239 ^ b;
  long int flag372 = 1115522681 ^ e;
  long int flag281 = 177 ^ d;
  long int flag210 = -940414904 ^ c;
  long int flag13 = -1709993571 ^ a;
  long int flag154 = 1556067210 ^ b;
  long int flag261 = 173 ^ d;
  long int flag232 = -940414862 ^ c;
  long int flag18 = -1709993552 ^ a;
  long int flag385 = 1115522687 ^ e;
  long int flag161 = -940414892 ^ c;
  long int flag64 = -1709993561 ^ a;
  long int flag299 = 182 ^ d;
  long int flag362 = 1115522616 ^ e;
  long int flag345 = 1115522671 ^ e;
  long int flag351 = 1115522686 ^ e;
  long int flag366 = 1115522658 ^ e;
  long int flag206 = -940414882 ^ c;
  long int flag323 = 1115522687 ^ e;
  long int flag262 = 181 ^ d;
  long int flag109 = 1556067210 ^ b;
  long int flag263 = 157 ^ d;
  long int flag244 = 157 ^ d;
  long int flag240 = 157 ^ d;
  long int flag80 = 1556067258 ^ b;
  long int flag138 = 1556067248 ^ b;
  long int flag6 = -1709993543 ^ a;
  long int flag314 = 175 ^ d;
  long int flag181 = -940414904 ^ c;
  long int flag87 = 1556067239 ^ b;
  long int flag97 = 1556067248 ^ b;
  long int flag196 = -940414885 ^ c;
  long int flag124 = 1556067235 ^ b;
  long int flag193 = -940414862 ^ c;
  long int flag122 = 1556067239 ^ b;
  long int flag359 = 1115522657 ^ e;
  long int flag153 = 1556067306 ^ b;
  long int flag213 = -940414908 ^ c;
  long int flag177 = -940414862 ^ c;
  long int flag228 = -940414898 ^ c;
  long int flag130 = 1556067258 ^ b;
  long int flag211 = -940414881 ^ c;
  long int flag15 = -1709993561 ^ a;
  long int flag91 = 1556067239 ^ b;
  long int flag361 = 1115522657 ^ e;
  long int flag89 = 1556067235 ^ b;
  long int flag113 = 1556067210 ^ b;
  long int flag251 = 157 ^ d;
  long int flag373 = 1115522683 ^ e;
  long int flag296 = 187 ^ d;
  long int flag276 = 172 ^ d;
  long int flag242 = 173 ^ d;
  long int flag140 = 1556067248 ^ b;
  long int flag303 = 157 ^ d;
  long int flag159 = -940414904 ^ c;
  long int flag56 = -1709993561 ^ a;
  long int flag176 = -940414904 ^ c;
  long int flag236 = -940414887 ^ c;
  long int flag389 = 1115522636 ^ e;
  long int flag186 = -940414881 ^ c;
  long int flag327 = 1115522661 ^ e;
  long int flag388 = 1115522594 ^ e;
  long int flag47 = -1709993555 ^ a;
  long int flag379 = 1115522686 ^ e;
  long int flag65 = -1709993548 ^ a;
  long int flag307 = 169 ^ d;
  long int flag317 = 1115522675 ^ e;
  long int flag72 = -1709993552 ^ a;
  long int flag248 = 174 ^ d;
  long int flag217 = -940414910 ^ c;
  long int flag106 = 1556067210 ^ b;
  long int flag318 = 1115522633 ^ e;
  long int flag107 = 1556067249 ^ b;
  long int flag321 = 1115522659 ^ e;
  long int flag295 = 157 ^ d;
  long int flag167 = -940414885 ^ c;
  long int flag128 = 1556067248 ^ b;
  long int flag212 = -940414862 ^ c;
  long int flag157 = 1556067259 ^ b;
  long int flag83 = 1556067233 ^ b;
  long int flag94 = 1556067249 ^ b;
  long int flag69 = -1709993561 ^ a;
  long int flag386 = 1115522684 ^ e;
  long int flag204 = -940414862 ^ c;
  long int flag306 = 172 ^ d;
  long int flag145 = 1556067210 ^ b;
  long int flag348 = 1115522679 ^ e;
  long int flag17 = -1709993561 ^ a;
  long int flag101 = 1556067238 ^ b;
  long int flag11 = -1709993555 ^ a;
  long int flag337 = 1115522675 ^ e;
  long int flag4 = -1709993548 ^ a;
  long int flag246 = 167 ^ d;
  long int flag320 = 1115522681 ^ e;
  long int flag175 = -940414907 ^ c;
  long int flag134 = 1556067261 ^ b;
  long int flag151 = 1556067238 ^ b;
  long int flag377 = 1115522658 ^ e;
  long int flag179 = -940414904 ^ c;
  long int flag53 = -1709993556 ^ a;
  long int flag382 = 1115522603 ^ e;
  long int flag146 = 1556067239 ^ b;
  long int flag241 = 187 ^ d;
  long int flag253 = 170 ^ d;
  long int flag173 = -940414862 ^ c;
  long int flag264 = 182 ^ d;
  long int flag155 = 1556067238 ^ b;
  long int flag390 = 1115522675 ^ e;
  long int flag203 = -940414881 ^ c;
  long int flag102 = 1556067248 ^ b;
  long int flag260 = 172 ^ d;
  long int flag141 = 1556067239 ^ b;
  long int flag330 = 1115522633 ^ e;
  long int flag347 = 1115522657 ^ e;
  long int flag334 = 1115522675 ^ e;
  long int flag117 = 1556067210 ^ b;
  long int flag218 = -940414888 ^ c;
  long int flag290 = 157 ^ d;
  long int flag371 = 1115522677 ^ e;
  long int flag343 = 1115522679 ^ e;
  long int flag249 = 174 ^ d;
  long int flag227 = -940414862 ^ c;
  long int flag169 = -940414881 ^ c;
  long int flag36 = -1709993561 ^ a;
  long int flag363 = 1115522671 ^ e;
  long int flag152 = 1556067248 ^ b;
  long int flag129 = 1556067210 ^ b;
  long int flag70 = -1709993562 ^ a;
  long int flag338 = 1115522674 ^ e;
  long int flag92 = 1556067238 ^ b;
  long int flag269 = 177 ^ d;
  long int flag104 = 1556067258 ^ b;
  long int flag66 = -1709993561 ^ a;
  long int flag52 = -1709993561 ^ a;
  long int flag267 = 177 ^ d;
  long int flag387 = 1115522676 ^ e;
  long int flag252 = 177 ^ d;
  long int flag23 = -1709993558 ^ a;
  long int flag310 = 157 ^ d;
  long int flag29 = -1709993561 ^ a;
  long int flag258 = 157 ^ d;
  long int flag149 = 1556067248 ^ b;
  long int flag9 = -1709993571 ^ a;
  long int flag21 = -1709993571 ^ a;
  long int flag178 = -940414881 ^ c;
  long int flag62 = -1709993571 ^ a;
  long int flag143 = 1556067248 ^ b;
  long int flag367 = 1115522659 ^ e;
  long int flag7 = -1709993589 ^ a;
  long int flag394 = 1115522667 ^ e;
  long int flag120 = 1556067248 ^ b;
  long int flag82 = 1556067210 ^ b;
  long int flag346 = 1115522633 ^ e;
  long int flag189 = -940414904 ^ c;
  long int flag96 = 1556067239 ^ b;
  long int flag139 = 1556067235 ^ b;
  long int flag20 = -1709993561 ^ a;
  long int flag305 = 171 ^ d;
  long int flag45 = -1709993571 ^ a;
  long int flag171 = -940414904 ^ c;
  long int flag76 = -1709993552 ^ a;
  long int flag255 = 183 ^ d;
  long int flag115 = 1556067248 ^ b;
  long int flag162 = -940414910 ^ c;
  long int flag266 = 171 ^ d;
  long int flag164 = -940414862 ^ c;
  long int flag333 = 1115522656 ^ e;
  long int flag75 = -1709993561 ^ a;
  long int flag341 = 1115522680 ^ e;
  long int flag194 = -940414881 ^ c;
  long int flag222 = -940414909 ^ c;
  long int flag247 = 163 ^ d;
  long int flag300 = 183 ^ d;
  long int flag12 = -1709993545 ^ a;
  long int flag198 = -940414881 ^ c;
  long int flag27 = -1709993561 ^ a;
  long int flag166 = -940414904 ^ c;
  long int flag291 = 187 ^ d;
  long int flag272 = 164 ^ d;
  long int flag77 = -1709993551 ^ a;
  long int flag220 = -940414886 ^ c;
  long int flag302 = 167 ^ d;
  long int flag304 = 174 ^ d;
  long int flag297 = 173 ^ d;
  long int flag352 = 1115522658 ^ e;
  long int flag182 = -940414881 ^ c;
  long int flag286 = 167 ^ d;
  long int flag191 = -940414882 ^ c;
  long int flag250 = 187 ^ d;
  long int flag187 = -940414904 ^ c;
  long int flag259 = 169 ^ d;
  long int flag219 = -940414862 ^ c;
  long int flag207 = -940414881 ^ c;
  long int flag32 = -1709993561 ^ a;
  long int flag74 = -1709993548 ^ a;
  long int flag265 = 170 ^ d;
  long int flag108 = 1556067258 ^ b;
  long int flag100 = 1556067239 ^ b;
  long int flag273 = 164 ^ d;
  long int flag79 = 1556067210 ^ b;
  long int flag313 = 173 ^ d;
  long int flag238 = 163 ^ d;
  long int flag384 = 1115522606 ^ e;
  long int flag147 = 1556067248 ^ b;
  long int flag301 = 160 ^ d;
  long int flag195 = -940414904 ^ c;
  long int flag46 = -1709993541 ^ a;
  long int flag57 = -1709993546 ^ a;
  long int flag28 = -1709993548 ^ a;
  long int flag309 = 171 ^ d;
  long int flag287 = 157 ^ d;
  long int flag202 = -940414910 ^ c;
  long int flag114 = 1556067250 ^ b;
  long int flag354 = 1115522662 ^ e;
  long int flag144 = 1556067249 ^ b;
  long int flag42 = -1709993571 ^ a;
  long int flag40 = -1709993551 ^ a;
  long int flag156 = 1556067260 ^ b;
  long int flag1 = -1709993565 ^ a;
  long int flag392 = 1115522595 ^ e;
  long int flag214 = -940414901 ^ c;
  long int flag185 = -940414862 ^ c;
  long int flag336 = 1115522661 ^ e;
  long int flag90 = 1556067248 ^ b;
  long int flag288 = 171 ^ d;
  long int flag209 = -940414885 ^ c;
  long int flag332 = 1115522675 ^ e;
  long int flag5 = -1709993552 ^ a;
  long int flag285 = 176 ^ d;
  long int flag355 = 1115522661 ^ e;
  long int flag308 = 157 ^ d;
  long int flag322 = 1115522633 ^ e;
  long int flag254 = 173 ^ d;
  long int flag38 = -1709993561 ^ a;
  long int flag26 = -1709993552 ^ a;
  long int flag99 = 1556067248 ^ b;
  long int flag73 = -1709993561 ^ a;
  long int flag233 = -940414908 ^ c;
  long int flag118 = 1556067233 ^ b;
  long int flag0 = -1709993547 ^ a;
  long int flag31 = -1709993551 ^ a;
  long int flag105 = 1556067239 ^ b;
  long int flag357 = 1115522617 ^ e;
  long int flag78 = -1709993561 ^ a;
  long int flag119 = 1556067261 ^ b;
  long int flag369 = 1115522675 ^ e;
  long int flag282 = 157 ^ d;
  long int flag200 = -940414904 ^ c;
  long int flag289 = 177 ^ d;
  long int flag215 = -940414862 ^ c;
  long int flag257 = 166 ^ d;
  long int flag127 = 1556067238 ^ b;
  long int flag10 = -1709993541 ^ a;
  long int flag51 = -1709993558 ^ a;
  long int flag268 = 157 ^ d;
  long int flag216 = -940414892 ^ c;
  long int flag205 = -940414904 ^ c;
  long int flag37 = -1709993548 ^ a;
  long int flag8 = -1709993564 ^ a;
  long int flag16 = -1709993548 ^ a;
  long int flag335 = 1115522660 ^ e;
  long int flag298 = 183 ^ d;
  long int flag86 = 1556067210 ^ b;
  long int flag271 = 183 ^ d;
  long int flag393 = 1115522643 ^ e;
  long int flag111 = 1556067258 ^ b;
  long int flag34 = -1709993571 ^ a;
  long int flag280 = 187 ^ d;
  long int flag235 = -940414862 ^ c;
  long int flag391 = 1115522675 ^ e;
  long int flag60 = -1709993558 ^ a;
  long int flag274 = 157 ^ d;
  long int flag312 = 176 ^ d;
  long int flag88 = 1556067248 ^ b;
  long int flag293 = 183 ^ d;
  long int flag71 = -1709993571 ^ a;
  long int flag14 = -1709993552 ^ a;
  long int flag188 = -940414885 ^ c;
  long int flag374 = 1115522617 ^ e;
  long int flag55 = -1709993563 ^ a;
  long int flag33 = -1709993562 ^ a;
  long int flag133 = 1556067233 ^ b;
  long int flag383 = 1115522655 ^ e;
  long int flag230 = -940414911 ^ c;
  long int flag378 = 1115522677 ^ e;
  long int flag237 = 170 ^ d;
  long int flag201 = -940414862 ^ c;
  long int flag311 = 178 ^ d;
  long int flag256 = 174 ^ d;
  long int flag234 = -940414887 ^ c;
  long int flag3 = -1709993561 ^ a;
  long int flag123 = 1556067248 ^ b;
  long int flag85 = 1556067248 ^ b;
  long int flag275 = 163 ^ d;
  long int flag136 = 1556067210 ^ b;
  long int flag353 = 1115522658 ^ e;
  long int flag142 = 1556067238 ^ b;
  long int flag292 = 173 ^ d;
  long int flag270 = 182 ^ d;
  long int flag360 = 1115522657 ^ e;
  long int flag224 = -940414862 ^ c;
  long int flag126 = 1556067239 ^ b;
  long int flag121 = 1556067210 ^ b;
  long int flag59 = -1709993546 ^ a;
  long int flag278 = 181 ^ d;
  long int flag380 = 1115522601 ^ e;
  long int flag54 = -1709993571 ^ a;
  long int flag331 = 1115522660 ^ e;
  int is_correct = 1;
  is_correct = ((a & 0xff)*(b & 0xff)*(c & 0xffff))-((c*d*e) & 0xffff) >> 8;
  int isreally = check_it(flag0, flag1, flag2, flag3, flag4, flag5, flag6, flag7, flag8, flag9, flag10, flag11, flag12, flag13, flag14, flag15, flag16, flag17, flag18, flag19, flag20, flag21, flag22, flag23, flag24, flag25, flag26, flag27, flag28, flag29, flag30, flag31, flag32, flag33, flag34, flag35, flag36, flag37, flag38, flag39, flag40, flag41, flag42, flag43, flag44, flag45, flag46, flag47, flag48, flag49, flag50, flag51, flag52, flag53, flag54, flag55, flag56, flag57, flag58, flag59, flag60, flag61, flag62, flag63, flag64, flag65, flag66, flag67, flag68, flag69, flag70, flag71, flag72, flag73, flag74, flag75, flag76, flag77, flag78, flag79, flag80, flag81, flag82, flag83, flag84, flag85, flag86, flag87, flag88, flag89, flag90, flag91, flag92, flag93, flag94, flag95, flag96, flag97, flag98, flag99, flag100, flag101, flag102, flag103, flag104, flag105, flag106, flag107, flag108, flag109, flag110, flag111, flag112, flag113, flag114, flag115, flag116, flag117, flag118, flag119, flag120, flag121, flag122, flag123, flag124, flag125, flag126, flag127, flag128, flag129, flag130, flag131, flag132, flag133, flag134, flag135, flag136, flag137, flag138, flag139, flag140, flag141, flag142, flag143, flag144, flag145, flag146, flag147, flag148, flag149, flag150, flag151, flag152, flag153, flag154, flag155, flag156, flag157, flag158, flag159, flag160, flag161, flag162, flag163, flag164, flag165, flag166, flag167, flag168, flag169, flag170, flag171, flag172, flag173, flag174, flag175, flag176, flag177, flag178, flag179, flag180, flag181, flag182, flag183, flag184, flag185, flag186, flag187, flag188, flag189, flag190, flag191, flag192, flag193, flag194, flag195, flag196, flag197, flag198, flag199, flag200, flag201, flag202, flag203, flag204, flag205, flag206, flag207, flag208, flag209, flag210, flag211, flag212, flag213, flag214, flag215, flag216, flag217, flag218, flag219, flag220, flag221, flag222, flag223, flag224, flag225, flag226, flag227, flag228, flag229, flag230, flag231, flag232, flag233, flag234, flag235, flag236, flag237, flag238, flag239, flag240, flag241, flag242, flag243, flag244, flag245, flag246, flag247, flag248, flag249, flag250, flag251, flag252, flag253, flag254, flag255, flag256, flag257, flag258, flag259, flag260, flag261, flag262, flag263, flag264, flag265, flag266, flag267, flag268, flag269, flag270, flag271, flag272, flag273, flag274, flag275, flag276, flag277, flag278, flag279, flag280, flag281, flag282, flag283, flag284, flag285, flag286, flag287, flag288, flag289, flag290, flag291, flag292, flag293, flag294, flag295, flag296, flag297, flag298, flag299, flag300, flag301, flag302, flag303, flag304, flag305, flag306, flag307, flag308, flag309, flag310, flag311, flag312, flag313, flag314, flag315, flag316, flag317, flag318, flag319, flag320, flag321, flag322, flag323, flag324, flag325, flag326, flag327, flag328, flag329, flag330, flag331, flag332, flag333, flag334, flag335, flag336, flag337, flag338, flag339, flag340, flag341, flag342, flag343, flag344, flag345, flag346, flag347, flag348, flag349, flag350, flag351, flag352, flag353, flag354, flag355, flag356, flag357, flag358, flag359, flag360, flag361, flag362, flag363, flag364, flag365, flag366, flag367, flag368, flag369, flag370, flag371, flag372, flag373, flag374, flag375, flag376, flag377, flag378, flag379, flag380, flag381, flag382, flag383, flag384, flag385, flag386, flag387, flag388, flag389, flag390, flag391, flag392, flag393, flag394, inp);
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
