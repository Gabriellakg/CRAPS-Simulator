#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

int lancar_dado() {
    int dado1, dado2, soma;
    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;
    soma = dado1 + dado2;

    cout << "\nVoce tirou " << dado1 << " e " << dado2;
    cout << "\nSoma dos pontos: " << soma;
    return soma;
}

int jogo() {
    srand(time(NULL));
    int primeiro_lance = lancar_dado();

    if (primeiro_lance == 7 || primeiro_lance == 11)
        cout << "\nYOU WON!";
    else if (primeiro_lance == 2 || primeiro_lance == 3 || primeiro_lance == 12)
        cout << "\nYOU LOSE!";
    else {
        cout << "\nSeu ponto eh " << primeiro_lance;
        int ponto = primeiro_lance;
        while (true) {
            char op;
            cout << "\nPressione ENTER para lancar os dados novamente...";
            op = getch();
            int resultado = lancar_dado();
            cout << "\nSeu ponto eh " << ponto;
            if (resultado == ponto) {
                cout << "\nYOU WON!";
                break;
            } else if (resultado == 7) {
                cout << "\nYOU LOSE!";
                break;
            }
        }
    }
}



int main() {
    cout << "Simulador de Craps";
    char op;
    do {
        cout << "\nPressione ENTER para jogar...";
        cout << "\nPressione 'Q' para sair";

        op = getch();
        if (op == 'Q' or op == 'q'){
        	break;
		}

        jogo();
    } while (op == 13);

    return 0;
}
