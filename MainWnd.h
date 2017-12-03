#ifndef MAINWND_H
#define MAINWND_H

/* Window procedure for our main window */
LONG FAR PASCAL MainWndProc(HWND, unsigned, WORD, LONG);

/* Register a class for our main window */
BOOL RegisterMainWindowClass(void);

/* Create an instance of our main window */
HWND CreateMainWindow(void);

#endif
