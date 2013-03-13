#include <stdio.h>
#include <math.h>

int get_pointer(char *s)
{
	int i=0;
	while(s[i++])
		if(s[i]=='.')
			return i;
	return -1;
}

double string_to_double(char *n)
{
	double result=(double)atoi(n);
	int pointer=get_pointer(n)+1;
	int i=0,a=1;

	if(!pointer)
		return result;

	while(n[pointer])
	{
		a*=10;
		result+=((double)(n[pointer]-48)/a);
		++pointer;
	}

	return result;
}

void get_log(double *n,double *m,char *n_s,char *m_s)
{
	*n=string_to_double(n_s);
	*m=string_to_double(m_s);
}

int main(int argc,char **argv)
{
	double n,m;

	if(argc==3)
		get_log(&n,&m,argv[1],argv[2]);
	else
	{
		printf("请输入底数:");
		scanf("%lf",&n);
		printf("请输入真数:");
		scanf("%lf",&m);
	}

	printf("以%g为底%g的对数是 %g\n",n,m,log(m)/log(n));

	return 0;
}
