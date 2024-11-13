#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
  int i,key,zero;
  char c;
  char str[20];
  char enc[20];
  printf("Enter the text:");
  gets(str);
  printf("Enter the key:");
  scanf("%d",&key);
  for(i=0;i<20;i++)
  {
    if(str >= 'a' && str[i] <='z')
    { if (str[i] == 'z')
      { str[i]='a'; }
      else 
      { str[i] = str[i] + key; }
    }
  }
  printf("The encrypted text is : %s\n",str);
  for(i=0;i<20;i++)
  { 
      if(str >= 'a' && str[i] <='z')
    { if (str[i] == 'z')
      { str[i]='a'; }
      else 
      { str[i] = str[i] - key; }
    }
  }
  printf("The decrypted text is : %s\n",str);
}
