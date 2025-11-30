#include <stdio.h>
#include <string.h>

// Definição da struct Territorio.
// Esta struct agrupa informações relacionadas a um território: nome, cor do exército e quantidade de tropas.
// Facilita a organização de dados em um sistema de cadastro simples.
typedef struct {
    char nome[30];    // Nome do território (até 29 caracteres + null terminator)
    char cor[10];     // Cor do exército (até 9 caracteres + null terminator)
    int tropas;       // Quantidade de tropas (valor inteiro)
} Territorio;

int main() {
    // Declaração de um vetor de structs para armazenar até 5 territórios.
    // Usamos um vetor fixo para simplicidade, conforme o requisito de 5 cadastros.
    Territorio territorios[5];
    
    // Laço para cadastrar os 5 territórios.
    // Percorremos o vetor e solicitamos entrada para cada campo, com mensagens orientativas.
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do Território %d:\n", i + 1);
        
        // Entrada do nome: usamos scanf para ler string sem espaços.
        printf("Digite o nome do território: ");
        scanf("%s", territorios[i].nome);
        
        // Entrada da cor: similar ao nome.
        printf("Digite a cor do exército: ");
        scanf("%s", territorios[i].cor);
        
        // Entrada da quantidade de tropas: scanf para inteiro.
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        
        printf("\n");  // Quebra de linha para separar cadastros
    }
    
    // Após o cadastro, exibimos os dados de todos os territórios.
    // Percorremos o vetor novamente e imprimimos os campos com formatação clara.
    printf("Dados dos Territórios Cadastrados:\n");
    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor do Exército: %s\n", territorios[i].cor);
        printf("  Tropas: %d\n", territorios[i].tropas);
        printf("\n");
    }
    
    return 0;
}