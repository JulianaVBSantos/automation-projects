#include <stdio.h>
#include <string.h>

#define MAX_LINHA 256

int verificar_usuario(FILE *arq2, const char *linha) {
    char linha_arq2[MAX_LINHA];
    rewind(arq2);  // Reposiciona o ponteiro de leitura para o início do arquivo

    while (fgets(linha_arq2, sizeof(linha_arq2), arq2)) {
        linha_arq2[strcspn(linha_arq2, "\n")] = '\0';

        if (strcmp(linha_arq2, linha) == 0) {
            return 1;  // Linha encontrada no segundo arquivo
        }
    }
    return 0;  // Linha não encontrada no segundo arquivo
}

int main() {
    FILE *arq1, *arq2;
    char linha[MAX_LINHA];

    arq1 = fopen("usuariospendentes.txt", "r");
    arq2 = fopen("usuariostotal.txt", "r");

    if (arq1 == NULL || arq2 == NULL) {
        perror("Erro ao abrir os arquivos");
        return 1;
    }

    printf("Comparando os arquivos...\n");

    while (fgets(linha, sizeof(linha), arq1)) {
        linha[strcspn(linha, "\n")] = '\0';

        if (verificar_usuario(arq2, linha)) {
            printf("%s\n", linha); //usuarios encontrados
        } else {
            // printf("%s\n", linha); //não encontrado
        }
    }
    
    fclose(arq1);
    fclose(arq2);

    return 0;
}