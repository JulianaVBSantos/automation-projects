#include <windows.h>
#include <stdio.h>
#include <string.h>
 
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
        Sleep(50); // Pausa para simular digitação
    }
}
 
void clearText() {
    keybd_event(VK_CONTROL, 0, 0, 0); // Pressiona Ctrl
    keybd_event(0x41, 0, 0, 0);       // Pressiona A
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // Libera A
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0); // Libera Ctrl
 
    Sleep(500);
 
    for (int i = 0; i < 10; i++) { // Limita o número de Backspaces para evitar loops infinitos
        keybd_event(0x08, 0, 0, 0);   // Pressiona Backspace
        keybd_event(0x08, 0, KEYEVENTF_KEYUP, 0); // Libera Backspace
        Sleep(50); // Atraso entre os Backspaces
    }
}