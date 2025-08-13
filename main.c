#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int IsRunAsAdmin() {
    BOOL isAdmin = FALSE;
    PSID adminGroup = NULL;
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&NtAuthority, 2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &adminGroup))
    {
        CheckTokenMembership(NULL, adminGroup, &isAdmin);
        FreeSid(adminGroup);
    }
    return isAdmin;
}

int main(void) {
    // Récupère la fenêtre console
    HWND hwnd = GetConsoleWindow();

    // Charge l'icône depuis un fichier ICO
    HICON hIcon = (HICON)LoadImage(
        NULL,
        "icon.ico",       // chemin vers ton fichier .ico
        IMAGE_ICON,       // type image
        32, 32,           // taille de l'icône
        LR_LOADFROMFILE   // charge depuis un fichier
    );

    if (hIcon) {
        // Définit l'icône petite (barre de titre)
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
        // Définit l'icône grande (Alt+Tab et barre des tâches)
        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    }

    if (!IsRunAsAdmin()) {
        SHELLEXECUTEINFO sei = { sizeof(sei) };
        sei.lpVerb = "runas";
        sei.lpFile = "fastDisableDefender.exe"; // nom du .exe
        sei.nShow = SW_SHOWNORMAL;

        if (!ShellExecuteEx(&sei)) {
            MessageBox(NULL, "ELEVATION PRIVILEGE ERROR: Please execute fastDisableDefender in admin.", "Erreur", MB_ICONERROR);
            return 1;
        }
        return 0;
    }

    printf(">> fastDisableDefender\n");
    char menu_choose[30];

    printf("'activate' <> 'disable'\n");
    while (1) {
        printf(">> ");
        scanf("%29s", menu_choose);

        if (strcmp(menu_choose, "activate") == 0) {
            printf("Activating Defender...\n");
            Sleep(500);
            system("powershell -Command \"Set-MpPreference -EnableRealtimeMonitoring $true -Force\"");
            printf("SUCCESS: Windows Defender enabled!\n");
            break;
        }
        else if (strcmp(menu_choose, "disable") == 0) {
            printf("Disabling Defender...\n");
            Sleep(500);
            system("powershell -Command \"Set-MpPreference -DisableRealtimeMonitoring $true -Force\"");
            printf("SUCCESS: Windows Defender disabled!\n");
            Sleep(500);
            break;
        }
        else {
            printf("Invalid syntax :/\n");
        }
    }
    return 0;
}
