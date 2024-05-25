#include <stdio.h>
#include "lektion1.h"
#include "esp_log.h"

static const char *TAG = "LEKTION 1 ";

Lektion1::Lektion1(/* args */)
{
}

Lektion1::~Lektion1()
{
}

void Lektion1::func()
{
		ESP_LOGI(TAG, CONFIG_EXEMPEL_TEXT);
}