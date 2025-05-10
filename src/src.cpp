#include "../include/src.h"
#include "../include/ui.h"

void startProgram(MYSQL *conn)
{

    system("COLOR 7");
    showStartupAnimation();
    showWelcomeScreen();
    showMainMenu();
    // system("cls");
}
