#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringlib.h"
int main(){
#define TXT 1024
#define WORD 30
char word[WORD];
char text[TXT];
// char w=getchar();
// int i=0;
// while(w!= '\n'){
// word[i]=w;
// i++;
// w=getchar();
// }
char ch;
size_t i;
int k=0;
for (i = 0; i < WORD-1; i++)
{
     ch=getchar();
    if (!isEnd(ch))
    {
    word[i]=ch;
}
else{
   break;
}
k++;
}
word[k]='\0';

char c=getchar();
int j=0;
while(c!='~'){
text[j]=c;
j++;
c=getchar();
}
text[j]='~';
text[++j]='\0';
printf("Gematria Sequences: ");
gimetria(word,text);
printf("\n");
printf("Atbash Sequences: ");
char * wa=atbashWord(word);
atbash(wa,text);
printf("\n");
printf("Anagram Sequences: ");
anagram(word, text);
printf("\n");



return 0;
}






