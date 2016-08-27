#ifndef ABOUTDLG_H
#define ABOUTDLG_H

/* Dialog procedure for our "about" dialog */
BOOL FAR PASCAL AboutDialogProc(HWND, unsigned, WORD, LONG);

/* Show our "about" dialog */
void ShowAboutDialog(HWND);

#endif
