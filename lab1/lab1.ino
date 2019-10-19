#include <Arduino.h>
#include "button.h"

#define R_OUT 6
#define G_OUT 7
#define B_OUT 8
#define INCREASE_R_BUTTON 9
#define DECREASE_R_BUTTON 10
#define INCREASE_G_BUTTON 11
#define DECREASE_G_BUTTON 12
#define INCREASE_B_BUTTON 13
#define DECREASE_B_BUTTON 14
#define COLOR_DELTA 50

Button IncreasingButtons[] = { Button(INCREASE_R_BUTTON), Button(INCREASE_G_BUTTON), Button(INCREASE_B_BUTTON)};
Button DecreasingButtons[] = { Button(DECREASE_R_BUTTON), Button(DECREASE_G_BUTTON), Button(DECREASE_B_BUTTON)};
int RgbValues[] = { 0, 0, 0 };

void setup()
{
    pinMode(INCREASE_R_BUTTON, INPUT);
    pinMode(INCREASE_G_BUTTON, INPUT);
    pinMode(INCREASE_B_BUTTON, INPUT);
    pinMode(DECREASE_R_BUTTON, INPUT);
    pinMode(DECREASE_G_BUTTON, INPUT);
    pinMode(DECREASE_B_BUTTON, INPUT);
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
    for (int i = 0; i < 3; ++i)
    {
        if (IncreasingButtons[i].wasPressed())
            RgbValues[i] = min(RgbValues[i] + COLOR_DELTA, 250);

        if (DecreasingButtons[i].wasPressed())
            RgbValues[i] = max(0, RgbValues[i] - COLOR_DELTA);
    }

    set_rgb_led();
}

void set_rgb_led()
{
    analogWrite(R_OUT, RgbValues[0]);
    analogWrite(G_OUT, RgbValues[1]);
    analogWrite(B_OUT, RgbValues[2]);
}
