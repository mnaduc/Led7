#if !defined(LED7_H_)
#define LED7_H_

#include <Arduino.h>

class Led7
{
private:
    uint8_t pins_[7];
    static const uint8_t number_to_display[];
    bool is_common_cathode_;
public:
    Led7();
    Led7(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, bool is_common_cathode = true);
    void check();
    void display(char val);
};

#endif // LED7_H_
