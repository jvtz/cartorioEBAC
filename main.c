#include <stdio.h> // comunicacao com o usuario
#include <stdlib.h> // alocacao de espaco em memoria
#include <locale.h> // alocacoes de texto por regiao
#include <string.h> // responsavel por cuidar das strings


int registro() { // funcao responsavel por cadastrar o usuario no sistema
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40]; // criacao das variaveis
    
    printf("Digite o CPF a ser cadastrado: "); // coletando informacao do usuario
    scanf("%s", cpf); // %sd refere-se a strings
    
    strcpy(arquivo, cpf); // Copia os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo | w significa write
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
}

int consulta() {
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL) {
        printf("Não foi possível abrir o arquivo, não localizado!\n");
        printf("Pressione Enter para continuar...");
        getchar(); // Aguarda o Enter antes de retornar ao menu
        return;
    }
    
    while(fgets(conteudo,200,file) != NULL) {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
}

int deletar() {
    char cpf[40];
    
    printf("Digite o CPF do usuario a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL) {
        printf("O usuario nao se encontra no sistema!\n");
        getchar();
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    int opcao = 0; // Definindo as linguagens
    int loop = 1;

    for (loop = 1; loop == 1;) {
        system("clear"); // Limpa a tela do console em sistemas Unix/Linux
      
        // Menu do cartório
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: ");

        scanf("%d", &opcao); // Armazenando a escolha do usuário
        getchar(); // Consumir o caractere de nova linha

        system("clear"); // Limpa a tela do console em sistemas Unix/Linux

        switch (opcao) {  // Seleção de opções
            case 1:
                registro();
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;
                
            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
                break;

            default:
                printf("Essa opção não está disponível.\n");
                getchar(); // Pausa e aguarda uma entrada do usuário
                break;
        }
    }

    return 0;
}
