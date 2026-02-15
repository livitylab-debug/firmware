#ifndef __GEIGER_MENU_H__
#define __GEIGER_MENU_H__

#include "MenuItemInterface.h"

class GeigerMenu : public MenuItemInterface {

public:
    GeigerMenu() : MenuItemInterface("Geiger Counter") {}

    void optionsMenu(void);
    void drawIcon(float scale);

    bool hasTheme() { return false; }
    String themePath() { return ""; }
};

#endif
