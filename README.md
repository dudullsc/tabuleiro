# tabuleiroBatalha Naval Simplificado: Implementação do Posicionamento de Navios em C
1. Resumo
Este documento descreve a implementação de uma funcionalidade central para um jogo de Batalha Naval: o posicionamento de navios em um tabuleiro bidimensional. Desenvolvido em linguagem C, o programa gerencia um tabuleiro de dimensões 10x10, posiciona dois navios de tamanho fixo (um na orientação horizontal e outro na vertical), valida suas posições em relação aos limites do tabuleiro e verifica a ausência de sobreposições entre eles. O objetivo principal deste trabalho é demonstrar o uso prático de arrays (vetores e matrizes) e a aplicação de lógica de programação fundamental em C, atendendo aos requisitos de um desafio de nível iniciante proposto.

2. Introdução
O presente trabalho foi concebido e desenvolvido no contexto de um desafio de programação classificado como "nível novato". O propósito fundamental é a aplicação e consolidação de conhecimentos básicos na linguagem de programação C, com ênfase particular na manipulação de vetores (arrays unidimensionais) e matrizes (arrays bidimensionais). O escopo do desafio compreende a criação da estrutura basilar para um jogo de Batalha Naval, concentrando-se exclusivamente na representação gráfica do tabuleiro e no posicionamento inicial de dois navios – um disposto verticalmente e outro horizontalmente – incluindo as devidas validações de suas posições. Este exercício prático visa reforçar a compreensão teórica através da implementação de uma solução funcional e bem documentada.

3. Metodologia e Implementação
A solução foi metodicamente implementada em conformidade com as diretrizes especificadas no desafio, empregando estruturas de dados e algoritmos simples, porém eficientes e adequados para a complexidade da tarefa proposta.

3.1. Representação do Tabuleiro
O campo de jogo, ou tabuleiro, é modelado como uma matriz bidimensional de inteiros, declarada como int tabuleiro[10][10]. Esta estrutura de 10 linhas por 10 colunas é fundamental para o sistema. Por convenção, as células desta matriz são inicializadas com o valor inteiro 0, que simboliza a condição de "água", ou seja, uma posição desocupada.

3.2. Definição e Posicionamento dos Navios
Para esta fase do desenvolvimento, são considerados dois navios. Cada navio possui um tamanho fixo, ocupando exatamente 3 posições adjacentes no tabuleiro. As coordenadas de origem (canto superior esquerdo da primeira célula do navio) e a orientação de cada navio (horizontal ou vertical) são predefinidas diretamente no código fonte. Uma vez validadas as coordenadas e a ausência de conflitos, as posições ocupadas pelos navios são marcadas na matriz do tabuleiro com o valor inteiro 3.

3.3. Lógica de Validação
Previamente ao posicionamento de qualquer navio na matriz do tabuleiro, um conjunto de verificações é executado para garantir a integridade do estado do jogo:

Validação de Limites: Esta verificação assegura que todas as 3 células que compõem o navio estejam integralmente contidas dentro das dimensões físicas do tabuleiro (isto é, entre as linhas 0-9 e colunas 0-9).
Validação de Sobreposição: Esta lógica previne que um navio seja posicionado de forma a ocupar células que já estejam designadas a outro navio. No contexto deste desafio, esta verificação é simplificada, sendo aplicada ao tentar posicionar o segundo navio, checando conflitos com o primeiro já posicionado.

4. Estrutura do Código Fonte
O código-fonte foi organizado de forma modular, utilizando funções distintas para cada responsabilidade principal, promovendo maior clareza, legibilidade e potencial de reutilização:

void inicializar_tabuleiro(): Função dedicada a percorrer todas as células da matriz tabuleiro e atribuir-lhes o valor AGUA (definido como 0), estabelecendo o estado inicial do campo de jogo.
void exibir_tabuleiro(): Responsável por apresentar o estado corrente do tabuleiro no console. A exibição é formatada para incluir índices de linha e coluna, facilitando a interpretação visual das posições.

bool validar_posicao_limites(int linha, int coluna, int tamanho, bool horizontal): Avalia se um navio, dados seus parâmetros de linha e coluna iniciais, tamanho e orientação, pode ser posicionado sem exceder os limites físicos do tabuleiro. Retorna true se a posição é válida, e false caso contrário.

bool verificar_sobreposicao(int linha, int coluna, int tamanho, bool horizontal): Determina se o posicionamento de um navio nas coordenadas e orientação especificadas resultaria em uma colisão (sobreposição) com um navio preexistente. Retorna true em caso de sobreposição, e false se a posição estiver livre.

