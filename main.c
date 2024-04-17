#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[20];
};

void adicionarUsuario(struct Usuario **lista, int *numUsuarios) {
    *lista = realloc(*lista, (*numUsuarios + 1) * sizeof(struct Usuario));
    if (*lista == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite o nome do usuario: ");
    scanf("%s", (*lista)[*numUsuarios].nome);

    printf("Digite o sobrenome do usuario: ");
    scanf("%s", (*lista)[*numUsuarios].sobrenome);

    printf("Digite o email do usuario: ");
    scanf("%s", (*lista)[*numUsuarios].email);

    printf("Digite o telefone do usuario: ");
    scanf("%s", (*lista)[*numUsuarios].telefone);

    (*numUsuarios)++;
}
void mostrarUsuarios(struct Usuario *lista, int numUsuarios) {
    if (numUsuarios == 0) {
        printf("Lista de Usuários está vazia.\n");
        return;
    }
    printf("Lista de Usuários:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("%d. Nome: %s\n", i+1, lista[i].nome);
        printf("   Sobrenome: %s\n", lista[i].sobrenome);
        printf("   Email: %s\n", lista[i].email);
        printf("   Telefone: %s\n", lista[i].telefone);
        printf("\n");    
    }
}

int main() {
    struct Usuario *listaUsuarios = NULL;
    int numUsuarios = 0;
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Usuário\n");
        printf("2. Mostrar Usuários\n");
        printf("3. Deletar Usuário\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                adicionarUsuario(&listaUsuarios, &numUsuarios);
                break;
            case 2:
                mostrarUsuarios(listaUsuarios, numUsuarios);
                break;
            case 3:
                deletarUsuario(&listaUsuarios, &numUsuarios);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao != 4);

    free(listaUsuarios);
    return 0;
}