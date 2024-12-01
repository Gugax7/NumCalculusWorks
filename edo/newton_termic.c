#include <stdio.h>

int main() {
    // Definir parâmetros
    double k = -0.0636;   // Constante de resfriamento
    double T_amb = 30.0;  // Temperatura ambiente
    double T0 = 120.0;    // Temperatura inicial
    double h = 10.0; // Tamanho do passo
    double t_final = 110; // Tempo final
    
    // Calcular o número de passos
    int n = (int)(t_final / h); 
    
    // Arrays para armazenar os tempos e temperaturas
    double t = 10.0;  // Tempo inicial
    double T = T0;   // Temperatura inicial
    
    // Cabeçalho da tabela
    printf("Tempo (horas)\tTemperatura (°C)\n");
    
    // Imprimir o valor inicial
    printf("%.2f\t\t%.2f\n", t, T);
    
    // Método de Euler
    for (int i = 1; i <= n; i++) {
        // Calcular a taxa de variação da temperatura
        double dT_dt = k * (T - T_amb);
        
        // Atualizar a temperatura usando a fórmula de Euler
        T = T + h * dT_dt;
        
        // Atualizar o tempo
        t = t + h;
        
        // Imprimir o valor do tempo e temperatura
        printf("%.2f\t\t%.2f\n", t, T);
    }

    return 0;
}
