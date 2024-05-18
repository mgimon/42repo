# About push_swap

Push_swap is a simple algorithmic project where you need to sort data. You have at your disposal a set of integer values, two stacks, and a set of instructions to manipulate both. Your goal is to use the minimum number of instructions possible.

This project is an introduction to efficiency and it teaches different approaches to sorting algorithms.

## 🟠 Operations


| Operations | Description |
| :--- | :--- |
| sa | swap a - swap the first two elements at the top of stack a. |
| sb | swap b - swap the first two elements at the top of stack b. |
| ss | swap a and swap b at the same time. |
| pa | push a - take the first element at the top of stack b and put it at the top of stack a. |
| pb | push b - take the first element at the top of stack a and put it at the top of stack b. |
| ra | rotate a - shift up all elements of stack a by one position. The first element becomes the last one. |
| rb | rotate b - shift up all elements of stack b by one position. The first element becomes the last one. |
| rr | ra and rb at the same time. |
| rra | reverse rotate a - shift down all elements of stack a by one position. The last element becomes the first one. |
| rrb | reverse rotate b - shift down all elements of stack b by one position. The last element becomes the first one. |
| rrr | rra and rrb at the same time. |

✅ 100 Numbers:

| Movements | Points |
| :---: | :---: |
| Less than 700 | 5 |
| Less than 900 | 4 |
| Less than 1100 | 3 |
| Less than 1300 | 2 |
| Less than 1500 | 1 |

✅ 500 Numbers: 

| Movements | Points |
| :---: | :---: |
| Less than 5500 | 5 |
| Less than 7000 | 4 |
| Less than 8500 | 3 |
| Less than 10000 | 2 |
| Less than 11500 | 1 |


## 🟠 Compilation and Testing


Execute: 

```
make
```

Then execute:
```
./push_swap value1 value2 ... value500
```

Or download multiple-input tester by gemartin99 (
`https://github.com/gemartin99/Push-Swap-Tester` )

And execute:
```
bash push_swap_test.sh
```

Note for this project:
5/5 (A* search algorithm)

##

### 🔄 You may also like...
[-> My profile on the 42 Intranet](https://profile.intra.42.fr/users/mgimon-c)

[-> My LinkedIn profile](https://www.linkedin.com/in/mgimon-c/)
