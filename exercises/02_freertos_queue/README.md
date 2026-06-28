# 02 - FreeRTOS Queue

## Goal

The goal of this exercise is to understand basic communication between FreeRTOS tasks using a queue.

This exercise focuses on:

* creating a FreeRTOS queue
* sending messages from one task
* receiving messages in another task
* understanding producer-consumer communication
* avoiding direct shared global data between tasks
* observing how a task can block while waiting for queue data

## What This Exercise Does

This exercise will create two FreeRTOS tasks.

The producer task will periodically create a simple message and send it to a queue.

The consumer task will wait for messages from the queue and log the received data.

The purpose is to observe how tasks can communicate through message passing instead of directly accessing shared variables.

## Planned Structure

The exercise should contain:

* a queue handle
* a simple message structure
* a producer task
* a consumer task
* queue creation in `app_main()`
* task creation in `app_main()`
* error checking for queue creation
* error checking for task creation

## Tested Concepts

This exercise introduces the following concepts:

* `QueueHandle_t`
* `xQueueCreate()`
* `xQueueSend()`
* `xQueueReceive()`
* producer task
* consumer task
* blocking receive
* queue length
* message size
* queue full condition
* queue timeout
* message-based communication

## Expected Output

The monitor should show that the producer sends messages and the consumer receives them.

Example:

```text
I (xxx) 02_freertos_queue: Producer sent message: 1
I (xxx) 02_freertos_queue: Consumer received message: 1

I (xxx) 02_freertos_queue: Producer sent message: 2
I (xxx) 02_freertos_queue: Consumer received message: 2

I (xxx) 02_freertos_queue: Producer sent message: 3
I (xxx) 02_freertos_queue: Consumer received message: 3
```

The consumer should not continuously poll the queue in a tight loop.

It should block while waiting for a message.

## Observations

To be completed after the exercise.

## Implementation Notes

To be completed after the exercise.

## Conclusions

To be completed after the exercise.

## Questions to Answer

After completing this exercise, it should be possible to answer:

* What problem does a FreeRTOS queue solve?
* What is the difference between shared global data and message passing?
* What is a producer task?
* What is a consumer task?
* What happens when a task waits on an empty queue?
* What happens when a task tries to send to a full queue?
* Why is blocking on a queue better than polling in a loop?
* Why are queues useful in embedded applications?
* How can this pattern be used later in a message-driven architecture?

## Related Notes

General FreeRTOS notes are available in:

```text
../../notes/freertos.md
```

## Next Step

After understanding queues, the next step will be to use periodic events more intentionally, for example with a FreeRTOS timer or a dedicated timing task.
