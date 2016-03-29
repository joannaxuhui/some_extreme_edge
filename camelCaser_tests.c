#include "camelCaser_tests.h"

#include "camelCaser.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
//testcase 1
int test(char ** dest, char* source[] )
{
    //assert(dest!=NULL);
    if(dest==NULL && source==NULL)
    return 1;
   
    int a=1;
    if(dest)
	{    
        char**pd=dest;
	   int j=0;
        int n1=0;
        int n2=0;
		//printf("this is the my answer.\n");
        
          while(*pd!=NULL)
		{
			//printf("'%s'\n",*pd);
			pd++;
			n1++;
		}
   	    //printf("this is the right answer.\n");
         while(source[j]!=NULL)
		{
			//printf("'%s'\n",source[j]);
			j++;
               n2++;
		} 

         
          if(n1!=n2)
          return 0;
		//printf("n1 is %d\n",n1);
		//printf("n2 is %d\n",n2);
		char** line=dest;
		int i =0;
		while(*line)
		{
			if(strcmp(*line,*source)!=0)
			{
				a=0;	
			} 
			line++;
			source++;
		}
	}
	return a;
}
void des(char** input,char* original)
{
     int dot_num=0;
     const char* dot=original;
	while(*dot)
     {
		if(*dot=='.')
		dot_num++;
		dot++;
	}
    for(int i=0; i<dot_num; i++)
	{
	free (input[i]);  
	}
     free (input);   
}


int test_camelCaser (char ** (* camelCaser)(const char *))
{   
       char* a1="1huigyy,HUigH112qQ.";
       char* a2="HELL,\t,\n,word,+,1,";
	  char* a3="111.11";
	  char* a4="";
	  char* a5="ttest ++ ++ ttest333.";
    	  char* a6=";';;::";
       char* a7="hello world.";
       char* a8="5hello 4world.";
       

       char** result1=camelCaser(a1);
       char** result2=camelCaser(a2);
	  char** result3=camelCaser(a3);
       char** result4=camelCaser(a4);
       char** result5=camelCaser(a5);
 	  char** result6=camelCaser(a6);
	  char** result7=camelCaser(a7);
       char** result8=camelCaser(a8);

       char* inputs1[]={"1huigyy","huigh112qq",NULL};
       char* inputs2[]={"hell","","","word","","","1",NULL};
	  char* inputs3[]={"111",NULL};
       char* inputs4[]={NULL};
	  char* inputs5[]={"ttest","","","","ttest333",NULL};
	  char* inputs6[]={"","","","","","",NULL};
	  char* inputs7[]={"helloWorld",NULL};
       char* inputs8[]={"5hello4World",NULL};

        
       
       int r1=test(result1,inputs1);
       int r2=test(result2,inputs2);
	  int r3=test(result3,inputs3);
       int r4=test(result4,inputs4);
       int r5=test(result5,inputs5);
       int r6=test(result6,inputs6);
       int r7=test(result7,inputs7);
       int r8=test(result8,inputs8);


     des(result1,a1);
	des(result2,a2);
    	des(result3,a3);
	des(result4,a4);
	des(result5,a5);
	des(result6,a6);
	des(result7,a7);
     des(result8,a8);
	return r1&&r2&&r3&&r4&&r5&&r6&&r7&&r8;

		

     

     
}
