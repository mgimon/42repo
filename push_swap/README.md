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


## 🟠 Efficiency

<table>
  <tr>
    <td style="vertical-align: top;">
      <h4>✅ 100 Numbers:</h4>
      <table style="margin-right: 20px;">
        <thead>
          <tr>
            <th>Movements</th>
            <th>Points</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td>Less than 700</td>
            <td>5</td>
          </tr>
          <tr>
            <td>Less than 900</td>
            <td>4</td>
          </tr>
          <tr>
            <td>Less than 1100</td>
            <td>3</td>
          </tr>
          <tr>
            <td>Less than 1300</td>
            <td>2</td>
          </tr>
          <tr>
            <td>Less than 1500</td>
            <td>1</td>
          </tr>
        </tbody>
      </table>
    </td>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <td style="vertical-align: top;">
      <h4>✅ 500 Numbers:</h4>
      <table>
        <thead>
          <tr>
            <th>Movements</th>
            <th>Points</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td>Less than 5500</td>
            <td>5</td>
          </tr>
          <tr>
            <td>Less than 7000</td>
            <td>4</td>
          </tr>
          <tr>
            <td>Less than 8500</td>
            <td>3</td>
          </tr>
          <tr>
            <td>Less than 10000</td>
            <td>2</td>
          </tr>
          <tr>
            <td>Less than 11500</td>
            <td>1</td>
          </tr>
        </tbody>
      </table>
    </td>
  </tr>
</table>

<br>

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

Note for this project: ✅ 5/5 (A* search algorithm)

##

### 🔄 You may also like...
[-> My profile on the 42 Intranet](https://profile.intra.42.fr/users/mgimon-c)

[-> My LinkedIn profile](https://www.linkedin.com/in/mgimon-c/)
