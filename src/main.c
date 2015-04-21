#include <stdio.h>
#include <gmp.h>
#include <string.h>
#define BUFFER_SIZE 1048576
#define BUFFER_SIZE_IND 1048575
void populateBuffer(unsigned char buffer[BUFFER_SIZE])
{
	unsigned long int count = 0;
	buffer[0] = '\0';
	buffer[1] = '1';
	for(count = 2; count < BUFFER_SIZE_IND-1;count+=2)
	{
		buffer[count] = '\0';
		buffer[count+1] = '1';
	}
}
void fill(char fileName[],mpz_t size)
{
	FILE * filler;
	
	unsigned char buffer[BUFFER_SIZE];
	unsigned long int offset = BUFFER_SIZE;

	populateBuffer(buffer);

	mpz_t counter;
	mpz_t difference;

	mpz_init(counter);
	mpz_init(difference);

	mpz_set_ui(counter,0);
	mpz_set_ui(difference,0);

	if((filler = fopen(fileName,"wb")) == NULL)
	{
		puts("Error opening file to create!");
	}
	else
	{
		do
		{
			mpz_sub(difference,size,counter);
			if(mpz_cmp_ui(difference,BUFFER_SIZE) < 0)
			{
				offset = mpz_get_ui(difference);
			}
			if((fwrite(buffer,sizeof(unsigned char),offset,filler)) != offset)
			{
				puts("Error!");
				break;
			}
			mpz_add_ui(counter,counter,offset);	
		}while(mpz_cmp(counter,size) < 0);
	}
}
int main()
{
	mpz_t size;
	char fileName[30];
	memset(fileName,'\0',29);
	mpz_init(size);
	mpz_set_ui(size,0);

	puts("Please enter the name of the file you want to create.");
	fgets(fileName,29,stdin);
	fileName[strlen(fileName)-1] = '\0';
	puts(fileName);

	puts("Please enter the size of the file in bytes.");
	while(!mpz_inp_str(size,stdin,10))
	{
		puts("Error occurred! Please retry!");
		mpz_set_ui(size,0);
	}
	fill(fileName,size);

	mpz_clear(size);
	return 0;	
}
