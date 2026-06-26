# FreeRTOS Notes

## Task

A FreeRTOS task is an independent execution context managed by the scheduler.

## vTaskDelay()

`vTaskDelay()` blocks the current task for a given number of ticks.

It does not block the whole CPU.

While one task is blocked, the scheduler may run other ready tasks.

## Priority

Task priority decides which ready task should run first when multiple tasks are ready at the same time.

Priority does not directly define how often a task runs.