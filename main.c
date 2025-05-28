#include <stdio.h>
#include <stdbool.h>

// --- Constantes Globais ---
#define TAMANHO_TABULEIRO 10 // Tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3    // Tamanho fixo dos navios (3 posições)
#define AGUA 0             // Valor para representar água no tabuleiro
#define NAVIO 3            // Valor para representar parte de um navio no tabuleiro

// Matriz para representar o tabuleiro do jogo
// Esta é uma variável global para facilitar o acesso pelas funções.
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

// --- Protótipos das Funções ---
void inicializar_tabuleiro();
void exibir_tabuleiro();
bool validar_posicao_limites(int linha, int coluna, int tamanho, bool horizontal);
bool verificar_sobreposicao(int linha, int coluna, int tamanho, bool horizontal);
void posicionar_navio_no_tabuleiro(int linha, int coluna, int tamanho, bool horizontal);

// --- Função Principal ---
int main() {
    // Mensagem inicial do programa
    printf("Iniciando o jogo Batalha Naval - Posicionamento de Navios (Nível Novato)\n");
    printf("---------------------------------------------------------------------\n");

    // 1. Inicializa o tabuleiro com água (valor 0)
    inicializar_tabuleiro();
    printf("Tabuleiro inicializado com água.\n");

    // 2. Define as coordenadas e orientação dos navios
    // Estes valores são definidos diretamente no código, conforme o requisito.

    // Navio 1: Será posicionado horizontalmente
    int linha_navio1 = 2;         // Linha inicial escolhida para o navio horizontal
    int coluna_navio1 = 3;        // Coluna inicial escolhida para o navio horizontal
    bool horizontal_navio1 = true; // true para horizontal, false para vertical

    // Navio 2: Será posicionado verticalmente
    int linha_navio2 = 5;          // Linha inicial escolhida para o navio vertical
    int coluna_navio2 = 6;         // Coluna inicial escolhida para o navio vertical
    bool horizontal_navio2 = false; // false indica que o navio é vertical

    /* --- Exemplo de coordenadas para testar validação de sobreposição ---
    // Se quiser testar a validação de sobreposição, descomente estas linhas
    // e comente as coordenadas do navio2 acima.
    // Este navio vertical tentaria se posicionar em (1,4), (2,4), (3,4)
    // O navio horizontal estaria em (2,3), (2,4), (2,5) - haveria sobreposição em (2,4)
    // int linha_navio2 = 1;
    // int coluna_navio2 = 4;
    // bool horizontal_navio2 = false;
    */

    /* --- Exemplo de coordenadas para testar validação de limites ---
    // Se quiser testar a validação de limites, descomente uma destas linhas
    // e comente as coordenadas correspondentes acima.
    // int linha_navio1 = 8; // Tentaria colocar navio horizontal começando em (8,3), saindo do tabuleiro
    // int coluna_navio2 = 9; // Tentaria colocar navio vertical começando em (5,9), saindo do tabuleiro
    */


    // 3. Posiciona o primeiro navio (horizontal)
    printf("\nPosicionando Navio 1 (Horizontal)...\n");
    // Valida se o navio está dentro dos limites do tabuleiro
    if (!validar_posicao_limites(linha_navio1, coluna_navio1, TAMANHO_NAVIO, horizontal_navio1)) {
        printf("Erro Crítico: Navio 1 (horizontal) em (%d, %d) está fora dos limites do tabuleiro.\n", linha_navio1, coluna_navio1);
        printf("Verifique as coordenadas definidas no código.\n");
        return 1; // Termina o programa com código de erro
    }
    // Para o primeiro navio, não precisamos verificar sobreposição, pois o tabuleiro está vazio.
    posicionar_navio_no_tabuleiro(linha_navio1, coluna_navio1, TAMANHO_NAVIO, horizontal_navio1);
    printf("Navio 1 (horizontal) posicionado com sucesso em Linha: %d, Coluna: %d.\n", linha_navio1, coluna_navio1);


    // 4. Posiciona o segundo navio (vertical)
    printf("\nPosicionando Navio 2 (Vertical)...\n");
    // Valida se o navio está dentro dos limites do tabuleiro
    if (!validar_posicao_limites(linha_navio2, coluna_navio2, TAMANHO_NAVIO, horizontal_navio2)) {
        printf("Erro Crítico: Navio 2 (vertical) em (%d, %d) está fora dos limites do tabuleiro.\n", linha_navio2, coluna_navio2);
        printf("Verifique as coordenadas definidas no código.\n");
        return 1; // Termina o programa com código de erro
    }
    // Valida se o navio se sobrepõe a algum navio já posicionado
    if (verificar_sobreposicao(linha_navio2, coluna_navio2, TAMANHO_NAVIO, horizontal_navio2)) {
        printf("Erro Crítico: Navio 2 (vertical) em (%d, %d) sobrepõe um navio existente.\n", linha_navio2, coluna_navio2);
        printf("Verifique as coordenadas definidas no código para evitar sobreposição.\n");
        return 1; // Termina o programa com código de erro
    }
    posicionar_navio_no_tabuleiro(linha_navio2, coluna_navio2, TAMANHO_NAVIO, horizontal_navio2);
    printf("Navio 2 (vertical) posicionado com sucesso em Linha: %d, Coluna: %d.\n", linha_navio2, coluna_navio2);


    // 5. Exibe o tabuleiro final com os navios posicionados
    printf("\n--- Tabuleiro Final do Jogo Batalha Naval ---\n");
    exibir_tabuleiro();

    printf("\nPosicionamento de navios concluído com sucesso!\n");
    return 0; // Termina o programa com sucesso
}

// --- Implementação das Funções ---

