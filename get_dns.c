#include <stdio.h>
#include <string.h>

void seek_pos(FILE *fp)
{
	char buf[80];

	while(!feof(fp))
	{
		memset(buf,0,sizeof(buf));
		fscanf(fp,"%s",buf);
		if(strcmp(buf,"#twitter")==0)
			break;
	}
}

int main(int argc,char **argv)
{
	char buf[80];
	char route[100];
	FILE *in,*out;

	if(((in=fopen("/etc/hosts","rb"))==NULL) || argc!=2)
		return -1;

	seek_pos(in);

	while(!feof(in))
	{
		memset(buf,0,sizeof(buf));
		fscanf(in,"%s",buf);
		if(buf[0]>='1' && buf[0]<='9')
		{
			memset(route,0,sizeof(route));
			sprintf(route,"route add -host %s gw %s",buf,argv[1]);
			puts(route);
			system(route);
		}
	}

	fclose(in);
	return 0;
}
