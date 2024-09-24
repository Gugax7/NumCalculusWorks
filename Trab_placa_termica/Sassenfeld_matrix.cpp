#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){

    int linear_system[200][200];
    int n = 5;
    int matrix_size = n*n;

    // clean matrix
   
    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            linear_system[i][j] = 0;
            
            if(i == j- 1 || j == i -1){
                linear_system[i][j] = -1;
            }
            if(i == j){
                linear_system[i][j] = 4;
               
            }
            
        }
    }

    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
             if((i + 1) % n == 0 && i == j){
                    linear_system[i+1][j] = 0;
                    linear_system[i][j+1] = 0;
                }
            
        }
    }

    for(int i = 0; i < matrix_size; i++){
        linear_system[i][i-n] = -1;
        linear_system[i-n][i] = -1;
    }

    // write matrix
    for(int i = 0; i < matrix_size; i++){
        for(int j = 0; j < matrix_size; j++){
            if(linear_system[i][j] < 0){
                cout << " " << linear_system[i][j];
            }
            else{
            cout << "  " << linear_system[i][j];
            }
        }
        cout << endl;
    }

    


    return 0;
}