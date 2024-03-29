# philosophers

Implementation of the [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) using *threads*, *process*, *mutexes* and *semaphores* so that several programs can work on the same memory space. __(macOS)__

![Recordit GIF](https://github.com/trixky/philosophers/blob/master/.demo/demo.gif?raw=true)

| time in ms | philosopher id | action |

## Three programs

- `pilohopher_one` : There is a fork between each philosopher, *using threads and mutex.*
- `pilohopher_two` : All forks are in the middle of the table, *using threads and semaphore.*
- `pilohopher_three` : All forks are in the middle of the table, *using proce and semaphore.*

## Usage

```bash
make -C philo_one && make -C philo_two && make -C philo_three

# execute pilohopher_one
./philo_one/philosopher_one 6 2050 1000 1000

# execute pilohopher_two
./philo_two/philosopher_two 6 2050 1000 1000

# execute philosopher_three
./philo_three/philosopher_three 6 2050 1000 1000
```

## Arguments

> In that order.

- Number of philosophers and forks.
- Time it takes a philosopher to die after eating in ms.
- Time it takes a philosopher to eat.
- Time it takes a philosopher to sleep after eating.
- (optional) Stop dinner if each of the philosophers have eaten x times.

## Dining philosophers problem

In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them. It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise.
