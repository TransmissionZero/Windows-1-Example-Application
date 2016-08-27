#include <windows.h>
#include <string.h>
#include "mainwnd.h"
#include "aboutdlg.h"
#include "resource.h"
#include "globals.h"

/* Main window class and title */
static char MainWndClass[] = "Windows 1 Example Application";

/* Window procedure for our main window */
LONG FAR PASCAL MainWndProc(hWnd, msg, wParam, lParam)
HWND hWnd;
unsigned msg;
WORD wParam;
LONG lParam;
{
  switch (msg)
  {
    case WM_COMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case ID_HELP_ABOUT:
        {
          ShowAboutDialog(hWnd);
          break;
        }

        case ID_FILE_EXIT:
        {
          DestroyWindow(hWnd);
          break;
        }

        default:
          return DefWindowProc(hWnd, msg, wParam, lParam);
      }

      break;
    }

    case WM_GETMINMAXINFO:
    {
      /* Prevent our window from being sized too small */
      MINMAXINFO *minMax = (MINMAXINFO*) lParam;
      minMax->ptMinTrackSize.x = 220;
      minMax->ptMinTrackSize.y = 110;

      break;
    }

    /* Item from system menu has been invoked */
    case WM_SYSCOMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case ID_HELP_ABOUT:
        {
          ShowAboutDialog(hWnd);
          break;
        }

        default:
          return DefWindowProc(hWnd, msg, wParam, lParam);
      }

      break;
    }

    case WM_DESTROY:
    {
      PostQuitMessage(0);
      break;
    }

    default:
      return DefWindowProc(hWnd, msg, wParam, lParam);
  }

  return 0;
}

/* Register a class for our main window */
BOOL RegisterMainWindowClass()
{
  WNDCLASS wc;

  memset(&wc, 0, sizeof(wc));

  wc.lpfnWndProc   = MainWndProc;
  wc.hInstance     = g_hInstance;
  wc.hIcon         = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_APPICON));
  wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
  wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MAINMENU);
  wc.lpszClassName = MainWndClass;        

  return (RegisterClass(&wc)) ? TRUE : FALSE;
}

/* Create an instance of our main window */
HWND CreateMainWindow()
{
  HWND hWnd;
  HMENU hSysMenu;

  hWnd = CreateWindow(MainWndClass, MainWndClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                      320, 200, NULL, NULL, g_hInstance, NULL);

  if (hWnd)
  {
    /* Add "about" to the system menu. */
    hSysMenu = GetSystemMenu(hWnd, FALSE);
    ChangeMenu(hSysMenu, 0, NULL, 999, MF_APPEND | MF_SEPARATOR);
    ChangeMenu(hSysMenu, 0, "About", ID_HELP_ABOUT, MF_APPEND | MF_STRING);
  }

  return hWnd;
}
