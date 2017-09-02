#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

static LRESULT CALLBACK proc(HWND hWnd, UINT msg, WPARAM w, LPARAM l){
    return DefWindowProc(hWnd, msg, w, l);
}

int
main(int ac, char** av){
    char kblname[1024];
    int r;
    HKL hKl;
    ATOM a;
    HWND h;

    WNDCLASSEX cls;
    memset(&cls, 0, sizeof(cls));
    cls.cbSize = sizeof(cls);
    cls.hInstance = GetModuleHandle(NULL);
    cls.lpfnWndProc = proc;
    cls.lpszClassName = "test";

    a = RegisterClassEx(&cls);
    printf("a = %p\n", a);


    h = CreateWindow("test", "title", WS_OVERLAPPEDWINDOW,
                     100, 100, 100, 100,
                     NULL, NULL, GetModuleHandle(NULL),
                     NULL);
    printf("h = %p\n", h);
    ShowWindow(h, SW_SHOW);

    r = GetKeyboardLayoutName(&kblname);
    printf("Keyboard layout = %s\n", kblname);
    hKl = LoadKeyboardLayout("00000411", KLF_ACTIVATE);
    printf("hkl = %p\n", hKl);
    hKl = ActivateKeyboardLayout(hKl, KLF_SETFORPROCESS);
    printf("hkl = %p\n", hKl);
    return 0;
}
