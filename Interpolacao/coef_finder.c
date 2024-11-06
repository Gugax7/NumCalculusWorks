#include <stdio.h>
#include <stdlib.h>

void calcula_coeficientes(float *a, int n, float *coeficientes) {
    // Inicializa os coeficientes do polinômio resultante
    coeficientes[0] = 1;  // Coeficiente de x^n, sempre 1
    for (int i = 1; i <= n; i++) {
        coeficientes[i] = 0;
    }

    // Calcula os coeficientes usando a fórmula do produto
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            coeficientes[j + 1] += coeficientes[j] * a[i];
        }
    }
}

int calc_divider(int xi, float *a, int n){
    int result = 1;
    for(int i = 0; i < n; i++){
        result*=xi+a[i];
    }
    return result;
}

int main() {

    // My notes: probably i will have to work with matrix here, i need a matrix to keep each value of lk(xi)
    // but i dont need another to keep the values of x, this i already have. I just need to apply the formula.
    // Lets continue this tomorrow.
    int num_pontos;
    float a[50];
    float l[50][50];
    float coef[50];
    float result[50];
    int n = 0;
    printf("How many points do you want?");
    scanf("%d",&num_pontos);
    int xi[50], yi[50];
    printf("\nDigite os valores dos pontos (x,y):\n");
    for(int i = 0; i < num_pontos; i++){
        printf("\nx%d,y%d:",i,i);
        scanf("%d%d",&xi[i],&yi[i]);
        n++;
    }

    for(int g = 0; g < n; g++){
    // i need here to find first l0
        for (int i = 0, j = 0; i < n; i++) {
            if(i != g){
                a[j] = 0 - xi[i];
                j++;
            }
        }
        calcula_coeficientes(a, n-1, coef);
        for(int i = 0; i < n; i++){
            l[g][i] = coef[i] * yi[g] / calc_divider(xi[g],a,n-1);
        }

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result[i] += l[j][i];
            printf("%f ", l[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++){
        printf("%f ", result[i]);
    }

    return 0;
}