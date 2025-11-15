#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Mestre - Habilidades especiais e áreas de efeito
// Aluno José Ageu Layme Neto

#include <stdio.h>
#include <stdlib.h>

/* Definição dos vetores NAVIO:
    navio[0]: tamanho do navio
    navio[1]: direção do navio: 0-horizontal; 1-vertical; 2-diagonal subindo; 3-diagonal descendo
    navio[2]: linha em que o navio está posicionado
    navio[3]: coluna em que o navio está posicionado
*/

// Declaração de constantes
// Tamanho do tabuleiro
#define LINHAS 10
#define COLUNAS 10

//função para imprimir o tabuleiro. recebe como parâmetro uma matriz
void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]){ 
    //imprimindo as posições das colunas
    printf("| |");
    for (int i = 0; i < COLUNAS; i++){
        printf("\033[4m|%d\033[0m", i);
    }
    printf("|\n");

    //imprimindo o tabuleiro com posições das linhas
    for (int i = 0; i < LINHAS; i++){
        printf("|%d| ", i);
        for (int j = 0; j < COLUNAS; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

//função para verificar os parâmetros do navio
void verificarNavio(int navio[4], char nomeDoNavio[], int tabuleiro[LINHAS][COLUNAS]){
    int flagSobreposicao = 0;
    int flagEstouroTabuleiro = 0;
    int tamanhoDoNavio = navio[0];
    int sentidoDoNavio = navio[1];
    int linhaDoNavio = navio[2];
    int colunaDoNavio = navio[3];

    printf("CHECKLIST DE VERIFICAÇÃO DOS PARÂMETROS DO %s\n", nomeDoNavio);

    switch (sentidoDoNavio) {
    case 0: //navio na horizontal
        //impressão dos dados do navio
        printf("Navio tamanho %d, sentido Horizontal, posicionado nas coordenadas L%d-C%d a L%d-C%d\n", tamanhoDoNavio, linhaDoNavio, colunaDoNavio, linhaDoNavio, colunaDoNavio+tamanhoDoNavio-1);

        //verificando estouro dos limites do tabuleiro
        if (linhaDoNavio > (LINHAS-1) || (colunaDoNavio + tamanhoDoNavio) > (COLUNAS-1)) {
            flagEstouroTabuleiro = 1;
        }

        //verificando se há sobreposição de navios
        while (tamanhoDoNavio > 0) {
            flagSobreposicao += tabuleiro[linhaDoNavio][colunaDoNavio] == 3 ? 1 : 0;
            colunaDoNavio++;
            tamanhoDoNavio--;
        }
        break;

    case 1: //navio na vertical descendente
        printf("Navio tamanho %d, sentido Vertical, posicionado nas coordenadas L%d-C%d a L%d-C%d\n", tamanhoDoNavio, linhaDoNavio, colunaDoNavio, linhaDoNavio+tamanhoDoNavio-1, colunaDoNavio);

        if ((linhaDoNavio + tamanhoDoNavio) > (LINHAS-1) || colunaDoNavio > (COLUNAS-1)) {
            flagEstouroTabuleiro = 1;
        }
    
        while (tamanhoDoNavio > 0) {
            flagSobreposicao += tabuleiro[linhaDoNavio][colunaDoNavio] == 3 ? 1 : 0;
            linhaDoNavio++;
            tamanhoDoNavio--;
        }
        break;

    case 2: //navio na diagonal ascendente
        printf("Navio tamanho %d, sentido Diagonal Ascendente, posicionado nas coordenadas L%d-C%d a L%d-C%d\n", tamanhoDoNavio, linhaDoNavio, colunaDoNavio, linhaDoNavio-tamanhoDoNavio+1, colunaDoNavio+tamanhoDoNavio-1);

        if ((linhaDoNavio - tamanhoDoNavio) < 0 || (colunaDoNavio + tamanhoDoNavio) > (COLUNAS-1)) {
           flagEstouroTabuleiro = 1;
        }

        while (tamanhoDoNavio > 0) {
            flagSobreposicao += tabuleiro[linhaDoNavio][colunaDoNavio] == 3 ? 1 : 0;
            linhaDoNavio--;
            colunaDoNavio++;
            tamanhoDoNavio--;
        }
        break;

    case 3: //navio na diagonal descendente
        printf("Navio tamanho %d, sentido Diagonal Descendente, posicionado nas coordenadas L%d-C%d a L%d-C%d\n", tamanhoDoNavio, linhaDoNavio, colunaDoNavio, linhaDoNavio+tamanhoDoNavio-1, colunaDoNavio+tamanhoDoNavio-1);

        if ((linhaDoNavio + tamanhoDoNavio) > (LINHAS-1) || (colunaDoNavio + tamanhoDoNavio) > (COLUNAS-1)) {
            flagEstouroTabuleiro = 1;
        }

        while (tamanhoDoNavio > 0) {
            flagSobreposicao += tabuleiro[linhaDoNavio][colunaDoNavio] == 3 ? 1 : 0;
            linhaDoNavio++;
            colunaDoNavio++;
            tamanhoDoNavio--;
        }
        break;
    
    default:
        break;
    }

    //verificando o tamanho do navio e imprimindo os resultados das verificações
    printf("Tamanho do navio: "); 
    navio[0] > LINHAS ? 
        printf("Maior que o limite de %d\n", LINHAS) : 
        printf("Ok\n");

    printf("Limites do tabuleiro: ");
    flagEstouroTabuleiro == 0 ?
        printf("Ok\n") :
        printf("Navio posicionado além do limite do tabuleiro\n");

    printf("Sobreposição de navios: ");
    flagSobreposicao == 0 ? 
        printf("Ok\n") : 
        printf("Há navios sobrepostos\n");    

    printf("\n");
}

void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int navio[4]){
    switch (navio[1]) {
    case 0:
        while (navio[0] > 0) {
            tabuleiro[navio[2]][navio[3]] = 3;
            navio[3]++;
            navio[0]--;
        }
        break;
    case 1:
        while (navio[0] > 0) {
            tabuleiro[navio[2]][navio[3]] = 3;
            navio[2]++;
            navio[0]--;
        }
        break;
    case 2:
        while (navio[0] > 0) {
            tabuleiro[navio[2]][navio[3]] = 3;
            navio[2]--;
            navio[3]++;
            navio[0]--;
        }
        break;
    case 3:
        while (navio[0] > 0) {
            tabuleiro[navio[2]][navio[3]] = 3;
            navio[2]++;
            navio[3]++;
            navio[0]--;
        }
        break;    
    default:
        break;
    }
}

// Matrizes de habilidades
void aplicarHabilidade(int opcao, int linha, int coluna, int matrizHabilidade[LINHAS][COLUNAS]){
    /* Parâmetros: 
        Opção da habilidade: 1: Cone / 2: Cruz / 3: Octaedro
        Linha e Coluna: coordenadas do topo do cone ou centro da cruz e octaedro
        Matriz: matriz onde será aplicada a habilidade
    */

    int i, j; // Variáveis de iteração para linhas (i) e colunas (j)

    switch (opcao){
    case 1: //habilidade Cone
        int largura; // Variável para calcular a largura da base (número de colunas a preencher)
        int altura = 4;

        // --- Estrutura de Repetição para Formar o Cone ---
        for (i = linha; i < linha + altura; i++) {
            largura = 1 + 2 * (i - linha);

            // Determina a coluna inicial (j_inicio) para a largura calculada
            int j_inicio = coluna - (largura - 1) / 2;

            // Determina a coluna final (j_fim)
            int j_fim = coluna + (largura - 1) / 2;
        
            // --- Estrutura de Repetição Aninhada para Preencher a Linha ---
            for (j = j_inicio; j <= j_fim; j++) {
                // Verifica se a coluna está dentro dos limites da matriz (0 a 9)
                if (j >= 0 && j < COLUNAS) {
                    matrizHabilidade[i][j] = 1;
                }
            }
        }
        break;

    case 2: //habilidade Cruz
    int dist_vertical, dist_horizontal;
    #define RAIO_CRUZ 2   // Unidades máximas de distância a partir do centro

    // Estrutura de Repetição para Formar a Cruz Ortogonal ('+')
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            
            dist_vertical = abs(i - linha);
            dist_horizontal = abs(j - coluna);
            
            /* Um ponto (i, j) pertence à cruz ortogonal se:
                Ele está EXATAMENTE na linha central (dist_vertical == 0) E dentro da extensão (dist_horizontal <= RAIO_CRUZ)
                OU
                Ele está EXATAMENTE na coluna central (dist_horizontal == 0) E dentro da extensão (dist_vertical <= RAIO_CRUZ)
            */
            if ((dist_vertical == 0 && dist_horizontal <= RAIO_CRUZ) || // Ramo horizontal
                (dist_horizontal == 0 && dist_vertical <= RAIO_CRUZ)) { // Ramo vertical
                    matrizHabilidade[i][j] = 1;
            }
        }
    }
        break;

    case 3: //habilidade Octaedro
        int distancia; // Armazena a distância
        #define RAIO_OCTAEDRO 2 // O raio do octaedro

        // Estrutura de Repetição para Formar o Losango
        for (i = 0; i < LINHAS; i++) {
            for (j = 0; j < COLUNAS; j++) {
            
                // Calcular a distância vertical (|i - linha_do_centro_do_octaedro|)
                int dist_vertical = abs(i - linha);
            
                // Calcular a distância horizontal (|j - coluna_do_centro_do_octaedro|)
                int dist_horizontal = abs(j - coluna);
            
                // A Distância de Manhattan é a soma das distâncias vertical e horizontal.
                distancia = dist_vertical + dist_horizontal;

                // Se a distância for menor ou igual ao RAIO, 
                //    o ponto faz parte do losango e deve ser 1.
                if (distancia <= RAIO_OCTAEDRO) {
                    matrizHabilidade[i][j] = 1;
                }
            }
        }
        break;
    
    default:
        break;
    }
}

