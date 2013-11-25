#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PHONE 10;
#define MAX_CHARS 100;
#define MAX_EMAILS 100;

typedef struct {
    char *name;
    char *email;
    char phone[MAX_PHONE];
} EMAIL_STRUCT;

void freadEmailArray(FILE* infile,EMAIL_STRUCT*emailPtrArray[MAX_PHONE],int*pnumElems);

int main()
{
    EMAIL_STRUCT*emailPtrArray[MAX_CHARS]=;
    int *pnumElems;
    FILE*infile;
    freadEmailArray(infile,emailPtrArray,pnumElems);

}

void freadEmailArray(FILE* infile,
	EMAIL_STRUCT *emailPtrArray[], int *pnumElems)
{
	int i, j;
	char temp[256], *ps;
	for (i=0; i< MAX_EMAILS && (fgets( temp, MAX_CHARS, infile )!= NULL); ++i ) {
		removeNewLine(temp); // you write
// assign an element to dynamically allocated memory
		emailPtrArray[i]=makeString(temp);
	// check if memory allocates:
		if(emailPtrArray[i]!=NULL){
		ps = strtok(temp,"\t");
		emailPtrArray->name = makeString(ps);
		ps = strtok(NULL,"\t");
		emailPtrArray->email = makeString(ps);
		ps = strtok(NULL,"\t");
		strcpy(emailPtrArray->phone[i],ps);
    }
    }
	*pnumElems = i;
} /* end freadEmailArray */

char *makeString(const char *str)
{
	char *ps;

	ps= (char *)malloc( strlen(str) + 1);
	// DON'T DO:  malloc(strlen(str+1));
	if( ps != NULL ){
		strcpy(ps, str);
	} // end if
	return ps;
} // end makeString

