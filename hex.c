#include <stdio.h>

#ifndef	NULL
#define	NULL	(void*)0
#endif

void hex(FILE *fp);

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage:Hex FileName\n");
		return -1;
	}
	
	FILE	*fp;
	fp	=	fopen(argv[1],"rb");
	if(fp == NULL)
	{
		printf("FileName Error.\n");
		return -1;
	}
	
	hex(fp);
	
	return 0;
}

void hex(FILE *fp)
{
	int i,ret=0,line=0;
	unsigned char buff[512];
	
	while(!feof(fp))
	{
		ret = fread((void *)buff,1,512,fp);
		
		for(i = 0; i < 512; i++)
		{
			if(i%16 == 0)printf("%5d\t",line+=16);
			printf(" %C%C",(buff[i]>>4&0xf)>9?(buff[i]>>4&0xf)+55:(buff[i]>>4&0xf)+48, (buff[i]&0xf)>9?(buff[i]&0xf)+55:(buff[i]&0xf)+48 );
			if((i+1) % 16 == 0)
			printf("\n");
		}
	}
	
	return ;
	
}
