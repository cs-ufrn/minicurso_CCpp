#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

bool checa_num(string str);
void dupla_escolha(void);
char X_ou_O(int jogador_da_vez);
bool altera_matriz_jogo(int escolha_jogador, int vez_jogador, char matriz_jogo[][3]);
int verifica_vencedor(char matriz_jogo[][3]);
void mostra_matriz(char matriz_jogo[][3]);
void vencedor_ou_velha(int vencedor);

int main() {
    int vencedor = 0;
    char matriz_jogo[3][3] = {{'1', '2', '3'},
                              {'4', '5', '6'},
                              {'7', '8', '9'}};

    while(vencedor == 0){
        int vez_jogador = 0;
        int escolha_jogador = 0;
        string aux_str;

        for(int i=1; i < 3; i++){
            vez_jogador = i;

            cout << "=====================================" << endl;
            cout << "  NOTA:                              " << endl;
            cout << "           Jogador 1 = X             " << endl;
            cout << "           Jogador 2 = O             " << endl;
            cout << "=====================================" << endl;

            cout << endl; //pula uma linha

            cout << "Vez do jogador " << vez_jogador << endl;
            cout << "Escolha onde quer jogar: " << endl;

            mostra_matriz(matriz_jogo);

            cin >> aux_str;

            if(checa_num(aux_str)){ //checa se a escolha é um número válido
                stringstream(aux_str) >> escolha_jogador;
            }
            else{
                escolha_jogador = 0;
            }

            if(!altera_matriz_jogo(escolha_jogador, vez_jogador, matriz_jogo)){
                i--;
            };

            vencedor = verifica_vencedor(matriz_jogo);
            if(vencedor != 0){
                break;
            }

        }
    }

    vencedor_ou_velha(vencedor);

    mostra_matriz(matriz_jogo);

    return 0;
}

bool checa_num(string str){
    for (int i = 0; i < str.length(); i++){
        if (isdigit(str[i]) == false){
            return false;
        }
    }
    return true;
}

void dupla_escolha(void){
    cout << "ERRO: O número escolhido já foi escolhido anteriormente por você ou por outro jogador." << endl;
    cout << "Tente novamente." << endl;
    sleep_for(seconds(3));
}

char X_ou_O(int jogador_da_vez){
    if(jogador_da_vez == 1){
        return 'X';
    }
    else{
        return 'O';
    }
}

void mostra_matriz(char matriz_jogo[][3]){

    cout << endl;//pula uma linha

    for(int j=0; j < 3; j++){
        cout << "             " << matriz_jogo[j][0] << " | " << matriz_jogo[j][1] << " | " << matriz_jogo[j][2] << endl;

        if(j != 2){
            cout << "             ----------" << endl;
        }
    }
    cout << endl;//pula uma linha
}

