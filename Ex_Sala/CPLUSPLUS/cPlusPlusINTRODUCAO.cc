#include <iostream>

using namespace std;

void imprimirmatriz(int *matriz, int l, int c, int contador){
    if (l*c == contador){return;}
    cout << matriz[contador] << " ";
    if ((contador + 1 )% c == 0){
        cout << endl;
    }
    return imprimirmatriz(matriz,l,c,contador+1);
}

void lermatriz(int *matriz, int l, int c, int contador){
    if (contador == l*c){return;}
    int val;
    cin >> val;
    matriz[contador] = val;
    return lermatriz(matriz,l,c,contador+1);
}

void somarMatriz(int *matriz1, int *matriz2, int l, int c, int contador){
    if(l*c == contador){return;}
    cout << matriz1[contador] + matriz2[contador] << " ";
    if ((contador + 1 ) % c == 0){cout <<endl;}
    return somarMatriz(matriz1,matriz2,l,c,contador+1);
}

int main(){
    // Tem como fazer com ponteiro de ponteiros;
    int *matriz1, *matriz2;
    int n,m;
    cin >> n >> m;
    
    matriz1 = new int[n*m];
    matriz2 = new int[n*m];

    lermatriz(matriz1,n,m,0);
    lermatriz(matriz2,n,m,0);

    imprimirmatriz(matriz1,n,m,0);
    cout << endl;
    imprimirmatriz(matriz2,n,m,0);
    cout << endl;
    somarMatriz(matriz1,matriz2,n,m,0);

    delete(matriz1);
    delete(matriz2);

}