#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

#include "qrenc.h"

HINSTANCE hInst;


BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    int nArgc = 4;
    _TCHAR * pArgv[] =
    {
        _T(""),
        _T("-o"),
        _T("ppsbbs.png"),
        _T("http://www.ppsbbs.com"),
    };
    qrencode_tmain_bmp(__argc, __argv);
    qrencode_tmain(nArgc, pArgv);

    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
