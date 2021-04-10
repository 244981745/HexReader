#include <stdio.h>

int main(int argc, char **argv)
{
	int i,j;
	FILE *fp,*fpout;
	unsigned char buf[20];
	fp	=	fopen("pcm16k.pcm","rb");
	fpout	=	fopen("1.h","wb");
	
	if(fp==NULL || fpout == NULL)return -1;
	
	fprintf(fpout,"const unsigned char pcm[88200]={\n");

	for(i = 0; i < 88200/16; i++)
	{
		memset((void*)buf,'\0',20);
		if(!feof(fp))
			fread((void*)buf,1,16,fp);
		for(j = 0; j < 16; j++)
		{
			fprintf(fpout,"0x%.2x,",buf[j]);
		}
		fprintf(fpout,"\n");
	}
	
	fprintf(fpout,"\n};\n");
	
	fclose(fp);
	fclose(fpout);
	
	return 0;
}