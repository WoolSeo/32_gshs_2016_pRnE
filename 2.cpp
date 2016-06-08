#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include <fstream>
using namespace std;

FILE *fout = fopen("8-out100.txt", "w");

int main()
{
    int p, l, t=0, k, m, a, e1, total=0;
    long long int i, j, n=1, num=0;
    int o[100][100];
    float e, ave;
    
    e=0.1;
    e1=10;
    l=8;
    
    srand(time(NULL));
    
    for(i=0; i<l; i++)
    {
        for(j=0; j<pow(3, i); j++)
        {
            o[i][j]=rand()%2;
            total+=(o[i][j]-0.5)*2;
        	num++;
        }
    }
    total=total-(o[0][0]-0.5)*2 -1;
    o[0][0]=0;
	while (t<100)
    {
        k=rand()%(l-1)+1;
        n=pow(3, k);
        m=rand()%n;
        a=m/3;
        if(o[k-1][a]) total=total-(o[k][m]-0.5)*2 +1, o[k][m]=o[k-1][a];
        else if (rand()%e1) total=total-(o[k][m]-0.5)*2 -1, o[k][m]=o[k-1][a];
        t++;
        ave=(float)total/num;
		fprintf(fout, "%f\n", ave);
    }
}
