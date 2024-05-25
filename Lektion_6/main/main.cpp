#include <stdio.h>
#include "lektion1.h"
#include "esp_log.h"

const char* TAG_1 = "MAIN 1";
const char* TAG_2 = "MAIN 2";
const char* TAG_3 = "MAIN 3";

static Lektion1 *obj;

extern "C" void app_main(void)
{
    esp_log_level_set(TAG_2, ESP_LOG_WARN);
    esp_log_level_set(TAG_3, ESP_LOG_DEBUG);

    obj = new Lektion1();

    obj->func();

    ESP_LOGW(TAG_1, "Meddelande %d", 1);
    ESP_LOGI(TAG_2, "Meddelande %d", 2);
    ESP_LOGI(TAG_3, "Meddelande %d", 3);
}