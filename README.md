# LilyGO T5 V2.66 E-Paper IDF Example

Example app for the [LilyGo T5 2.66"](https://www.aliexpress.com/item/1005002474854718.html) ESP32 board. Uses ESP-IDF
with the [esp-epaper-display](https://github.com/VedantParanjape/esp-epaper-display) component.

Be sure to install the esp-epaper-display into `./components/esp-epaper-display`.

Uses the following pins

| Function | Pin |
|----------|-----|
| MOSI     | 23  |
| CLK      | 18  |
| CS       | 5   |
| DC       | 19  |
| RST      | 4   |
| BUSY     | 34  |