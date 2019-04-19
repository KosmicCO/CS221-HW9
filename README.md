# CS221-HW9: The Traveling Salesperson Problem
---
### Chapter 1: Random Search

#### Compiling
Compiling should be standard.
#### Running tsv
tsv takes two arguments:
`./tsv [file] [tests]`
- `[file]` is a file from which to pull the point data 
- `[tests]` is the number of tests to run with the given file, setting tests to `-1` runs forever
#### Design Choices
I decided to mostly use the constructor from an istream istead of `>>` to ensure that `Cities` was immutable in the code. Everything else is mostly standard.
