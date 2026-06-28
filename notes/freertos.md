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

## app_main() in ESP-IDF

In ESP-IDF, `app_main()` is the user application entry point.

However, it is not the same as a bare-metal `main()` function.

ESP-IDF initializes the system and starts the FreeRTOS scheduler before calling `app_main()`.

As a result, `app_main()` already runs inside a FreeRTOS task.

Because of this, the user should not call `vTaskStartScheduler()` manually in ESP-IDF projects.

## vTaskStartScheduler()

In a standalone FreeRTOS application, `vTaskStartScheduler()` is used to start the FreeRTOS scheduler.

In ESP-IDF, the scheduler is started by the framework.

Calling `vTaskStartScheduler()` manually is not part of the normal ESP-IDF application flow.

## xTaskCreate()

`xTaskCreate()` creates a new FreeRTOS task.

The return value should be checked.

Successful task creation returns:

```text
pdPASS
```

If task creation fails, the task will not run.

A common reason for failure is insufficient memory for the task stack or internal task structures.

## Task Stack Size in ESP-IDF

In ESP-IDF, the stack size passed to `xTaskCreate()` is expressed in bytes.

Example:

```text
xTaskCreate(task_function, "task_name", 2048, NULL, 5, NULL)
```

This creates a task with a stack size of 2048 bytes.

## Good Practice

For learning exercises and real projects, check the result of every `xTaskCreate()` call.

This makes task creation errors visible in logs and helps avoid silent failures.
