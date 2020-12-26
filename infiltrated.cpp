#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

using namespace std;

bool Jogar(int Dificuldade);

int main(){
    setlocale(LC_ALL, "Portuguese"); 
    int Dif = 1;
    int DifMax = 10;

    while(Dif <= DifMax){
        srand(time(NULL));
        bool levelCompleto = Jogar(Dif);
        system("CLS");    
        if(levelCompleto){
            ++Dif;
        }
    }
    return 0; 
};

bool Jogar(int Dificuldade){
    cout << "You are a KGB russian agent infiltrated in a north-american government HQ." << endl;
    cout << "Your mission is to discover this " << Dificuldade << " level safe code. " << "Hints: " << endl;

    int A = rand() % Dificuldade + Dificuldade;
    int B = rand() % Dificuldade + Dificuldade;
    int C = rand() % Dificuldade + Dificuldade;

    int Soma = A + B + C;
    int Produto = A * B * C;

    cout << "The password has 3 digits." << endl;
    cout << "The sum between them is equal to " << Soma << endl;
    cout << "The product is: " << Produto << endl;

    int ChuteA = 0;
    int ChuteB = 0; 
    int ChuteC = 0;
    cin >> ChuteA;
    cin >> ChuteB;
    cin >> ChuteC;

    int NovaSoma = ChuteA + ChuteB + ChuteC;
    int NovoProduto = ChuteA * ChuteB * ChuteC;

    if(NovaSoma == Soma && Produto == NovoProduto){
        cout << "Nice! You've made it!" << endl;
        return true;
    } else {
        cout << "Crap! You've missed the combination and the alarm ringed... Run!" << endl;
        return false;
    }
}
