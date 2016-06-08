/* 파일 목적 : 선행연구에 있는 voter model에 대한 내용을 직접 코딩함 - 하지만 p에 대한 내용은 아직 미작성 */
/* 작성자 : 박종하 & 최진수 */
/* 작성일 : 2016.06.08 */

#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include <fstream>
using namespace std;

/*파일 출력을 txt파일에 하기 위한 준비*/
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
    
    /* rand을 사용하기 위한 준비 */
    srand(time(NULL));
    
    /* 군대식 모델의 배열값인 o[i][j]에 값을 넣고 개수를 센다 */
    for(i=0; i<l; i++)
    {
        for(j=0; j<pow(3, i); j++)
        {
            o[i][j]=rand()%2;
            total+=(o[i][j]-0.5)*2;
            num++;
        }
    }
    
    /* o[0][0]을 -1로 바꾸고 o[i][j]에 있는 값들의 합을 구한다 */
    total=total-(o[0][0]-0.5)*2 -1;
    o[0][0]=0;
    
    while (t<100)
    {
        k=rand()%(l-1)+1;
        n=pow(3, k);
        m=rand()%n;
        a=m/3;
        
        /* 값의 전환*/
        if(o[k-1][a]) total=total-(o[k][m]-0.5)*2 +1, o[k][m]=o[k-1][a];
        else if (rand()%e1) total=total-(o[k][m]-0.5)*2 -1, o[k][m]=o[k-1][a];
        t++;
        
        /* 단계에서의 평균을 구하고 이를 출력한다 */
        ave=(float)total/num;
	fprintf(fout, "%f\n", ave);
    }
}