/**
 * @brief Inicializa todas as posições do tabuleiro com o valor AGUA (0).
 * Percorre cada célula da matriz 'tabuleiro' e atribui o valor AGUA.
 */
void inicializar_tabuleiro() {
    // Loop para percorrer todas as linhas do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Loop para percorrer todas as colunas da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // Define a posição como AGUA
        }
    }
}

/**
 * @brief Exibe o tabuleiro no console de forma organizada.
 * Mostra '0' para água e '3' para partes de navios.
 * Inclui índices de linha e coluna para facilitar a visualização.
 */
void exibir_tabuleiro() {
    // Imprime os índices das colunas para referência
    printf("   "); // Espaço inicial para alinhar com os índices das linhas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Imprime o índice da coluna
    }
    printf("\n");

    // Imprime uma linha separadora para clareza
    printf("  +-");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("--");
    }
    printf("\n");

    // Loop para percorrer todas as linhas do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i); // Imprime o índice da linha e uma barra separadora
        // Loop para percorrer todas as colunas da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da célula (0 ou 3)
        }
        printf("\n"); // Nova linha ao final de cada linha do tabuleiro
    }
}

/**
 * @brief Valida se um navio, com base em sua posição inicial, tamanho e orientação,
 * está completamente dentro dos limites do tabuleiro.
 * @param linha Linha inicial (canto superior/esquerdo) do navio.
 * @param coluna Coluna inicial (canto superior/esquerdo) do navio.
 * @param tamanho Número de posições que o navio ocupa (ex: 3).
 * @param horizontal `true` se o navio for posicionado horizontalmente, `false` se verticalmente.
 * @return `true` se a posição for válida (dentro dos limites), `false` caso contrário.
 */
bool validar_posicao_limites(int linha, int coluna, int tamanho, bool horizontal) {
    // Validação básica: a posição inicial deve estar dentro do tabuleiro
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        //printf("Debug Validação Limites: Posição inicial (%d,%d) fora do tabuleiro.\n", linha, coluna);
        return false; // Posição inicial já está fora
    }

    if (horizontal) {
        // Para navio horizontal, verifica se a última parte do navio (coluna + tamanho - 1)
        // não excede a largura do tabuleiro (TAMANHO_TABULEIRO - 1).
        // Ou, de forma equivalente, se (coluna + tamanho) não excede TAMANHO_TABULEIRO.
        if ((coluna + tamanho) > TAMANHO_TABULEIRO) {
            //printf("Debug Validação Limites: Navio horizontal em (%d,%d) com tamanho %d excede limites.\n", linha, coluna, tamanho);
            return false; // Excede o limite da direita
        }
    } else {
        // Para navio vertical, verifica se a última parte do navio (linha + tamanho - 1)
        // não excede a altura do tabuleiro (TAMANHO_TABULEIRO - 1).
        // Ou, de forma equivalente, se (linha + tamanho) não excede TAMANHO_TABULEIRO.
        if ((linha + tamanho) > TAMANHO_TABULEIRO) {
            //printf("Debug Validação Limites: Navio vertical em (%d,%d) com tamanho %d excede limites.\n", linha, coluna, tamanho);
            return false; // Excede o limite inferior
        }
    }
    return true; // Posição é válida dentro dos limites
}

/**
 * @brief Verifica se o posicionamento de um novo navio nas coordenadas e orientação
 * especificadas resultaria em sobreposição com um navio já existente no tabuleiro.
 * @param linha Linha inicial do novo navio.
 * @param coluna Coluna inicial do novo navio.
 * @param tamanho Número de posições que o novo navio ocupa.
 * @param horizontal `true` se o novo navio for horizontal, `false` se for vertical.
 * @return `true` se houver sobreposição, `false` caso contrário.
 */
bool verificar_sobreposicao(int linha, int coluna, int tamanho, bool horizontal) {
    // Percorre todas as posições que o novo navio ocuparia
    for (int i = 0; i < tamanho; i++) {
        if (horizontal) {
            // Posição atual da parte do navio horizontal: (linha, coluna + i)
            if (tabuleiro[linha][coluna + i] == NAVIO) {
                //printf("Debug Sobreposição: Detectada em (%d,%d) para navio horizontal.\n", linha, coluna + i);
                return true; // Sobreposição encontrada! Célula já ocupada por NAVIO.
            }
        } else {
            // Posição atual da parte do navio vertical: (linha + i, coluna)
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                //printf("Debug Sobreposição: Detectada em (%d,%d) para navio vertical.\n", linha + i, coluna);
                return true; // Sobreposição encontrada! Célula já ocupada por NAVIO.
            }
        }
    }
    return false; // Nenhuma sobreposição encontrada
}

/**
 * @brief Posiciona um navio no tabuleiro, marcando suas posições com o valor NAVIO (3).
 * Esta função assume que a posição já foi validada quanto a limites e sobreposição.
 * A ideia de "copiar o valor 3 de cada posição do vetor do navio" é implementada
 * marcando diretamente as células do tabuleiro com o valor NAVIO (3) pelo TAMANHO_NAVIO.
 * @param linha Linha inicial do navio.
 * @param coluna Coluna inicial do navio.
 * @param tamanho Número de posições que o navio ocupa.
 * @param horizontal `true` se o navio for horizontal, `false` se for vertical.
 */
void posicionar_navio_no_tabuleiro(int linha, int coluna, int tamanho, bool horizontal) {
    // Loop para marcar cada parte do navio
    for (int i = 0; i < tamanho; i++) {
        if (horizontal) {
            // Para navio horizontal, a linha permanece a mesma e a coluna incrementa
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            // Para navio vertical, a coluna permanece a mesma e a linha incrementa
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}