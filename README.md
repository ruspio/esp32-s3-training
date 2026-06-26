# ESP32-S3 Training

This repository contains a set of small ESP32-S3 training projects created with ESP-IDF and FreeRTOS.

The main goal is to learn embedded programming step by step, starting from basic FreeRTOS concepts and gradually moving toward a larger Spotify Display project.

Target board:

* Seeed Studio XIAO ESP32-S3
* ESP32-S3
* Wi-Fi / Bluetooth
* USB-C

Target environment:

* VS Code
* ESP-IDF Extension
* ESP-IDF
* FreeRTOS
* C / embedded C++

## Main Learning Goals

The purpose of this repository is not only to make things work, but to understand how they work.

The main topics are:

* ESP-IDF project structure
* FreeRTOS tasks
* task delays and scheduling
* task priorities
* queues and inter-task communication
* timers
* Wi-Fi connection handling
* basic HTTP server
* JSON status endpoints
* HTTP client
* JSON parsing
* embedded-friendly C++
* hexagonal architecture in an embedded project
* separation between application logic and hardware/framework-specific code

## Final Project Goal

The final goal is to build a small Spotify Display device based on ESP32-S3.

Planned features:

* connect to Wi-Fi
* communicate with Spotify Web API
* fetch current playback information
* expose status through a local web server
* later display playback information on a physical display
* keep the application architecture clean and modular

Before using a physical screen, the project will use a local WebServer as a first display/presentation layer.

## Repository Structure

```text
esp32-s3-training/
  README.md

  notes/
    freertos.md
    wifi.md
    webserver.md
    architecture.md

  exercises/
    01_freertos_tasks/
    02_freertos_queue/
    03_freertos_timer/
    04_wifi_station/
    05_webserver_basic/
    06_webserver_status/
    07_mock_spotify_web/
    08_http_client/
    09_json_parsing/

  projects/
    spotify_display/
```

## Exercises

The `exercises/` directory contains small, focused ESP-IDF projects.

Each exercise should teach one specific concept.

The rule is:

> One exercise, one main topic.

Examples:

* task creation
* task delay
* task priority
* queue communication
* Wi-Fi connection
* HTTP server
* JSON response

The exercises are not meant to become the final application. They are learning steps.

## Projects

The `projects/` directory contains larger projects.

The main project will be:

```text
projects/spotify_display/
```

This project will reuse concepts learned in the exercises, but it should remain clean and not become a copy-paste dump of all experiments.

## Development Style

This repository follows an embedded-first approach.

Preferred style:

* simple and explicit code
* limited dynamic allocation
* small modules
* clear responsibility boundaries
* FreeRTOS used intentionally
* ESP-IDF code kept near infrastructure/adapters
* application logic kept as clean as possible

Avoid:

* unnecessary abstraction
* over-engineering
* desktop-style C++
* excessive use of heap allocation
* mixing business logic with hardware/framework code

## Architecture Direction

The final project should move toward hexagonal architecture.

In practice, this means:

* the application core should not directly depend on ESP-IDF APIs
* hardware and framework-specific code should stay in adapters
* Spotify API should be treated as an external adapter
* WebServer and physical display should be treated as presentation adapters
* the application should operate on its own internal models

Example future concepts:

* `PlaybackInfo`
* `DeviceStatus`
* `DisplayViewModel`
* `IPlaybackSource`
* `IStatusPresenter`
* `ITokenProvider`

The architecture will be introduced gradually, not all at once.

## Git Workflow

Each completed learning step should be committed separately.

Example commit messages:

```text
Add FreeRTOS two task delay exercise
Add FreeRTOS queue communication exercise
Add basic WiFi station exercise
Add basic HTTP server exercise
```

For now, the `main` branch is enough.

Feature branches may be used later for larger experiments or refactoring.

## Suggested Git Ignore Rules

The `build/` directory should not be committed.

Recommended `.gitignore` content:

```gitignore
build/
sdkconfig.old
.vscode/
.DS_Store
*.pyc
__pycache__/
```

The `sdkconfig` file should usually be committed because it contains project-specific ESP-IDF configuration.

## Learning Notes

Each exercise should include a short README with:

* goal
* what was tested
* observations
* conclusions
* possible next step

The goal is to build not only working code, but also a personal knowledge base.
