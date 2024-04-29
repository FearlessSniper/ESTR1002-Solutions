#include <stdio.h>
#include <math.h>

int main() {
    int N, M;
    scanf("%d", &N);
    int e, a, b, L, K, P, d, sum=0;
    // Tries to take away as many 2s as possible;
    M=e;
    for(e=N;e%2==0;e=e/2)
    {
        sum=sum+2;
        M=e/2; // M is carried forward before divided by 2
    }
    L=M;
    for(a=M;a%3==0;a=a/3)
    {
        sum=sum+3;
        L=a/3;
    }
    K=L;
    for(b=5;b<=sqrt(N);b=b+6)
    {
      if(L%b==0)
      {
        for(L;L%b==0;L=L/b)
        {
           sum=sum+b;
           K=L/b;
        }
      }
    }
    P=K;
    for(d=7;d<=sqrt(N);d=d+6)
    {
      if(K%d==0)
        {
        for(K;K%d==0;K=K/d)
        {
            sum=sum+d;
            P=K/d;
        }
        }
    }
    if (P != 1) sum += P;
    printf("%d", sum);
}