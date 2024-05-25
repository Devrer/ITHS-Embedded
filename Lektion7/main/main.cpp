#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <LED.h>

#define LED_PIN GPIO_NUM_18

static const char *TAG = "MAIN";

LED *led1;

extern "C" void app_main(void)
{
    led1 = new LED(LED_PIN);

    led1->(1000, 1000);

    for (size_t i=0; i < 10; i++){
        led1->on();
        vTaskDelay(pdMS_TO_TICKS(1000));
        led1->off();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    delete led1;
}