#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    int l1, l2, c2;
    cin >> l1 >> l2 >> c2;

    
    vector<vector<int>> matriz1(l1, vector<int>(l2)); //MATRIZ L1 X L2 
    
    vector<vector<int>> matriz2(l2, vector<int>(c2)); //MATRIZ L2 X C2
    
    //vector<vector<int>> matrizResultado(l2, vector<int>(c2)); //RESULTADO DA MULTIPLICAÇÃO DE 1 X 2

    for(int i = 0; i < l1; i++) {
        for(int j = 0; j < l2; j++) {
            cin >> matriz1[i][j]; 
        }
    }
    
    for(int i = 0; i < l2; i++) {
        for(int j = 0; j < c2; j++) {
            cin >> matriz2[i][j]; 
        }
    }

    vector<vector<int>> resultado(l1, vector<int>(c2));
    for(int i = 0; i < l1; i++) {
        for(int j = 0; j < c2; j++) {
            for(int k = 0; k < l2; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << resultado[i][j];
            if (j < c2-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
   return 0;
}