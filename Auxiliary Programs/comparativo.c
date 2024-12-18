#include <stdio.h>
#include <string.h>

#define MAX_LINHA 256

int verificar_usuario(FILE *arq2, const char *linha) {
    char linha_arq2[MAX_LINHA];
    rewind(arq2); 

    while (fgets(linha_arq2, sizeof(linha_arq2), arq2)) {

        linha_arq2[strcspn(linha_arq2, "\n")] = '\0';

        if (strcmp(linha_arq2, linha) == 0) {
            return 1;
        }
    }
    return 0; 
}

int main() {
    FILE *arq1, *arq2;
    char linha[MAX_LINHA];

    arq1 = fopen("usuariospendentesosmobile.txt", "r");
    arq2 = fopen("totaldeusuarios.txt", "r");

    if (arq1 == NULL || arq2 == NULL) {
        perror("Erro ao abrir os arquivos");
        return 1;
    }

    printf("Comparando os arquivos...\n");

    while (fgets(linha, sizeof(linha), arq1)) {
        linha[strcspn(linha, "\n")] = '\0';

        if (verificar_usuario(arq2, linha)) {
            printf("%s\n", linha);
        } else {
            // printf("%s\n", linha); //não encontrado no arquivo01
        }
    }

    fclose(arq1);
    fclose(arq2);

    return 0;
}