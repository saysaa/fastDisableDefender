**fastDisableDefender** is a small C utility that allows you to quickly enable or disable Windows Defender Real-Time Protection and the Windows Firewall without having to navigate through multiple Windows menus.

The tool is useful for developers or testers who often encounter false positives during software development or when running custom applications.

Features
Automatic UAC elevation (asks for admin rights if not already elevated)

Toggle between:

Disable: Turns off Windows Defender real-time monitoring and the Windows Firewall

Activate: Re-enables Windows Defender real-time monitoring and the Windows Firewall

Simple text-based menu interface

Fast execution for quick security changes

Requirements
Windows 10/11

Administrator privileges

Windows PowerShell available in the system PATH

Usage
Compile the source code with any Windows C compiler (MinGW, MSVC, etc.).

Run the executable — it will ask for admin rights if not already elevated.

Type:

disable → to turn off Defender & Firewall

activate → to turn them back on

Notes
Disabling antivirus and firewall protection makes your system vulnerable — only use this tool in safe, controlled environments.

This tool does not uninstall Windows Defender; it only toggles its real-time monitoring feature.

