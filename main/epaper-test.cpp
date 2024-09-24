#include <stdio.h>
#include "epaper.h"

#include <cstring>
#include <driver/gpio.h>
#include <hal/gpio_types.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/timer.h"

#define COLORED     0
#define UNCOLORED   1

extern "C" void app_main(void)
{
    Epd epd;
    unsigned char* frame = (unsigned char*)malloc(epd.width * epd.height / 8);

    Paint paint(frame, epd.width, epd.height);
    paint.Clear(UNCOLORED);

    ESP_LOGI("EPD", "e-Paper init and clear");
    epd.Init();
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    int d = 0;
    for (char i = '0'; i <= '9'; i++)
    {
        paint.DrawCharAt(d, d, i, &Font20, COLORED);
        d = d + 20;
    }

    epd.DisplayFrame(frame);
    epd.Sleep();
}
