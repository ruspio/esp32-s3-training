# 02 - FreeRTOS Queue

## Goal

The goal of this exercise is to understand basic communication between FreeRTOS tasks using a queue.

This is the first step toward a message-driven application structure.

In the final Spotify Display project, queues will be useful for sending events between infrastructure code and the application core.

## Why Queues Matter

In a multi-task FreeRTOS application, tasks should not randomly access and modify shared global data.

A better approach is to send messages.

A queue allows one task to send data to another task in a controlled and thread-safe way.

This is important because different tasks may run at different times and with different priorities.

## Concepts to Learn

This exercise focuses on:

* creating a FreeRTOS queue
* sending data to a queue
* receiving data from a queue
* producer task
* consumer task
* blocking on queue receive
* queue timeout
* basic message/event structure

## Planned Exercise

Create two tasks:

### Producer Task

The producer task periodically creates a simple message and sends it to a queue.

Example message meaning:

* button event
* timer tick
* test counter value
* application event

At this stage, the message can be very simple.

### Consumer Task

The consumer task waits for messages from the queue.

When a message is received, it logs the message content.

The consumer should not continuously poll in a tight loop.

It should block while waiting for new messages.

## Expected Behavior

The producer task sends a message periodically.

The consumer task wakes up only when a message is available.

This demonstrates that a task can wait efficiently for communication from another task.

## Important Design Idea

The producer should not directly call logic inside the consumer.

Instead, it sends a message.

This creates separation between:

* the task that detects or creates an event
* the task that reacts to the event

This idea will later be used in the application architecture.

## Future Relation to Spotify Display

In the future project, a similar queue may be used for application events such as:

* WiFiConnected
* WiFiDisconnected
* RefreshRequested
* PlaybackUpdated
* PlaybackFetchFailed
* ButtonPressed

The application task can receive these events and decide what to do next.

This is a good foundation for a message-driven architecture.

## Embedded Architecture Note

A FreeRTOS queue is an infrastructure mechanism.

The final application logic should not depend too heavily on FreeRTOS-specific details.

For now, the goal is to understand how queues work.

Later, queues can be hidden behind a small platform or adapter layer if needed.

## What to Observe

During this exercise, observe:

* whether the consumer task sleeps while waiting for data
* whether the producer can send messages periodically
* what happens when the queue is full
* what happens when the consumer waits with a timeout
* how message passing differs from using global variables

## Key Questions

After completing this exercise, it should be possible to answer:

* What problem does a queue solve?
* What is the difference between shared global data and message passing?
* What is a producer task?
* What is a consumer task?
* What happens when a task waits on an empty queue?
* What happens when a task tries to send to a full queue?
* Why are queues useful in embedded applications?

## Success Criteria

This exercise is complete when:

* a queue is created successfully
* one task sends messages to the queue
* another task receives messages from the queue
* logs show successful communication between tasks
* the behavior of blocking receive is understood

## Current Status

The ESP-IDF project structure for this exercise has been created.

The required FreeRTOS headers have been added.

The queue logic is not implemented yet.

The next step is to create:

* a queue handle
* a producer task
* a consumer task
* a simple message structure
* basic error checking for queue creation and task creation

This exercise will be implemented step by step.

## Next Step

After understanding queues, the next step will be to use periodic events more intentionally, for example with a FreeRTOS timer or a dedicated timing task.
