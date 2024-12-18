#include <windows.h>
#include <stdio.h>

int main() {
    printf("Movimente o mouse para ver as coordenadas.\n");
    
    while (1) {
        // Verifica se a tecla ESC foi pressionada para sair do loop
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("Tecla ESC pressionada. Finalizando...\n");
            break;
        }

        POINT pt;
        if (GetCursorPos(&pt)) {  // Obtém as coordenadas do mouse
            printf("Coordenadas do mouse: X=%d, Y=%d\n", pt.x, pt.y);
        }

        Sleep(100);  // Pausa para reduzir a quantidade de impressões no console
    }

    return 0;
}