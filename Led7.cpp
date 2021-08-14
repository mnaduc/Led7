#include "Led7.h"

const uint8_t Led7::number_to_display[] = {
    B0111111, //  0
    B0000110, //  1
    B1011011, //  2
    B1001111, //  3
    B1100110, //  4
    B1101101, //  5
    B1111101, //  6
    B0000111, //  7
    B1111111, //  8
    B1101111, //  9
};

Led7::Led7()
{
    pins_[0] = 6;
    pins_[1] = 8;
    pins_[2] = 9;
    pins_[3] = 10;
    pins_[4] = 11;
    pins_[5] = 12;
    pins_[6] = 5;
    is_common_cathode_ = true;
    for (int i = 0; i < 7; i++)
    {
        pinMode(pins_[i], OUTPUT);
        digitalWrite(pins_[i], LOW);
    }
}

Led7::Led7(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g,  bool is_common_cathode)
{
    pins_[0] = a;
    pins_[1] = b;
    pins_[2] = c;
    pins_[3] = d;
    pins_[4] = e;
    pins_[5] = f;
    pins_[6] = g;
    is_common_cathode_ = is_common_cathode;
    for (int i = 0; i < 7; i++)
    {
        pinMode(pins_[i], OUTPUT);
        digitalWrite(pins_[i], LOW);
    }
}

void Led7::check()
{
    for (size_t i = 0; i < 7; i++)
    {
        digitalWrite(pins_[i], HIGH);
        delay(100);
    }
    delay(400);
    for (size_t i = 0; i < 7; i++)
    {
        digitalWrite(pins_[i], LOW);
        delay(100);
    }
    delay(400);
}

void Led7::display(char val)
{
    uint8_t byte_to_display = 0;
    if (val >= 0 && val < 10)
    {
        byte_to_display = number_to_display[(uint8_t)val];
    }
    else
    {
        switch (val)
        {
        case 'A':
        case 'a':
            byte_to_display = B1110111;
            break;
        case 'B':
        case 'b':
            byte_to_display = B1111100;
            break;
        case 'C':
        case 'c':
            byte_to_display = B0111001;
            break;
        case 'D':
        case 'd':
            byte_to_display = B1011110;
            break;
        case 'E':
        case 'e':
            byte_to_display = B1111001;
            break;
        case 'F':
        case 'f':
            byte_to_display = B1110001;
            break;
        case 'H':
        case 'h':
            byte_to_display = B1110110;
            break;
        case 'I':
        case 'i':
            byte_to_display = B0110000;
            break;
        case 'J':
        case 'j':
            byte_to_display = B0001110;
            break;
        case 'L':
        case 'l':
            byte_to_display = B0111000;
            break;
        case 'N':
        case 'n':
            byte_to_display = B1010100;
            break;
        case 'O':
        case 'o':
            byte_to_display = B1011100;
            break;
        case 'P':
        case 'p':
            byte_to_display = B1110011;
            break;
        case 'R':
        case 'r':
            byte_to_display = B1010000;
            break;
        case 'S':
        case 's':
            byte_to_display = number_to_display[5];
            break;
        case 'U':
        case 'u':
            byte_to_display = B0111110;
            break;
        case 'Y':
        case 'y':
            byte_to_display = B1101110;
            break;
        case 'Z':
        case 'z':
            byte_to_display = number_to_display[2];
            break;
        }
    }
    if (!is_common_cathode_) byte_to_display = ~byte_to_display;
    for (size_t i = 0; i < 7; i++)
        digitalWrite(pins_[i], bitRead(byte_to_display, i));
}
