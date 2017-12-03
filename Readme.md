# Windows 1 Example Application

## Table of Contents

- [Introduction](#introduction)
- [Building the Application](#building-the-application)
- [Marking the Application](#marking-the-application)
- [Terms of Use](#terms-of-use)
- [Known Problems](#known-problems)
- [Changelog](#changelog)

## Introduction

This application is an example Windows 1 application written in C. It accompanies the
[Building Win16 GUI Applications in C](https://www.transmissionzero.co.uk/computing/win16-apps-in-c/) article on
[Transmission Zero](https://www.transmissionzero.co.uk/).

The application runs under Windows 1 to Windows 3.11, and all versions of Windows NT which support Win16 apps (Windows
NT 3.1 to at least the x86 version of Windows 10). It does not run under Windows 9x (Windows 95 to Windows ME). I think
the reason is that Windows 9x just doesn't have support for Windows 1 and 2 applications, whereas Windows NT does
because the Win16 subsystem is based on Windows 3.1.

## Building the Application

To build the application you will need Microsoft C 4 and a Windows 1 SDK. Microsoft C 4 also works with a Windows 2 SDK,
and although the executables it produces target Windows 2, they seem to run fine on Windows 1. You can also build the
application with Microsoft C 3 and the Windows 1.01 SDK, or Microsoft C 5 and a Windows 2 SDK. Other combinations of
Microsoft C and Windows SDK either won't work at all, or will work with some modifications but produces an executable
which only works on Windows 3.x and later.

To perform the build with Microsoft C 4, open a command prompt (with the relevant environment variables set that
Microsoft C needs), change to the directory containing the Makefile, and run "make Win1App".

If you are using Microsoft C 5, the build depends on how you configured the Windows 2 SDK. If you configured it to
replace the standard C libraries with the special Windows combined libraries, the build is the same as the Microsoft C 4
build. If not, you will first need to change the linker command line as follows:

```$(LINK) /NOD [obj files],$(EXE) /align:16,/map,slibw.lib slibcew.lib,Win1App.def```

The `/NOD` tells the linker not to link the default libraries (e.g. `slibce.lib`), and the addition of `slibcew.lib`
causes it to link against this special Windows version instead.

If you are using Microsoft C 3, you will need to make some changes to the Makefile. The compiler should be changed from
"cl" to "cc", and you'll need to specify the "/NOD" linker command line option and link against "swlibc.lib".

Note that Microsoft C should not be confused with Visual C++, as Visual C++ 4.0 arrived on the scene nearly 10 years
after Visual C 4.0. Even Visual C++ 1.0 is too new to build Windows 1 and 2 applications with.

I'm not aware of any freely available tools you can use to build the application.

## Marking the Application

The Makefile includes a step to run `mark` on the produced executable. This tool can be found in the Windows 3.x SDKs,
and marks the application as being safe to run in protected mode and gives the application a proportional font rather
than a fixed font. This step is completely optional, but results in the application looking nicer under Windows 3.x and
later, and also means Windows does not give a warning suggesting the user contacts the author to get a newer version of
the application.

## Terms of Use

Refer to "License.txt" for terms of use.

## Known Problems

The icon does not display correctly in versions of Windows after Windows 3.x and Windows NT 3.1. Icons in Windows 1 and
2 are a different file format from the ".ico" file format, and there appears to be a bug introduced around the Windows
95 period which breaks support for them. It happens to all Windows 1 and 2 applications, so it's not a problem with the
supplied icon file. Interestingly, it doesn't affect the display of cursors, despite the fact that the difference
between a Windows 1 cursor and icon is a single byte in the header.

If you have any problems or questions, please ensure you have read this readme file and the
[Building Win16 GUI Applications in C](https://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article. If you are still having trouble, you can [get in contact](https://www.transmissionzero.co.uk/contact/).

## Changelog

3. 2017-05-21: Version 1.2
  - Removed unnecessary whitespace from source files.
  - Corrected min / max window size handling, which should have been using a far pointer for the MINMAXINFO struct.
  - Makefile enhancements and support for Microsoft C 5.
  - Target 8086 instead of 80286, and use emulation if x87 isn't available.

2. 2016-08-28: Version 1.1
  - Corrected name in module definition file. This was causing an odd issue where launching the Windows 3.x version of
    the application while the Windows 1 application was running, resulted in a second instance of the Windows 1
    application!

1. 2014-11-09: Version 1.0
  - First release.

Transmission Zero
2017-05-21