void posicionar_navio_no_tabuleiro(int linha, int coluna, int tamanho, bool horizontal): Efetua a marcação do navio na matriz do tabuleiro, alterando o valor das células correspondentes para NAVIO (definido como 3). Esta função é invocada somente após a confirmação da validade da posição.

int main(): Ponto de entrada e função principal do programa. Coordena a sequência de operações: definição dos dados dos navios, chamada das funções de inicialização do tabuleiro, validação das posições, posicionamento dos navios e, finalmente, a exibição do tabuleiro resultante.

Para melhorar a clareza e facilitar futuras modificações, foram definidas constantes simbólicas (TAMANHO_TABULEIRO, TAMANHO_NAVIO, AGUA, NAVIO) que parametrizam aspectos chave do jogo.

5. Instruções para Compilação e Execução
Para compilar e executar o programa, siga os passos abaixo:

Código Fonte: O código fonte deve ser salvo em um arquivo com a extensão .c, por exemplo, batalha_naval_posicionamento.c.

Compilação: Utilize um compilador C padrão (como o GCC) em um ambiente de terminal ou linha de comando. O comando de compilação típico é:

Bash

gcc batalha_naval_posicionamento.c -o batalha_naval
Observação: O programa faz uso do cabeçalho <stdbool.h> para a utilização de tipos de dados booleanos (bool, true, false), que é um recurso padrão da linguagem C a partir da norma C99. Compiladores modernos geralmente suportam este recurso sem necessidade de flags adicionais.

Execução: Após a compilação bem-sucedida, o programa pode ser executado da seguinte forma:

Em sistemas Linux ou macOS: ./batalha_naval
Em sistemas Windows: batalha_naval.exe

6. Exemplo de Saída Esperada
Ao ser executado, o programa apresentará no console mensagens informativas sobre as etapas de inicialização e posicionamento dos navios. Caso as coordenadas predefinidas no código sejam alteradas para valores que resultem em violação dos limites do tabuleiro ou sobreposição, mensagens de erro específicas serão exibidas, e o programa será encerrado.

Com as coordenadas padrão (configuradas para serem válidas e não sobrepostas), a saída final consistirá na representação textual do tabuleiro 10x10. Nesta representação, o caractere 0 indica uma célula de água, enquanto o caractere 3 denota uma célula ocupada por parte de um navio. Um exemplo ilustrativo da aparência do tabuleiro é fornecido abaixo:

Iniciando o jogo Batalha Naval - Posicionamento de Navios (Nível Novato)
---------------------------------------------------------------------
Tabuleiro inicializado com água.

Posicionando Navio 1 (Horizontal)...
Navio 1 (horizontal) posicionado com sucesso em Linha: 2, Coluna: 3.

Posicionando Navio 2 (Vertical)...
Navio 2 (vertical) posicionado com sucesso em Linha: 5, Coluna: 6.

--- Tabuleiro Final do Jogo Batalha Naval ---
   0 1 2 3 4 5 6 7 8 9
  ---------------------
0 |0 0 0 0 0 0 0 0 0 0
1 |0 0 0 0 0 0 0 0 0 0
2 |0 0 0 3 3 3 0 0 0 0
3 |0 0 0 0 0 0 0 0 0 0
4 |0 0 0 0 0 0 0 0 0 0
5 |0 0 0 0 0 0 3 0 0 0
6 |0 0 0 0 0 0 3 0 0 0
7 |0 0 0 0 0 0 3 0 0 0
8 |0 0 0 0 0 0 0 0 0 0
9 |0 0 0 0 0 0 0 0 0 0

Posicionamento de navios concluído com sucesso!
(Nota: A disposição exata dos navios no exemplo acima reflete as coordenadas predefinidas no código (linha_navio1 = 2, coluna_navio1 = 3 para o horizontal; linha_navio2 = 5, coluna_navio2 = 6 para o vertical).)

7. Considerações Finais
O presente projeto atende satisfatoriamente aos requisitos e objetivos propostos para o desafio de programação de nível novato. Demonstra de forma eficaz a aplicação de conceitos fundamentais da linguagem C, como a manipulação de arrays multidimensionais, a estruturação do código em funções e a implementação de lógica condicional para validações, na resolução de um problema prático com escopo definido.

A estrutura do código foi pensada para priorizar a clareza, legibilidade e facilidade de manutenção. As validações implementadas são cruciais para assegurar a integridade do estado do tabuleiro, de acordo com as regras simplificadas estabelecidas. Considera-se que este desenvolvimento constitui uma base sólida, passível de expansão futura para incorporar funcionalidades mais avançadas e compor um jogo de Batalha Naval completo.