int main(){
    int tabuleiro[LINHAS][COLUNAS] = {0}; //Inicialização do tabuleiro como 0
    int navio1[4], navio2[4], navio3[4], navio4[4]; //inicializando os navios

    //imprimindo o tabuleiro inicial
    printf("TABULEIRO INICIALIZADO\n");
    imprimirTabuleiro(tabuleiro); //chamada da função para imprimir o tabuleiro.
    printf("\n");

    //definindo o navio 1
    navio1[0] = 3; //tamanho do navio
    navio1[1] = 0; //direção do navio: 0-horizontal; 1-vertical; 2-diagonal subindo; 3-diagonal descendo
    navio1[2] = 3; //linha em que o navio está posicionado
    navio1[3] = 4; //coluna em que o navio está posicionado
    verificarNavio(navio1, "NAVIO 1", tabuleiro); //chamada da função que verifica alguma irregularidade nos parâmatros do navio
    posicionarNavio(tabuleiro, navio1); //chamada da função para posicionar o navio no tabuleiro
    printf("TABULEIRO APÓS POSICIONAR O NAVIO\n");
    imprimirTabuleiro(tabuleiro); //chamada da função para imprimir o tabuleiro após posicionar o navio
    printf("\n");

    //definindo o navio 2
    navio2[0] = 3; //tamanho do navio
    navio2[1] = 1; //direção do navio: 0-horizontal; 1-vertical; 2-diagonal subindo; 3-diagonal descendo
    navio2[2] = 2; //linha em que o navio está posicionado
    navio2[3] = 9; //coluna em que o navio está posicionado
    verificarNavio(navio2, "NAVIO 2", tabuleiro); //chamada da função que verifica alguma irregularidade nos parâmatros do navio
    posicionarNavio(tabuleiro, navio2); //chamada da função para posicionar o navio no tabuleiro
    printf("TABULEIRO APÓS POSICIONAR O NAVIO\n");
    imprimirTabuleiro(tabuleiro); //chamada da função para imprimir o tabuleiro após posicionar o navio
    printf("\n");

    //definindo o navio 3
    navio3[0] = 3; //tamanho do navio
    navio3[1] = 2; //direção do navio: 0-horizontal; 1-vertical; 2-diagonal subindo; 3-diagonal descendo
    navio3[2] = 5; //linha em que o navio está posicionado
    navio3[3] = 0; //coluna em que o navio está posicionado
    verificarNavio(navio3, "NAVIO 3", tabuleiro); //chamada da função que verifica alguma irregularidade nos parâmatros do navio
    posicionarNavio(tabuleiro, navio3); //chamada da função para posicionar o navio no tabuleiro
    printf("TABULEIRO APÓS POSICIONAR O NAVIO\n");
    imprimirTabuleiro(tabuleiro); //chamada da função para imprimir o tabuleiro após posicionar o navio
    printf("\n");

    //definindo o navio 4
    navio4[0] = 3; //tamanho do navio
    navio4[1] = 3; //direção do navio: 0-horizontal; 1-vertical; 2-diagonal subindo; 3-diagonal descendo
    navio4[2] = 5; //linha em que o navio está posicionado
    navio4[3] = 6; //coluna em que o navio está posicionado
    verificarNavio(navio4, "NAVIO 4", tabuleiro); //chamada da função que verifica alguma irregularidade nos parâmatros do navio
    posicionarNavio(tabuleiro, navio4); //chamada da função para posicionar o navio no tabuleiro

    //imprimindo o tabuleiro após o posicionamento de todos os navios
    printf("TABULEIRO COM TODOS OS NAVIOS POSICIONADOS\n");
    imprimirTabuleiro(tabuleiro);    
    printf("\n");

    //chamada da função para aplicar habilidades ao tabuleiro
        /* Parâmetros: 
            Opção da habilidade: 1: Cone / 2: Cruz / 3: Octaedro
            Linha e Coluna: coordenadas do topo do cone ou centro da cruz/octaedro
            Matriz: matriz onde será aplicada a habilidade
        */
    aplicarHabilidade(2, 4, 4, tabuleiro); //tipo: cone, topo: lin.7 col.4

    //imprimindo o tabuleiro após aplicação da habilidade
    printf("TABULEIRO APÓS USO DA HABILIDADE\n");
    imprimirTabuleiro(tabuleiro);
}