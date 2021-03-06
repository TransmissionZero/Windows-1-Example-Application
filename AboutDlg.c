#include <windows.h>
#include "AboutDlg.h"
#include "Globals.h"
#include "Resource.h"

/* Dialog procedure for our "about" dialog */
BOOL FAR PASCAL AboutDialogProc(hwndDlg, uMsg, wParam, lParam)
HWND hwndDlg;
unsigned uMsg;
WORD wParam;
LONG lParam;
{
  switch (uMsg)
  {
    case WM_COMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case IDOK:
        case IDCANCEL:
        {
          EndDialog(hwndDlg, id);
          return TRUE;
        }
      }
      break;
    }

    case WM_INITDIALOG:
    {
      return TRUE;
    }
  }

  return FALSE;
}

/* Show our "about" dialog */
void ShowAboutDialog(owner)
HWND owner;
{
  /* Create dialog callback thunk */
  FARPROC aboutProc = MakeProcInstance(AboutDialogProc, g_hInstance);

  DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_ABOUTDIALOG), owner, aboutProc);

  /* Free dialog callback thunk */
  FreeProcInstance(aboutProc);
}
