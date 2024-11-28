#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "RevogacaoAcesso.h"

int main() {
    printf("Automação iniciada. Pressione ESC para sair.\n");
 
    FILE* arquivo = fopen("usuariospendentes.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Arquivo localizado!\n");
 
    char nomeUsuario[256]; // Buffer para armazenar cada nome
 
    while (1) {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("Tecla ESC pressionada. Finalizando...\n");
            break;
        }
 
        int isLastUser = 0; // Variável para verificar se o usuário é o último
        while (fgets(nomeUsuario, sizeof(nomeUsuario), arquivo)) {

            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                printf("Tecla ESC pressionada. Finalizando...\n");
                fclose(arquivo);
                return 0;
            }
 
            nomeUsuario[strcspn(nomeUsuario, "\n")] = 0;
 
            if (feof(arquivo)) {
                isLastUser = 1;
            }
 
            printf("Processando usuario: %s\n", nomeUsuario);

            clickMouse(1181, 219);
            Sleep(600);
 
            clickMouse(1242, 394);
            Sleep(600);
 
            clickMouse(1444, 461);
            Sleep(600);
 
            clearText();
            Sleep(600);
           
            typeText(nomeUsuario);
            Sleep(1000);
            
            clickMouse(1402, 614);
            Sleep(800);
 
            clickMouse(1036, 241);
            Sleep(800);
 
            clickMouse(1842, 171);
            Sleep(800);

            clickMouse(1842, 171);
            Sleep(800);
           
            clickMouse(1205, 436);
            Sleep(800);
 
            clickMouse(1113, 660);
            Sleep(600);
 
            clickMouse(1217, 514);
            Sleep(2500);

            clickMouse(1402, 614);
            Sleep(600);
 
            printf("Usuario %s revogado.\n", nomeUsuario);
 
            if (isLastUser) {
                printf("Ultimo usuario processado. Finalizando...\n");
                fclose(arquivo);
                return 1; // Finaliza o programa
            }
        }
        Sleep(1000);
    }
 
    fclose(arquivo);
    printf("Automacao finalizada.\n");
    return 0;
}