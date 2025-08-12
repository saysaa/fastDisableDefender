fastDisableDefender
fastDisableDefender is a lightweight Windows utility written in C that allows you to quickly enable or disable Windows Defender Real-Time Protection and the Windows Firewall from a simple command-line menu.

It’s designed for developers, testers, and advanced users who often encounter false positives when running custom applications, without having to dig into Windows settings each time.

✨ Features
One command to toggle security – Quickly disable or enable Defender and Firewall.

Automatic admin rights – The program requests elevation via UAC if not already running as administrator.

Simple CLI menu – Type disable or activate and the tool does the rest.

Fast & lightweight – Written in C, compiled to a small executable.

🛠 Installation
**Clone this repository:**
git clone https://github.com/saysaa/fastDisableDefender.git
**Compile the program (example with MinGW):**
gcc main.c -o fastDisableDefender.exe
**Run the program:**
fastDisableDefender.exe


💻 Usage
When launched, you’ll see:
'activate' <> 'disable'
>>
Type disable → Turns off Windows Defender real-time monitoring and the Windows Firewall.

Type activate → Turns on Windows Defender real-time monitoring and the Windows Firewall.

**⚠ Disclaimer**
Disabling antivirus and firewall protection makes your system vulnerable.
Only use this tool in a safe and controlled environment.
The author is not responsible for any damage or security breaches caused by misuse.

Notes
Disabling antivirus and firewall protection makes your system vulnerable — only use this tool in safe, controlled environments.

This tool does not uninstall Windows Defender; it only toggles its real-time monitoring feature.

Leave the original name and do not change the program name in order to let the program do an elevation of privilege so that it can run as administrator

