# Windows 1 Example Application

## Table of Contents

- [Introduction](#introduction)
- [Terms of Use](#terms-of-use)
- [Problems?](#problems)
- [Changelog](#changelog)

## Introduction

This application is an example 16 bit Windows application written in C. It
accompanies the
[Building Win16 GUI Applications in C](http://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article on [Transmission Zero](http://www.transmissionzero.co.uk/). The
application runs under Windows 1 to Windows 3.11, and all versions of Windows NT
which support Win16 apps (Windows NT 3.1 to at least the x86 version of Windows
8.1). It does not run under Windows 9x (Windows 95 to Windows ME). The reason
for this is not known at the moment.

To build the application with Microsoft C, open a command prompt, change to the
directory containing the Makefile, and run "make Win1App". Note that you will
need a very old version of the C compiler and Windows SDK to build the
application. I built it with Microsoft C 4 (not to be confused with Visual C++
4), but I believe it will compile with Microsoft C 5 as well. It cannot be built
with newer tools, e.g. Visual C++ 1.52, and I'm not aware of any freely
available tools you can use to build it.

## Terms of Use

Refer to "License.txt" for terms of use.

## Problems?

If you have any problems or questions, please ensure you have read this readme
file and the
[Building Win16 GUI Applications in C](http://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article. If you are still having trouble, you can
[get in contact](http://www.transmissionzero.co.uk/contact/).

## Changelog

1. 2014-11-09: Version 1.0
  - First release.

Transmission Zero
2016-08-27
