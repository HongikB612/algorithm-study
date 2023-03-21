#include <stdio.h>

void fibonacci(int n);

int main()
{
    int t;
    scanf("%d", &t);

    for(int i=0; i< t; i++)
    {
        int n;
        scanf("%d", &n);

        fibonacci(n);
    }
}
    void fibonacci(int n){
        if(n==0)
        printf("%d %d\n", 1, 0);
        else {
            int fib[n+1][2];
            fib[0][0]=1;
            fib[0][1] = 0;
            fib[1][0] = 0;
            fib[1][1] = 1;
            for(int i=2; i<n+1;i++){
                fib[i][0]= fib[i-1][0]+fib[i-2][0];
                fib[i][1] = fib[i-1][1] + fib[i-2][1];
            }

            printf("%d %d\n", fib[n][0], fib[n][1]);
        }
    
}
