#include <stdio.h>
#include <stdlib.h>

unsigned int inverti(unsigned int i)
{
	//easy way
	/*
	 while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    return reversedNumber;
	*/
	
	if(i==0)
		return 0;
		
	int counter=0;
	int k=10;
	
	while(i/k>0)
	{
		k=k*10;
		counter++;
	}
	
	int *p=malloc((counter+1)*sizeof(unsigned int));
	
	
	int j=0;
	while(j<counter+1)
	{
		p[j]=i%10;
		i=i/10;
		j++;
	}
	
	
	int ret=0;
	j=0;
	k=k/10;
	while(j<counter+1)
	{
		ret=ret+(p[j]*k);
		k=k/10;
		j++;
	}
	free(p);
 	return ret;
	
}

int main()
{
	unsigned int k=123;
	
	unsigned int res = inverti(k);
	
	return 0;
}
