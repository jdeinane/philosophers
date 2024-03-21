# Philosophers

Welcome to my Philosophers Project repository! This project is part of the third circle of 42's common core.  

## Project Overview

In this simulation, we'll encounter a scenario where multiple philosophers are seated around a table, contemplating life's mysteries, and sharing a finite number of forks to eat their meal. The challenge lies in orchestrating their actions such that no philosopher is left starving, while also ensuring that they engage in a balanced cycle of eating, thinking, and sleeping. The project is divided into a mandatory part, focusing on thread management and mutexes, and an optional bonus part, which delves into process synchronization and semaphores.

### Key Concepts:

![The Dining Philosophers Problem](https://upload.wikimedia.org/wikipedia/commons/7/7b/An_illustration_of_the_dining_philosophers_problem.png)

This project will allow us to learn a lot of new concepts, functions and notions, such as:
- **Concurrency & Synchronization**: Understand and apply techniques to manage concurrent execution and synchronize shared resources.
- **Threads & Processes**: Explore the use of threads for the mandatory part and processes for the bonus part, each serving as a philosopher in the simulation.
- **Mutexes & Semaphores**: Implement mutexes to manage access to forks in the mandatory part and semaphores to control fork availability in the bonus part.

### Simulation Rules:

- Philosophers alternate between eating, thinking, and sleeping, requiring two forks to eat.
- A philosopher must eat before `time_to_die` milliseconds elapse; failure results in death and termination of the simulation.
- The simulation employs a no-starvation policy, ensuring each philosopher gets an opportunity to eat.
- Philosophers do not communicate directly, maintaining isolation in their actions.

This project not only challenges your technical abilities but also invites you to reflect on the philosophical underpinnings of sharing, competition, and survival. As you delve into the Philosophers Project, consider how the dilemmas faced by your digital philosophers mirror the complex interdependencies and shared resources in our own lives and systems.

## Getting Started

To get started with the Philosophers Project, follow these steps:

1. **Clone the Repository**: `git clone https://github.com/jdeinane/philosophers.git`
2. **Navigate to the Project**: `cd philo`
3. **Compile**: `make`
4. **And now, time for testing**: `ex: ./philo 4 310 200 100`
