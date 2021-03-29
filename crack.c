#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int main(int argc, string argv[])
{
    int f[4]={0,0,0,0}, cn;
    char salt[3], pass[6];
    string hash;
   
    if(argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
// Determine SALT
    salt[0]=argv[1][0];
    salt[1]=argv[1][1];
    salt[2]='\0';
// Brutal force PASSWORD crack
// f[] used as marker of pasword length
    pass[5]='\0';
        for (pass[4]=33; pass[4]<=126; pass[4]++)
        {
            if(f[3] == 0){ pass[4]='\0';}
            for(pass[3]=33; pass[3]<=126; pass[3]++)
            {
                if(f[2] == 0){ pass[3]='\0';}               
                for(pass[2]=33; pass[2]<=126; pass[2]++)
                {
                    if(f[1] == 0){ pass[2]='\0';}                  
                    for(pass[1]=33; pass[1]<=126; pass[1]++)
                    {
                        if(f[0] == 0){ pass[1]='\0';}
                        for(pass[0]=33; pass[0]<=126; pass[0]++)
                        {
                                if(strcmp(crypt(pass,salt),argv[1]) == 0)
                                {
                                    printf("%s\n",pass);
                                    return 0;
                                }
                        }
                        if(f[0] == 0){ pass[1]=33; f[0]=1;}
                    }
                    if(f[1] == 0){ pass[2]=33; f[1]=1;}    
                }
                if(f[2] == 0){ pass[3]=33; f[2]=1;}
            }
            if(f[3] == 0){ pass[4]=33; f[3]=1;} 
        }
    
    printf("sorry, can't crack\n");
    return 1;                 
}
