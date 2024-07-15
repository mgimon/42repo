# About philosophers
Philosophers is an exercise designed to practice the creation of multiple threads to solve the classical problem of the philosophers.

Each philosopher should perform a routine consisting of various actions such as eating, thinking or sleeping, but they can only eat by effectively grabbing two objects called forks. This way, the program should be efficient enough to handle scenarios where different philosophers try to grab different forks, ensuring that no philosopher dies of hunger.

Executing the program:
```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> (optional)<minimum_number_of_meals_before_stop>
```
<br><br>

| Execution | Expected result |
| :--- | :--- |
| ./philo 1 800 200 200 | One philosopher should die |
| ./philo 5 800 200 200 | No philosopher should die |
| ./philo 5 800 200 200 7 | No philosopher should die, but simulation stops |
| ./philo 4 410 200 200 | No philosopher should die |
| ./philo 4 310 200 100 | One philosopher should die |

## 🟠 Compilation:
Execute
```
make
```

### 🔄 You may also like...
[-> My profile on the 42 Intranet](https://profile.intra.42.fr/users/mgimon-c)

[-> My LinkedIn profile](https://www.linkedin.com/in/mgimon-c/)



