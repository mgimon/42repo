# About pipex

Pipex is an exercise designed to practice the maintenance of multiple processes and their communication with one another in Unix-like systems. This requires the creation of pipes and the management of process outputs and inputs to these pipes, ensuring effective inter-process communication, particularly in error handling scenarios.

Executing the program:
```
./pipex infile.txt "command1" "command2" outfile.txt
```

Should do as the shell instruction:
```
< infile.txt command1 | command2 > outfile.txt
```

for example:
```
./pipex vehicles.txt "grep powerboat" "wc -w" outfile.txt
```

## 🟠 Compilation:
Execute
```
make
```

### 🔄 You may also like...
[-> My profile on the 42 Intranet](https://profile.intra.42.fr/users/mgimon-c)

[-> My LinkedIn profile](https://www.linkedin.com/in/mgimon-c/)



