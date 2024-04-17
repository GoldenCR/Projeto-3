#include <stdio.h>

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