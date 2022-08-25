#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int check_character(string str)
{
    for (int i = 0; i < 26; i++)
    {
        if ((isalpha(str[i])))
        {
            //nothing to do;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int check_count(string str)
{
    int num[26];
    int uppercase = 65, lowercase = 97;
    for (int i = 0; i < 26 ; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (str[j] == uppercase || str[j] == lowercase)
            {
                num[i] = 1;
            }
        }
        if (num[i] != 1)
        {
            num[i] = 0;
        }
        ++uppercase;
        ++lowercase;
    }

    for (int i = 0; i < 26; i++)
    {
        if (num[i] == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, string argv[])
{
     string plaintext;

    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (check_character(argv[1]))
    {
        printf("Key should not contain non-alphabetic characters.\n");
        return 1;
    }
    if (check_count(argv[1]))
    {
        printf("Key should contain unique alphabetic characters.\n");
        return 1;
    }
    else
    {
        string key=argv[1];
        plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");
        for(int i=0;i<strlen(plaintext);i++)
        {
            int uppercase = 65, lowercase = 97, flag = 0;

            for (int j = 0; j < 26; j++)
            {
                if(plaintext[i] == uppercase || plaintext[i] == lowercase)
                {
                    if(isupper(plaintext[i]))
                    {
                      printf("%c",toupper(key[j]));
                      flag=1;
                    }
                    else
                    {
                    printf("%c",tolower(key[j]));
                    flag=1;
                    }
                }
                ++uppercase;
                ++lowercase;
            }
            if(flag==0)
            {
                printf("%c",plaintext[i]);
            }
        }
        printf("\n");
    }
return 0;
}