# Windows 1 Example Application

## Table of Contents

- [Introduction](#introduction)
- [Building the Application](#building-the-application)
- [Terms of Use](#terms-of-use)
- [Known Problems](#known-problems)
- [Changelog](#changelog)

## Introduction

This application is an example 16 bit Windows application written in C. It
accompanies the
[Building Win16 GUI Applications in C](http://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article on [Transmission Zero](http://www.transmissionzero.co.uk/).

The application is a little anachronistic, since it makes use of functionality
which didn't exist in Windows 1. An example is overlapped windows, which didn't
exist until Windows 2 (Windows 1 only supported tiled windows). That doesn't
magically make the functionality work on Windows 1, but means it works on the
supported version of Windows and falls back gracefully on the unsupported one.
This has been achieved by defining constants and structures in the header files
of this project, which match the definitions of later Windows SDKs. This works
because Windows API changes are designed to be backwards compatible, so older
versions of Windows just ignore window styles it doesn't understand, and message
handlers in the application will never receive messages which aren't defined on
that version of Windows.

The application runs under Windows 1 to Windows 3.11, and all versions of
Windows NT which support Win16 apps (Windows NT 3.1 to at least the x86 version
of Windows 10). It does not run under Windows 9x (Windows 95 to Windows ME). I
think the reason is that Windows 9x just doesn't have support for Windows 1 and
2 applications, whereas Windows NT does because the Win16 subsystem is based on
Windows 3.1.

## Building the Application

To build the application you will either need Microsoft C 4 with a Windows 1 SDK
or Microsoft C 5 with a Windows 2 SDK. To perform the build, open a command
prompt (with the relevant environment variables set that Microsoft C needs),
change to the directory containing the Makefile, and run "make Win1App".

Note that Microsoft C should not be confused with Visual C++, as Visual C++ 4.0
arrived on the scene nearly 10 years after Visual C 4.0. Even Visual C++ 1.0 is
too new to build Windows 1 and 2 applications with.

I'm not aware of any freely available tools you can use to build the
application.

## Terms of Use

Refer to "License.txt" for terms of use.

## Known Problems

The icon does not display correctly in versions of Windows after 3.x. Icons in
Windows 1 and 2 are a different file format from the ".ico" file format, and I
think they either aren't supported in later versions or there is a bug which
means they aren't rendered correctly. Either way, it happens to all Windows 1
and 2 applications, so it's not a problem with the supplied icon file.

If you have any problems or questions, please ensure you have read this readme
file and the
[Building Win16 GUI Applications in C](http://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article. If you are still having trouble, you can
[get in contact](http://www.transmissionzero.co.uk/contact/).

## Changelog

2. 2016-08-28: Version 1.1
  - Corrected name in module definition file. This was causing an odd issue
    where launching the Windows 3.x version of the application while the Windows
    1 application was running, resulted in a second instance of the Windows 1
    application!

1. 2014-11-09: Version 1.0
  - First release.

Transmission Zero
2016-08-28
