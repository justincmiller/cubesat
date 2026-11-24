#include "controller.h"

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

namespace {
constexpr auto stack_depth = 256U;
constexpr UBaseType_t priority = 24; // Matches the CubeMX CMSIS-RTOS2 normal priority.

void RunController(void *) {
    // Half a second in kernel ticks, rounded up to a whole tick.
    constexpr auto delay_ticks = (configTICK_RATE_HZ + 1U) / 2U;

    while (true) {
        HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        vTaskDelay(delay_ticks);
    }
}
} // namespace

extern "C" void Controller_Init(void) {
    if (xTaskCreate(RunController, "controller", stack_depth, nullptr, priority, nullptr) != pdPASS) {
        Error_Handler();
    }
}
