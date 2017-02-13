#ifndef MAINWND_H
#define MAINWND_H

/* Window procedure for our main window */
LONG FAR PASCAL MainWndProc(HWND, unsigned, WORD, LONG);

/* Register a class for our main window */
BOOL RegisterMainWindowClass();

/* Create an instance of our main window */
HWND CreateMainWindow();

/* Minimum and maximum window sizing */
#ifndef WM_GETMINMAXINFO
  #define WM_GETMINMAXINFO 0x0024
#endif

typedef struct tagMINMAXINFO
{
  POINT ptReserved;
  POINT ptMaxSize;
  POINT ptMaxPosition;
  POINT ptMinTrackSize;
  POINT ptMaxTrackSize;
} MINMAXINFO;

/* Button colour */
#ifndef COLOR_BTNFACE
  #define COLOR_BTNFACE 15
#endif

/* Overlapped window style */
#ifndef WS_OVERLAPPEDWINDOW
  #define WS_OVERLAPPEDWINDOW WS_TILED | WS_CAPTION | WS_SYSMENU | WS_SIZEBOX | 0x00010000L | 0x00020000L
#endif

/* Default window positioning */
#ifndef CW_USEDEFAULT
  #define CW_USEDEFAULT ((int)0x8000)
#endif

#endif
