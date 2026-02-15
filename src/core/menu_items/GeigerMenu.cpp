#include "GeigerMenu.h"

#include "core/display.h"
#include "core/utils.h"

void GeigerMenu::optionsMenu() {
    options = {
        {"Monitor",      [=]() { /* TODO: Add Geiger monitoring */ }},
        {"Settings",     [=]() { /* TODO: Add Geiger settings */ }},
    };

    addOptionToMainMenu();
    loopOptions(options, MENU_TYPE_SUBMENU, "Geiger Counter");
}

void GeigerMenu::drawIcon(float scale) {
    clearIconArea();

    int radius = scale * 6;
    int centerX = iconCenterX;
    int centerY = iconCenterY;

    // Radiation symbol - three blades with center circle
    // Center circle
    tft.fillCircle(centerX, centerY, radius, bruceConfig.priColor);

    // Three radiation blades (trefoil symbol)
    float angles[] = {0, 120, 240};
    for (int i = 0; i < 3; i++) {
        float angle = angles[i] * PI / 180.0;
        float nextAngle = (angles[i] + 60) * PI / 180.0;
        
        int innerR = radius * 1.5;
        int outerR = radius * 4;
        
        // Draw blade as filled arc
        tft.drawArc(
            centerX, centerY,
            outerR, innerR,
            angles[i] + 10, angles[i] + 50,
            bruceConfig.priColor, bruceConfig.bgColor
        );
    }

    // Outer ring
    tft.drawCircle(centerX, centerY, radius * 4.5, bruceConfig.priColor);
    tft.drawCircle(centerX, centerY, radius * 4.5 - 1, bruceConfig.priColor);
}