bool altera_matriz_jogo(int escolha_jogador, int vez_jogador, char matriz_jogo[][3]){

            if(escolha_jogador == 1){
                if(matriz_jogo[0][0] != 'X' && matriz_jogo[0][0] != 'O'){

                    matriz_jogo[0][0] = X_ou_O(vez_jogador);

                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }
            }
            else if(escolha_jogador == 2){
                if(matriz_jogo[0][1] != 'X' && matriz_jogo[0][1] != 'O'){

                    matriz_jogo[0][1] = X_ou_O(vez_jogador);

                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }
            }
            else if(escolha_jogador == 3){
                if(matriz_jogo[0][2] != 'X' && matriz_jogo[0][2] != 'O'){

                    matriz_jogo[0][2] = X_ou_O(vez_jogador);

                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }
            }
            else if(escolha_jogador == 4){
                if(matriz_jogo[1][0] != 'X' && matriz_jogo[1][0] != 'O'){

                    matriz_jogo[1][0] = X_ou_O(vez_jogador);
                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }
            }
            else if(escolha_jogador == 5){
                if(matriz_jogo[1][1] != 'X' && matriz_jogo[1][1] != 'O'){

                    matriz_jogo[1][1] = X_ou_O(vez_jogador);

                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }

            }
            else if(escolha_jogador == 6){
                if(matriz_jogo[1][2] != 'X' && matriz_jogo[1][2] != 'O'){

                    matriz_jogo[1][2] = X_ou_O(vez_jogador);

                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }
            }
            else if(escolha_jogador == 7){
                if(matriz_jogo[2][0] != 'X' && matriz_jogo[2][0] != 'O'){

                    matriz_jogo[2][0] = X_ou_O(vez_jogador);

                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }

            }
            else if(escolha_jogador == 8){
                if(matriz_jogo[2][1] != 'X' && matriz_jogo[2][1] != 'O'){

                    matriz_jogo[2][1] = X_ou_O(vez_jogador);

                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }

            }
            else if(escolha_jogador == 9){
                if(matriz_jogo[2][2] != 'X' && matriz_jogo[2][2] != 'O'){

                    matriz_jogo[2][2] = X_ou_O(vez_jogador);

                    return true;
                }
                else{
                    dupla_escolha();
                    return false;
                    }
            }
            else{
                cout << "O valor indicado não é válido, informe outro valor de acordo com os números disponíveis no tabuleiro." << endl;
                sleep_for(seconds(3));

                return false;
            }
}

int verifica_vencedor(char matriz_jogo[][3]){

    //Verifica se existem colunas iguais
    for(int col = 0; col < 3; col++){
        if(matriz_jogo[0][col] == matriz_jogo[1][col] && matriz_jogo[1][col] == matriz_jogo[2][col]){
            if(matriz_jogo[0][col] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
        }
    }

    //Verifica se existem colunas iguais
    for(int lin = 0; lin < 3; lin++){
        if(matriz_jogo[lin][0] == matriz_jogo[lin][1] && matriz_jogo[lin][1] == matriz_jogo[lin][2]){
            if(matriz_jogo[lin][0] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
        }
    }
    //Verifica se a diagonal direita (\) tem elementos iguais
    if(matriz_jogo[0][0] == matriz_jogo[1][1] && matriz_jogo[1][1] == matriz_jogo[2][2]){
        if(matriz_jogo[0][0] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
    }

    //Verifica se a diagonal esquerda (/) tem elementos iguais
    else if(matriz_jogo[0][2] == matriz_jogo[1][1] && matriz_jogo[1][1] == matriz_jogo[2][0]){
        if(matriz_jogo[0][2] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
    }

    else if((matriz_jogo[0][0] == 'X' || matriz_jogo[0][0] == 'O') &&
            (matriz_jogo[0][1] == 'X' || matriz_jogo[0][1] == 'O') &&
            (matriz_jogo[0][2] == 'X' || matriz_jogo[0][2] == 'O') &&
            (matriz_jogo[1][0] == 'X' || matriz_jogo[1][0] == 'O') &&
            (matriz_jogo[1][1] == 'X' || matriz_jogo[1][1] == 'O') &&
            (matriz_jogo[1][2] == 'X' || matriz_jogo[1][2] == 'O') &&
            (matriz_jogo[2][0] == 'X' || matriz_jogo[2][0] == 'O') &&
            (matriz_jogo[2][1] == 'X' || matriz_jogo[2][1] == 'O') &&
            (matriz_jogo[2][2] == 'X' || matriz_jogo[2][2] == 'O')){
                return 3;
            }
    //Se não houver vencedores retorna 0
    else{
        return 0;
    }

}

void vencedor_ou_velha(int vencedor){
    if(vencedor == 3){
        cout << '\n' << endl; //pula duas linhas
        cout << "=====================================" << endl;
        cout << "             Deu velha!              " << endl;
        cout << "=====================================" << endl;
    }
    else{
        cout << '\n' << endl; //pula duas linhas
        cout << "=====================================" << endl;
        cout << "           Jogador " << vencedor << " venceu!  " << endl;
        cout << "=====================================" << endl;
    }
}
