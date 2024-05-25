#include <stdio.h>
#include "LED.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "esp_timer.h"

static const char* TAG = "LED";

LED::LED(gpio_num_t pin) : pin (pin)
{
    ESP_LOGI(TAG, "Create Led on pin %d", pin);
    esp_rom_gpio_pad_select_gpio(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    state = LS_NONE
}

LED::~LED()
{
    ESP_LOGI(TAG, "Delete Led on pin %d", pin);
}

    void LED::On(){
        ESP_LOGI(TAG, "Turn on Led on pin %d", pin);
        gpio_set_level(pin, 1);
    }

    void LED::Off(){
        ESP_LOGI(TAG, "Turn off Led on pin %d", pin);
        gpio_set_level(pin, 0);
    }

    void LED::update(){
        switch (state)
        {
            case LS_BLINKIN:
                if (pdTICKS_TO_MS() - timer) + on + off){
                    timer = pdTICKS_TO_MS(xTaskGetTickCount());
                    On();
                }
                else if(pdTICKS_TO_MS(xTaskGetTickCount()) > timer + on)
                {
                    Off();
                }
                break;
            
            default:
                break;
        }

    void LED::blink(unsigned int on, unsigned int off){
        this->on = on;
        this->off = off;
        
        timer = pdTICKS_TO_MS(xTaskGetTickCount();
        On();
        state = LS_BLINKIN;
    }