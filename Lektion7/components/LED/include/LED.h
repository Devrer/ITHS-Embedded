#ifndef _LED_H_
#define _LED_H_
#include "driver/gpio.h"

class LED
{
    typedef enum ledState_e
    {
        LS_NONE = 0,
        LS_BLINKIN_ON,
        LS_BLINKIN_OFF
    } 
private:
    gpio_num_t pin;
    unsigned int on;
    unsigned int off;
    uint64_t timer;
public:
    LED(gpio_num_t pin);
    ~LED();

    void On();
    void Off();

    void update();
    void blink(unsigned int on, unsigned int off);
};




#endif