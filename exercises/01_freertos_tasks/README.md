# 01 - FreeRTOS Tasks

## Goal

The goal of this exercise is to understand the basics of FreeRTOS tasks on ESP32-S3.

This exercise focuses on:

* creating FreeRTOS tasks
* using `vTaskDelay()`
* observing how tasks are scheduled
* understanding the difference between blocking one task and blocking the whole CPU
* observing how two independent tasks can run with different timing

## Concepts Practiced

Main concepts:

* `app_main()`
* task function
* infinite task loop
* `xTaskCreate()`
* task stack size
* task priority
* `vTaskDelay()`
* `pdMS_TO_TICKS()`
* task states: Running, Ready, Blocked

## What Was Tested

Two FreeRTOS tasks were created.

The first task logs a message every 500 ms.

The second task logs a message every 1500 ms.

The purpose was to observe that when one task is blocked by `vTaskDelay()`, another task can still run.

## Main Observation

`vTaskDelay()` blocks only the currently running task.

It does not stop the whole ESP32.

When a task calls `vTaskDelay()`, it enters the Blocked state. During that time, the FreeRTOS scheduler may run other tasks that are ready to execute.

## Important Notes

`vTaskDelay()` does not take milliseconds directly.

It takes FreeRTOS ticks.

The recommended way to write delays is:

```text
pdMS_TO_TICKS(milliseconds)
```

This makes the code easier to read and independent of the configured tick period.

## Task Timing

If a task does this:

```text
log message
delay 500 ms
log message
delay 500 ms
```

then the logs appear alternately after each delay.

The task resumes from the instruction after `vTaskDelay()`.

## Priority Observation

Changing task priority may not visibly change the terminal output in this simple exercise.

This is expected.

Task priority matters mainly when multiple tasks are ready to run at the same time.

In this exercise, both tasks spend most of their time blocked in `vTaskDelay()`, so there is very little real CPU competition.

## Key Conclusions

* A FreeRTOS task is an independent execution context.
* `vTaskDelay()` blocks the current task, not the whole CPU.
* While one task is blocked, other tasks may run.
* Shorter delay means the task wakes up more often.
* Higher priority does not mean the task runs more frequently.
* Priority decides which ready task should run first when there is competition for CPU time.
* `app_main()` may finish after creating tasks. The created tasks continue running.

## Questions to Answer

After completing this exercise, it should be possible to answer:

* What is a FreeRTOS task?
* What happens when a task calls `vTaskDelay()`?
* What does it mean that a task is blocked?
* Why can another task run while the first task is delayed?
* What is the difference between delay time and task priority?
* Why is `pdMS_TO_TICKS()` preferred over manual tick conversion?

## Next Step

The next exercise introduces FreeRTOS queues.

The goal will be to understand how tasks can communicate safely without sharing global variables directly.
