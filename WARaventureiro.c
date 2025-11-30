#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da struct Territorio.
// Esta struct agrupa informações relacionadas a um território: nome, cor do exército e quantidade de tropas.
// É usada para representar entidades em uma simulação de batalha, com acesso via ponteiros para eficiência.
typedef struct {
    char nome[30];    // Nome do território
    char cor[10];     // Cor do exército (representa o dono)
    int tropas;       // Quantidade de tropas
} Territorio;

// Função para cadastrar territórios.
// Recebe um ponteiro para o vetor de territórios e o número de territórios.
// Percorre o vetor e solicita entrada para cada campo, utilizando ponteiros para acesso.
void cadastrarTerritorios(Territorio* mapa, int numTerritorios) {
    for (int i = 0; i < numTerritorios; i++) {
        printf("Cadastro do Território %d:\n", i + 1);
        
        printf("Digite o nome do território: ");
        scanf("%s", (mapa + i)->nome);  // Acesso via ponteiro
        
        printf("Digite a cor do exército: ");
        scanf("%s", (mapa + i)->cor);
        
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &(mapa + i)->tropas);
        
        printf("\n");
    }
}

// Função para exibir territórios.
// Recebe um ponteiro para o vetor e o número de territórios.
// Percorre o vetor e imprime os dados de cada território com formatação clara.
void exibirTerritorios(Territorio* mapa, int numTerritorios) {
    printf("Dados dos Territórios:\n");
    for (int i = 0; i < numTerritorios; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome: %s\n", (mapa + i)->nome);
        printf("  Cor do Exército: %s\n", (mapa + i)->cor);
        printf("  Tropas: %d\n", (mapa + i)->tropas);
        printf("\n");
    }
}

// Função para simular ataque.
// Recebe ponteiros para atacante e defensor.
// Simula dados aleatórios (1-6) para cada lado.
// Se atacante vence (dado maior), defensor muda de cor e recebe metade das tropas do atacante.
// Se perde, atacante perde 1 tropa.
// Atualiza os dados via ponteiros.
void atacar(Territorio* atacante, Territorio* defensor) {
    int dadoAtacante = rand() % 6 + 1;  // Dado de 1 a 6
    int dadoDefensor = rand() % 6 + 1;
    
    printf("Resultado do ataque:\n");
    printf("Atacante (%s) rolou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor (%s) rolou: %d\n", defensor->nome, dadoDefensor);
    
    if (dadoAtacante > dadoDefensor) {
        // Atacante vence: transfere cor e metade das tropas
        strcpy(defensor->cor, atacante->cor);
        int tropasTransferidas = atacante->tropas / 2;
        defensor->tropas = tropasTransferidas;
        atacante->tropas -= tropasTransferidas;
        printf("Atacante venceu! Território conquistado.\n");
    } else {
        // Atacante perde: perde 1 tropa
        atacante->tropas -= 1;
        if (atacante->tropas < 0) atacante->tropas = 0;
        printf("Defensor venceu! Atacante perdeu uma tropa.\n");
    }
}

// Função para liberar memória.
// Recebe o ponteiro para o vetor alocado dinamicamente e libera com free.
// Essencial para evitar vazamentos de memória.
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

int main() {
    srand(time(NULL));  // Inicializa gerador de números aleatórios para dados
    
    int numTerritorios;
    printf("Digite o número de territórios: ");
    scanf("%d", &numTerritorios);
    
    // Alocação dinâmica: usa calloc para inicializar memória com zeros
    Territorio* mapa = (Territorio*)calloc(numTerritorios, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }
    
    // Cadastro e exibição inicial
    cadastrarTerritorios(mapa, numTerritorios);
    exibirTerritorios(mapa, numTerritorios);
    
    // Loop para simulação de ataques
    while (1) {
        printf("Escolha o território atacante (1 a %d) ou 0 para sair: ", numTerritorios);
        int idxAtacante;
        scanf("%d", &idxAtacante);
        if (idxAtacante == 0) break;
        idxAtacante--;  // Ajusta para índice 0-based
        
        printf("Escolha o território defensor (1 a %d): ", numTerritorios);
        int idxDefensor;
        scanf("%d", &idxDefensor);
        idxDefensor--;  // Ajusta para índice 0-based
        
        // Validação: não atacar território da mesma cor
        if (strcmp((mapa + idxAtacante)->cor, (mapa + idxDefensor)->cor) == 0) {
            printf("Erro: Não é possível atacar um território da mesma cor!\n");
            continue;
        }
        
        // Realiza o ataque
        atacar(mapa + idxAtacante, mapa + idxDefensor);
        
        // Exibe dados atualizados
        exibirTerritorios(mapa, numTerritorios);
    }
    
    // Liberação de memória
    liberarMemoria(mapa);
    
    return 0;
}