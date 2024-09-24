#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    // draw matrix
    int mat[300][300];
    int n = 10;
    int matrix_size = n*n;
    double precision_checker;
    double side_temperatures[100][100];
    double malha1[100][100];
    int temp_up = 20, temp_right = 20, temp_left = 25, temp_down = 30;

    double biggest_from_subtraction = 0;
    double biggest_from_current = 0;
    double current_x[1024];
    double last_x[1024];
    double vector_subtracted[1024];

    for(int k = 0; k < n*n; k++){
        current_x[k] = 0;
    }
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< n+1; j++){
            side_temperatures[i][j] = 0;
            malha1[i][j] = 0;
        }
    }
    //put temperatures
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< n+1; j++){
            if(i == 0){
                side_temperatures[i][j]+=temp_up;
            }
            if(i == n-1){
                side_temperatures[i][j]+=temp_down;
            }
            if(j == 0){
                side_temperatures[i][j]+=temp_left;
            }
            if(j == n-1){
                side_temperatures[i][j]+=temp_right;
            }
        }
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            cout << side_temperatures[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------" << endl;
    int k;
    int trys = 0;
    // add values of the sides
    do{
        trys++;
        k = 0;
            for(int i = 0; i< n; i++){
                    for(int j = 0; j< n; j++){
                        last_x[k] = current_x[k];
                        double media = 0;
                        if(i > 0){
                        media+=malha1[i-1][j];
                        }
                        if(i < n-1){
                        media+=malha1[i+1][j];
                        }
                        if(j > 0){
                        media+=malha1[i][j-1];
                        }
                        if(j < n-1){
                        media+=malha1[i][j+1];
                        }
                        media+=side_temperatures[i][j];
                        malha1[i][j] = media/4;
                                
                        current_x[k] = malha1[i][j];
                        k++;
                    }
                }
        k = 0;
            biggest_from_current = 0;
            biggest_from_subtraction = 0;
            while (k < n*n){
                vector_subtracted[k] = current_x[k] - last_x[k];
                if(abs(vector_subtracted[k]) > biggest_from_subtraction){
                    biggest_from_subtraction = abs(vector_subtracted[k]);
                }
                if(abs(current_x[k]) > biggest_from_current){
                    biggest_from_current = current_x[k];
                }
                
                k++;
            }
            /*cout << endl << endl << "Vector subtracted: " << endl;
            for (int i = 0; i < n*n; i++){
                cout << vector_subtracted[i] << endl;
                }
            cout << endl << endl << endl;*/

            cout << biggest_from_subtraction << " " << biggest_from_current << endl << endl;

            for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                cout << malha1[i][j] << " ";
            }
            cout << endl;
        }
        precision_checker = biggest_from_subtraction / biggest_from_current;
        cout << endl << endl << setprecision(20) << "precision: " << precision_checker << endl << endl;
    }while(precision_checker > 0.0000000000000005); // 16 casas decimais após a virgula ele chega
    

    // print temperatures
    
    return 0;
}