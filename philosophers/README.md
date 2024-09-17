# About philosophers
This project is an exercise designed to practice the creation and coordination of multiple threads to solve the classical problem of the philosophers. The threads should operate in an orderly manner (since accessing resources shared between threads might result in data races) and the code should make the process efficient enough so that no thread times out (philosopher dies of hunger).

Each philosopher should perform various actions such as eating, thinking, or sleeping, but they can only eat by successfully grabbing two objects called forks. The code should be able to handle scenarios where different philosophers try to grab different forks, ensuring that nobody starves.

The program might behave slightly differently in different OS.

<br>

## 🟠 Compilation:

Execute
```
make
```
<br>

## 🟠 Execution:
Executing the program:
```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> (optional)<minimum_number_of_meals_before_stop>
```
<br>

| Execution | Expected result |
| :--- | :--- |
| ./philo 1 800 200 200 | One philosopher should die |
| ./philo 5 800 200 200 | No philosopher should die |
| ./philo 5 800 200 200 7 | No philosopher should die, but simulation stops |
| ./philo 4 410 200 200 | No philosopher should die |
| ./philo 4 310 200 100 | One philosopher should die |

<br>

### 🔄 You may also like...
[-> My profile on the 42 Intranet](https://profile.intra.42.fr/users/mgimon-c)

[-> My LinkedIn profile](https://www.linkedin.com/in/mgimon-c/)



