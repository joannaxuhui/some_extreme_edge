#include "camelCaser.h"
#include <stddef.h>
#include "string.h"
#include <stdio.h>
#include <ctype.h>

#define _GNU_SOURCE


char **camel_caser(const char *input_str) {

	if(input_str==NULL)
	return NULL;
	//allocate memory
	int length=sizeof(input_str);
	char** result=malloc(length*sizeof(char*));
	//allocate memory
	for(int i=0; i<length; i++)
	result[i]=malloc(length*sizeof(char));
	// read the subline
	while(*input_str!='\0')
	{
		int i=0;
		if(ispunct(*input_str))
		i++;
		else if(isalpha(*input_str))
		{
		strcat(result[i],*input_str);
		}
		
		input_str++;
	}
	for(int i=0; i<length; i++)
	{
		if(*result[i]>'A' && *result[i]<'Z')
		*result[i]+=32;
		else if(*result[i]>'a' && *result[i]<'z')
		*result[i]-=32;
	}

}
