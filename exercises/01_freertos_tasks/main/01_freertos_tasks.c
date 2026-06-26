#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char* TAG = "01_freertos_tasks";

void first_task(void *pvParameters) {
    for(;;) {
        ESP_LOGI(TAG, "Test LOG 1");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void second_task(void *pvParameters) {
    for(;;) {
        ESP_LOGI(TAG, "Test LOG 2");
        vTaskDelay(pdMS_TO_TICKS(1200));
    }
}

void app_main(void) {
    xTaskCreate(first_task, "1st Task", 2048, NULL, 5, NULL);
    xTaskCreate(second_task, "2nd Task", 2048, NULL, 4, NULL);
}
