#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringlib.h"

void gimetria(char * word, char * txt)
{
    int word_sum = checkWordGimetria(word);
    //set two pointers for run all over the text and check each char
    char * s =txt; 
    char * e =txt; 
    int flag = 0;
    while (*e!='~')//the end of the text
    {
        if(charValue(*e) != 0)//if the char is a valid char
        {
            int cur_sum = 0;
            char * d=s;
            while (d<=e)
            {
                cur_sum = cur_sum + charValue(*d);
                d++;
                
            }
        
            if(cur_sum == word_sum)
            {
                flag ++;
                char *c1 = s;
                char *first = s;
                char *c2 = e;
                if(flag ==1)
                {
                     while (c1 != c2)
                {
                    if(charValue(*first) ==0)
                    {
                        first++;
                        c1++;
                
                    }else
                    {
                    printf("%c", *c1);
                    c1++;
                    }
                    
                }
                printf("%c", *c1);
                }
                else
                {
                  printf("~");

                while (c1 != c2)
                {
                    if(charValue(*first) ==0)
                    {
                        first++;
                        c1++;
                
                    }else
                    {
                    printf("%c", *c1);
                    c1++;
                    }
                    
                }
                printf("%c", *c1);
                }
                e++;
            }
            else if ( cur_sum > word_sum)
            {
                s++;
                
            }
            else
            {
                e++;
            }
            
        }
        else
        {
            e++;
            
            
        }
    }
}
int charValue (int a)//retruen the gimetri value of the char
{
         if (a>=65&&a<=90)
        {
            return a - 64;
         }
         else if (a<=122&&a>96)
         {
              return a-96;
        }
    return 0;
}

int checkWordGimetria(char * word)//return the gimetri sum of the word
{
    int sum =0;
    int len = strlen(word);
    for (int i=0;i<len;i++)
    {
        sum = sum +charValue((int)word[i]);
    }
    return sum;
}
int atbashTrans(char a)//return the atbash value of the char
{
    int t =charValue(a);
    if (a>=65&&a<=90)
        {
            return 91 - t;
         }
         else if (a<=122&&a>96)
         {
              return 123 - t;
        }
        return 0;
}
int boolCheck(char* original, char* s)//check if the word is like the atbash word
{   
    char *start =s;
    char *rev =reverse(original);
    if(*s ==original[0])
    {
    for(int i = 0;i < strlen(original);i++)
    {
        if(start[i] != original[i])
        {
            return 0;
        }
    }
    return 1;
    }
    else if(*s == rev[0])
    {
        for(int i = 0;i < strlen(original);i++)
    {
        if(start[i] != rev[i])
        {
            return 0;
        }
    }
    return 1;
    }
    else
    {
        return 0;
    }

}
int sumAtbashWord(char *word)//return the atbash sum of the word
{
    int sum = 0;
    int len = strlen(word);
    int i=0;
    while (i<len)
    {
        sum = sum +charValue(word[i]);
        i++;
    }
    return sum;
}


char *reverse(char *x)//return the string of the reverse atbash word
{
    int j=0;
    int len = strlen(x);
    char * rev = ((char *)malloc(sizeof(char)*len));
    for (int i = len-1;i>=0;i--)
    {
         rev[j] = x[i];
         j++;
    }
    return rev;
}



