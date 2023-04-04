#include <algorithm>
#include <stdio.h>
using namespace std;

int opt[101][101];
int K[101][101];
int d[101];
int countnum = 0;

void multiplication(int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    multiplication(i, K[i][j]);
    multiplication(K[i][j] + 1, j);
    printf(")");
}

int main(int argc, char *argv[]) {

    int n;
    scanf("%d", &n);
    
    for (int i = 0; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    
    for (int a = 1; a < n; a++) {
        for (int i = 1; i <= n - a; i++) {
            int j = i + a;
            
            opt[i][j] = 99999999;
            for (int k = i; k < j; k++) {
                
                countnum++;
                int save = opt[i][k] + opt[k + 1][j] + d[i - 1] * d[k] * d[j];
                
                if (save < opt[i][j]) {
                    K[i][j] = k;
                    opt[i][j] = save;
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("table of opt[i,j] \n");

    for (int i = 1; i <= n; i++) {
        for (int l = 1; l < i; l++) {
            printf("\t"); 
        }
        for (int j = i; j <= n; j++) {
            printf("%d\t", opt[i][j]);
        }
        printf("\n");
    }

    printf("table of k[i,j] \n");

    for (int i = 1; i <= n; i++) {
        for (int l = 1; l < i; l++) {
            printf("\t"); 
        }
        for (int j = i; j <= n; j++) {
            printf("%d\t", K[i][j]);
        }
        printf("\n");
    }

    printf("optimal chained matrix multiplication\n");
    multiplication(1, K[1][n]);
    multiplication(K[1][n] + 1, n);

    printf("%d", countnum);
}