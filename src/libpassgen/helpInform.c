#include "helpInform.h"

void helpInformation()
{
    printf("\tHelp information\n\n");
    printf("\tInput format:\n");
    printf("./genpw [option] [length] [number]\n\n");
    printf("\tPassword Properties:\n");
    printf("./genpw -sa <<Password consisting only of letters in "
           "lowercase>>\n");
    printf("./genpw -sAa <<Password consisting of letters in lowercase and "
           "uppercase>>\n");
    printf("./genpw -sAa0 <<Password consisting of letters in lowercase, "
           "uppercase and number>>\n");
    printf("./genpw -sAa0! <<Password consisting only of letters in lowercase, "
           "uppercase, numbers and special symbols>>\n");
    printf("./genpw -sBn5! <<Password consisting only of letters in lowercase, "
           "uppercase, numbers and special symbols>>\n");
    printf("<<You can also write any other type of symbols, like a,b,c,...; "
           "A,B,C,...; 0,1,2,...; <,>,!,/,?,... >>\n\n");
    printf("./genpw --mod=easy <<Is equal to properties: -a -l8 -c1>>\n");
    printf("./genpw --mod=medium <<Is equal to properties: -Aa0 -l8 -c1>>\n");
    printf("./genpw --mod=hard <<Is equal to properties: -Aa0! -l8 -c1>>\n");
    printf("./genpw -l10  <<Property related to the length of the "
           "password>>\n");
    printf("./genpw -c20  <<Property related to the count of the "
           "passwords>>\n");
}
