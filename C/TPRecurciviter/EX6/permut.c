#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* insert(char* sprim, char c, int i)
{
    char * spp = malloc(strlen(sprim) + 1);

    int sindex = 0;
    for (int y = 0; y < strlen(sprim) + 1;y++)
    {
        if (i == y)
        {
            spp[y] = c;
        }else
        {
            spp[y]=sprim[sindex];
            sindex++;
        }
    }
    //printf("%s", spp);
    return spp;
}

void permut(char* s, int i)
{
    char* sprim = malloc(strlen(s)-1);

    //Split de s
    char fixed = s[0];
    for (int y = 1;y<strlen(s);y++)
    {
        sprim[y] = s[y];
    }


    //condition d'arret
    if (i==strlen(s))
    {
        free(s);
        free(sprim);
        return;
    }

    //Permutation du reste de s : s[0] + toutes les permut de s'
    char * spp;
    for (int y=0; y< strlen(sprim);y++)
    {
        spp = insert(sprim,fixed,y);
        printf("%s\n",spp);
    }

    free(sprim);

    //recurciviter
    return permut(s,i+1);
}

int main()
{
    char* s = malloc(sizeof(char)*4);
    strcpy(s,"bc");
    //permut(s,0);

    printf("%s", insert(s,'a',0));

    return 0;
}