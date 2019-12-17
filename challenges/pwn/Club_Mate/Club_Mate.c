#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

struct club_mate {
        char a1[20];
        char a2[20];
        char a3[20];
        bool isInMachine;
};

void printFlag(){
        printf("%s\n", "[REDACTED]");
        printf("%s\n", "[REDACTED]");
}

bool hazCanInMachine(struct club_mate bottles[15]){
        int index;
        for(index = 0; index < 15; index++) {
                if(bottles[index].isInMachine) {
                        return true;
                }
        }
        return false;
}

void sig(int sign){
	exit(0);
}

int main()
{
	signal(SIGALRM, sig);
 	alarm(40);
        unsigned char money = 255; //mcDonald's hired you as their *national* security expert and now you are the richest mcDonald's employee!
        struct club_mate bottles[15];
        char can[2];
        int i = 0;
        int tmpVar = 18;

        while(true) {
                if(250 + tmpVar < money) {
                        printFlag();
                }

                while(i < 15) {
                        strcpy(bottles[i].a1, "\033[0;33m /\\\033[0m");
                        strcpy(bottles[i].a2, "\033[0;33m ||\033[0m");
                        strcpy(bottles[i].a3, "\033[0;33m ¯¯\033[0m");
                        bottles[i].isInMachine = true;
                        tmpVar--;
                        i += 1;
                }
                while(hazCanInMachine(bottles)) {
                        char can[4];
                        strcpy(can, "");
                        char payment[16];
                        strcpy(payment, "");
                        printf("%s\n", "You have been pwning all day and it has made you really thirsty!\nLucky for you i just finished building a club-mate vending machine!");
                        printf("balance: %i\n", money);
                        printf("%s\n", ".---------------.");
                        printf("%s","|");
                        printf("%s",bottles[0].a1);
                        printf("%s",bottles[1].a1);
                        printf("%s",bottles[2].a1);
                        printf("%s",bottles[3].a1);
                        printf("%s",bottles[4].a1);
                        printf("%s","|\n");
                        printf("%s","|");
                        printf("%s",bottles[0].a2);
                        printf("%s",bottles[1].a2);
                        printf("%s",bottles[2].a2);
                        printf("%s",bottles[3].a2);
                        printf("%s",bottles[4].a2);
                        printf("%s","|\n");
                        printf("%s","|");
                        printf("%s",bottles[0].a3);
                        printf("%s",bottles[1].a3);
                        printf("%s",bottles[2].a3);
                        printf("%s",bottles[3].a3);
                        printf("%s",bottles[4].a3);
                        printf("%s","|\n");
                        printf("%s","|               |\n");
                        printf("%s","|");
                        printf("%s",bottles[5].a1);
                        printf("%s",bottles[6].a1);
                        printf("%s",bottles[7].a1);
                        printf("%s",bottles[8].a1);
                        printf("%s",bottles[9].a1);
                        printf("%s","|\n");
                        printf("%s","|");
                        printf("%s",bottles[5].a2);
                        printf("%s",bottles[6].a2);
                        printf("%s",bottles[7].a2);
                        printf("%s",bottles[8].a2);
                        printf("%s",bottles[9].a2);
                        printf("%s","|\n");
                        printf("%s","|");
                        printf("%s",bottles[5].a3);
                        printf("%s",bottles[6].a3);
                        printf("%s",bottles[7].a3);
                        printf("%s",bottles[8].a3);
                        printf("%s",bottles[9].a3);
                        printf("%s","|\n");
                        printf("%s","|               |\n");
                        printf("%s","|");
                        printf("%s",bottles[10].a1);
                        printf("%s",bottles[11].a1);
                        printf("%s",bottles[12].a1);
                        printf("%s",bottles[13].a1);
                        printf("%s",bottles[14].a1);
                        printf("%s","|\n");
                        printf("%s","|");
                        printf("%s",bottles[10].a2);
                        printf("%s",bottles[11].a2);
                        printf("%s",bottles[12].a2);
                        printf("%s",bottles[13].a2);
                        printf("%s",bottles[14].a2);
                        printf("%s","|\n");
                        printf("%s","|");
                        printf("%s",bottles[10].a3);
                        printf("%s",bottles[11].a3);
                        printf("%s",bottles[12].a3);
                        printf("%s",bottles[13].a3);
                        printf("%s",bottles[14].a3);
                        printf("%s\n","|");
                        printf("%s", "|               |\n");
                        printf("%s\n", "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
                        printf("%s\n", "Enter which club-mate you want to buy/return: "); //0-14
                        scanf("%2s", can);
                        fflush(stdin);
                        int bottle = atoi(can);
                        int securityCheck = money;

                        if(bottles[atoi(can)].isInMachine)
                        {
                                printf("%s", "the ");
                                printf("%s", can);
                                printf("%s\n", " it is!");
                                printf("%s\n", "That will be $4");
                                //this time you actually have money with you!
                                scanf("%16s", payment);
                                if(!strcmp("$4", payment))
                                {
                                        printf("%s\n", "Thanks, here is your club-mate!");
                                        strcpy(bottles[bottle].a1, "   ");
                                        strcpy(bottles[bottle].a2, "   ");
                                        strcpy(bottles[bottle].a3, "   ");
                                        bottles[bottle].isInMachine = false;
                                        money -= 4;
                                }
                        }

                        else if(bottles[atoi(can)].isInMachine)
                        {
                                printf("%s", "I asked for $4 not ");
                                printf("%s", payment);
                                printf("\n");
                        }

                        else
                        {
                                char returnCan[4];
                                printf("Would you like to return can number ");
                                printf("%s", can);
                                printf("%s", "?\n");
                                scanf("%3s", returnCan);

                                if(!strcmp(returnCan, "yes") || !strcmp(returnCan, "Yes"))
                                {
                                        bottles[bottle].isInMachine = true;
                                        strcpy(bottles[bottle].a1, "\033[0;33m /\\\033[0m");
                                        strcpy(bottles[bottle].a2, "\033[0;33m ||\033[0m");
                                        strcpy(bottles[bottle].a3, "\033[0;33m ¯¯\033[0m");
                                        while(tmpVar != 0) {
                                                int calc = ~(~money | ~tmpVar);
                                                money = money ^ tmpVar;
                                                tmpVar = calc << 1;
                                        }
                                        tmpVar = abs(securityCheck-money);
                                }

                        }
                }
        }
        return 0;
}
