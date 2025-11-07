#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato - Posicionamento dos Navios
// Aluno José Ageu Layme Neto

//função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[10][10]){ 
    int i, j;

    //imprimindo as posições das colunas
    printf("|+|");
    for (i=0; i<10; i++){
        printf("\033[4m|%d\033[0m", i);
    }
    printf("|\n");

    //imprimindo o tabuleiro com posições das linhas
    for (i=0; i<10; i++){
        printf("|%d|-", i);
        for (j=0; j<10; j++){
            printf("%d-", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

//função para verificar os parâmetros do navio
void verificarNavio(int navio[4], char nomeDoNavio[], int tabuleiro[10][10]){
    int i, j; 
    int flagSobreposicao = 0;

    printf("CHECKLIST DE VERIFICAÇÃO DOS PARÂMETROS DO %s\n", nomeDoNavio);

    //impressão dos dados do navio
    navio[1] == 0 ?
        printf("Navio tamanho %d, sentido Horizontal, posicionado nas coordenadas L%d-C%d a L%d-C%d\n", navio[0], navio[2], navio[3], navio[2], navio[3]+navio[0]-1) :
        printf("Navio tamanho %d, sentido Vertical, posicionado nas coordenadas L%d-C%d a L%d-C%d\n", navio[0], navio[2], navio[3], navio[2]+navio[0]-1, navio[3]) ;        

    //verificando o tamanho do navio
    printf("Tamanho do navio: "); 
    navio[0] > 10 ? 
        printf("Maior que o limite de 10\n") : 
        printf("Ok\n");

    //verificando estouro dos limites do tabuleiro
    printf("Limites do tabuleiro: ");
    if (navio[1] == 0){
        (navio[0] + navio[3]) > 9 ? 
            printf("Navio posicionado além do limite do tabuleiro\n") :
            printf("Ok\n"); 
    }else{
        if (navio[1] == 1){
            (navio[0] + navio[2]) > 9 ?
                printf("Navio posicionado além do limite do tabuleiro\n") :
                printf("Ok\n"); 
        }
    }

    //verificando se há sobreposição de navios
    printf("Sobreposição de navios: ");
    if (navio[1] == 0){
        for (j=0; j<navio[0]; j++){
            flagSobreposicao += tabuleiro[navio[2]][j+navio[3]] == 3 ? 1 : 0;
        }

    }else{
        for (i=0; i<navio[0]; i++){
            flagSobreposicao += tabuleiro[i+navio[2]][navio[3]] == 3 ? 1 : 0;
        }
    }
    flagSobreposicao == 0 ? printf("Ok\n") : printf("Há navios sobrepostos\n");    

    printf("\n");
}

void posicionarNavio(int tabuleiro[10][10], int navio[4]){
    int i, j;

    if (navio[1] == 0){
        for (j=0; j<navio[0]; j++){
            tabuleiro[navio[2]][j+navio[3]] = 3;
        }
    }else{
        for (i=0; i<navio[0]; i++){
            tabuleiro[i+navio[2]][navio[3]] = 3;
        }
    }    
}

int main(){
    int tabuleiro[10][10]; //Inicialização do tabuleiro
    int i, j;
    int navio1[4], navio2[4];

    //inicializando todas as posições do tabuleiro com 0, representando água
    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //imprimindo o tabuleiro inicial
    printf("TABULEIRO INICIALIZADO\n");
    imprimirTabuleiro(tabuleiro); //chamada da função para imprimir o tabuleiro.
    printf("\n");

    //definindo o navio 1
    navio1[0] = 3; //tamanho do navio
    navio1[1] = 0; //direção do navio: 0 para horizontal e 1 para vertical
    navio1[2] = 1; //linha em que o navio está posicionado
    navio1[3] = 4; //coluna em que o navio está posicionado
    verificarNavio(navio1, "NAVIO 1", tabuleiro); //chamada da função que verifica alguma irregularidade nos parâmatros do navio
    posicionarNavio(tabuleiro, navio1); //chamada da função para posicionar o navio no tabuleiro
    printf("TABULEIRO APÓS POSICIONAR O NAVIO\n");
    imprimirTabuleiro(tabuleiro); //chamada da função para imprimir o tabuleiro após posicionar o navio
    printf("\n");

    //definindo o navio 2
    navio2[0] = 5; //tamanho do navio
    navio2[1] = 1; //direção do navio: 0 para horizontal e 1 para vertical
    navio2[2] = 2; //linha em que o navio está posicionado
    navio2[3] = 9; //coluna em que o navio está posicionado
    verificarNavio(navio2, "NAVIO 2", tabuleiro); //chamada da função que verifica alguma irregularidade nos parâmatros do navio
    posicionarNavio(tabuleiro, navio2); //chamada da função para posicionar o navio no tabuleiro

    //imprimindo o tabuleiro após o posicionamento de todos os navios
    printf("TABULEIRO COM TODOS OS NAVIOS POSICIONADOS\n");
    imprimirTabuleiro(tabuleiro);    
    printf("\n");
}