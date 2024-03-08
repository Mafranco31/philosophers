# Philosophers

The aim of the project is to understand the using of threads.

## Description

Philosophers is a simulation of philosophers around a table that have too survive by eating before they starve.

There is 1 fork by philosophers around the table, but each one needs 2 forks to eat.

A fork can be used by 1 philosopher at once, so they have to manage time to let the place to the others before they die.

## Installation

```bash
git clone https://github.com/Mafranco31/philosophers.git philosophers && cd philosophers && make
```

Now you can run the program !

## Utilisation

Run the program as follow :

./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat] (optional)

Example :

```bash
./philo 3 100 100 100 400
```