char *atbashWord(char *word)//this function translate the word to atbash
{
    int len = strlen(word);
    char* Aword =(char*)malloc(sizeof(char)*len);
    int len2 = strlen(word);
    char *s = word;
    int i = 0;
    while (i<len2)
        {
       Aword[i] = atbashTrans(*s);
       s++;
       i++;
        }

    return Aword;
}
void atbash(char *word, char *text)
{
    int flag =0;
int word_sum = sumAtbashWord(word);
    //set two pointers for run all over the text and check each char
    char * s =text; 
    char * e =text; 

    while (*e!='~')//the end of the text
    {
        if(atbashTrans(*e) != 0)//if the char is a valid char
        {
            int cur_sum = 0;
            char * d=s;
            while (d<=e)
            {
                cur_sum = cur_sum + charValue(*d);
                d++; 
            }
        
            if(cur_sum == word_sum)
            {
                char check[e-s];
                char *c1 = s;
                char *first = s;
                char *c2 = e;
                int i=0;
                while (c1 <=c2)
                {
                    if(atbashTrans(*first) ==0)
                    {
                        first++;
                        c1++;
                    }
                
                    check[i] = *c1;
                    i++;
                    c1++;
                }
                char *d = word;
                if(boolCheck(d,check))
                {
                    char *first2 = s;
                    char *c3 = s;
                    char *c4 = e;
                    if(atbashTrans(*first2) ==0)
                    {
                        first2++;
                        c3++;
                    }
            if (flag==1)
                {
                    while (c3<=c4)
                        {
                           printf("%c",*c3);
                            c3++;
                        }
                }else{
                    printf("~");
                     while (c3<=c4)
                        {
                           printf("%c",*c3);
                            c3++;
                        }
                }
                e++;
                }else{
                    s++;
                    e=s;
                }
            }  
            else if( cur_sum > word_sum)
            {
                s++;
            }
            else
            {
                e++;
            }
            
        }
        else
        {
            e++;
              
        }
    }
}
void anagram(char * word, char * txt)
{
    int flag = 0;
    int word_sum = checkWordGimetria(word);
    //set two pointers for run all over the text and check each char
    char * s =txt; 
    char * e =txt; 

    while (*e!='~')//the end of the text
    {
        if(charValue(*e) != 0)//if the char is a valid char
        {
            int cur_sum = 0;
            char * d=s;
            while (d<=e)
            {
                cur_sum = cur_sum + charValue(*d);
                d++;
                
            }
        
           if(cur_sum == word_sum)
            {
               
                char q[30];
                 char *c1 = s;
                char *first = s;
                char *c2 = e;
                int i = 0;
                while (c1 <= c2)
                {
                  q[i] = *c1;
                  c1++;
                  i++;
                }
                q[i] = '\0';
                if(anagramBoolCheck(word,q))
                {
                    flag++;
                char *c1 = s;
                char *first = s;
                char *c2 = e;
                if (flag==1)
                {
                     while (c1 <= c2)
                {
                    if(charValue(*first) ==0)
                    {
                        first++;
                        c1++;
                
                    }else
                    {
                    printf("%c", *c1);
                    c1++;
                    }
                    
                }
                }else{
                    printf("~");
                         while (c1 <= c2)
                {
                    if(charValue(*first) ==0)
                    {
                        first++;
                        c1++;
                
                    }else
                    {
                    printf("%c", *c1);
                    c1++;
                    }
                    
                } 
                }
                
                while (c1 <= c2)
                {
                    if(charValue(*first) ==0)
                    {
                        first++;
                        c1++;
                
                    }else
                    {
                    printf("%c", *c1);
                    c1++;
                    }
                    
                }
                
                e++;
                }
                else{
                    s++;
                    e=s;
                }
            }
            else if ( cur_sum > word_sum)
            {
                s++; 
            }
            else
            {
                e++;
            }
            
        }
        else
        {
            e++;  
        }
    }  
    
}
    



int anagramBoolCheck(char * word, char* check)
{
    char *x = (char*)malloc(sizeof(char)*strlen(word));
    // char x[strlen(word)];
    const int len =strlen(check);
    for ( int i = 0; i < strlen(check);i++)
    {
        if(check[i] >32 &&check[i] < 65)
        {
            return 0;
        }
        int flag = 0;
        for (int j = 0; j < strlen(word);)
        {
            if ((check[i] == word[j])&&flag ==0&&x[j]!='1')
            {
               x[j] = '1'  ;
               flag =1;  
            }
            j++;
        }
    }
    for (int h = 0 ; h < strlen(word);h++)
    {
        if(x[h]!='1')
        {
            return 0;

        }
    }
    free(x);
return 1;
}
int isEnd(char ch){

    return ((ch==' ')||(ch=='\t')||((ch=='\n')));

}



// int main(){
// #define TXT 1024
// #define WORD 30
// char word[WORD];
// char text[TXT];
// printf("please enter a word:");
// // char w=getchar();
// // int i=0;
// // while(w!= '\n'){
// // word[i]=w;
// // i++;
// // w=getchar();
// // }
// char ch;
// size_t i;
// int k=0;
// for (i = 0; i < WORD-1; i++)
// {
//      ch=getchar();
//     if (!isEnd(ch))
//     {
//     word[i]=ch;
// }
// else{
//    break;
// }
// k++;
// }
// word[k]='\0';

// printf("please enter a text:");
// char c=getchar();
// int j=0;
// while(c!='~'){
// text[j]=c;
// j++;
// c=getchar();
// }
// text[j]='~';
// text[++j]='\0';
// printf("Gimetria Sequences:");
// gimetria(word,text);
// printf("\n");
// printf("Atbash Sequences:");
// char * wa=atbashWord(word);
// atbash(wa,text);
// printf("\n");
// printf("Anagram Sequences:");
// anagram(word, text);
// printf("\n");



// return 0;
// }


// int main()
// {
// // int i = anagramBoolCheck("feacer", "ecrfe");
// // printf("%d", i);
// anagram("fish","One, nine, three, four, five,\nOnce I caught a fish alive,\nSix, seven, eight, nine, ten,\nThen I let go again.~");

// return 0;
// }






































































