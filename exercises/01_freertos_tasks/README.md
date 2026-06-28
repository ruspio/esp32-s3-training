# 01 - FreeRTOS Tasks

## Goal

The goal of this exercise is to understand the basics of FreeRTOS tasks on ESP32-S3 using ESP-IDF.

This exercise focuses on:

* creating FreeRTOS tasks
* using `vTaskDelay()`
* observing how tasks are scheduled
* understanding that delaying one task does not block the whole CPU
* observing how two independent tasks can run with different timing

## What This Exercise Does

This exercise creates two FreeRTOS tasks.

The first task logs a message every 500 ms.

The second task logs a message every 1200 ms.

Both tasks run independently and use `vTaskDelay()` to block themselves for a defined amount of time.

The purpose is to observe that when one task is blocked, the scheduler can run another task.

## Tested Concepts

This exercise introduces the following concepts:

* `app_main()`
* task function
* infinite task loop
* `xTaskCreate()`
* task stack size
* task priority
* `vTaskDelay()`
* `pdMS_TO_TICKS()`
* task states: Running, Ready, Blocked
* checking the return value of `xTaskCreate()`

## Expected Output

The monitor should show two different log messages appearing repeatedly.

Example:

```text
I (xxx) 01_freertos_tasks: Test LOG 1
I (xxx) 01_freertos_tasks: Test LOG 2
I (xxx) 01_freertos_tasks: Test LOG 1
I (xxx) 01_freertos_tasks: Test LOG 1
I (xxx) 01_freertos_tasks: Test LOG 2
```

The first task should appear more often because it uses a shorter delay.

## Observations

`vTaskDelay()` blocks only the currently running task.

It does not stop the whole ESP32.

When a task calls `vTaskDelay()`, it enters the Blocked state. During that time, the FreeRTOS scheduler may run other tasks that are ready to execute.

The task resumes from the instruction after `vTaskDelay()`.

Changing task priority may not visibly change the terminal output in this simple exercise. This is expected because both tasks spend most of their time blocked.

Task priority matters mainly when multiple tasks are ready to run at the same time.

## Implementation Notes

The return value of each `xTaskCreate()` call is checked against `pdPASS`.

If task creation fails, an error is logged and `app_main()` returns.

This makes task creation failures visible during testing.

The delay time is converted from milliseconds to FreeRTOS ticks using:

```text
pdMS_TO_TICKS(milliseconds)
```

This is preferred over manual tick conversion because it is more readable and independent of the configured tick period.

## Conclusions

* A FreeRTOS task is an independent execution context managed by the scheduler.
* `vTaskDelay()` blocks the current task, not the whole CPU.
* While one task is blocked, other ready tasks may run.
* A shorter delay means that a task wakes up more often.
* Higher priority does not mean that a task runs more frequently.
* Priority decides which ready task should run first when there is competition for CPU time.
* `xTaskCreate()` should be checked to detect task creation failures.
* `app_main()` may finish after creating tasks. The created tasks continue running.

## Questions to Answer

After completing this exercise, it should be possible to answer:

* What is a FreeRTOS task?
* What happens when a task calls `vTaskDelay()`?
* What does it mean that a task is blocked?
* Why can another task run while the first task is delayed?
* What is the difference between delay time and task priority?
* Why is `pdMS_TO_TICKS()` preferred over manual tick conversion?
* Why should the return value of `xTaskCreate()` be checked?

## Related Notes

General FreeRTOS notes are available in:

```text
../../notes/freertos.md
```

## Next Step

The next exercise introduces FreeRTOS queues.

The goal will be to understand how tasks can communicate safely without sharing global variables directly.
