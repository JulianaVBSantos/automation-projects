#include <windows.h>
#include <stdio.h>
#include <string.h>
 
void clickMouse(int x, int y);
void typeText(const char* text);
void clearText();
 
int main() {
    printf("Automacao iniciada. Pressione ESC para sair.\n");
 
    FILE* arquivo = fopen("usuariospendentesosmobile.txt", "r");
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
 
        int isLastUser = 0;
        while (fgets(nomeUsuario, sizeof(nomeUsuario), arquivo)) {
            // Verifica a tecla ESC dentro do loop
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
 
            // 3 pontinhos
            clickMouse(413, 223);
            Sleep(500);
 
            // Filtro
            clickMouse(487, 367);
            Sleep(500);
 
            // seleciona
            clickMouse(630, 418);
            Sleep(500);
 
            // limpa entrada
            clearText(); 
            Sleep(500);
           
            // digita user
            typeText(nomeUsuario);
            Sleep(1000);
 
            // pesquisa
            clickMouse(608, 544);
            Sleep(500);
 
            // seleciona
            clickMouse(285, 244);
            Sleep(500);
 
            // edita
            clickMouse(831, 192);
            Sleep(1700);
           
            // calendario
            clickMouse(648, 600);
            Sleep(500);
            /*clickMouse(652, 660);
            Sleep(500);*/
 
            // seleciona dia 29
            clickMouse(397, 780);
            Sleep(500);
 
            // ok
            clickMouse(654, 764);
            Sleep(3500);
 
            clickMouse(733, 680);
            Sleep(500);
 
            printf("Usuario %s revogado.\n", nomeUsuario);
 
            if (isLastUser) {
                printf("Ultimo usuario processado. Finalizando...\n");
                fclose(arquivo);
                return 1; // Finaliza o programa
            }
        }
        Sleep(1000);
    }
 
    fclose(arquivo); // Fecha o arquivo
    printf("Automacao finalizada.\n");
    return 0;
}
 
void clickMouse(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
 
void typeText(const char* text) {
    for (int i = 0; text[i] != '\0'; i++) {
        SHORT key = VkKeyScan(text[i]);
        keybd_event((BYTE)key, 0, 0, 0);
        keybd_event((BYTE)key, 0, KEYEVENTF_KEYUP, 0);
        Sleep(50);
    }
}
 
void clearText() {
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x41, 0, 0, 0);      
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
 
    Sleep(500);
 
    for (int i = 0; i < 10; i++) {
        keybd_event(0x08, 0, 0, 0);  
        keybd_event(0x08, 0, KEYEVENTF_KEYUP, 0);
        Sleep(50);
    }
}