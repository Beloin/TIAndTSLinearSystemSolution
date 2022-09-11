# Retro substitution method to solve Linear Systems 

Input:
 - Augmented Matrix having Coefficients and independent terms

Output:
 - Return Type: (0) Determinate, (1) Undetermined, (2) Incompatible  
 - Dependent variables Matrix

*M Here is Unnecessary, since the Matrix are Rectangular*

```c
m = M.columns - 1 // Since we have augmented Matrix
n = M.rows 
Xs = array de M itens iniciados com 0
TIPO = 0
For i = n - 1, i == 0, i = i-1:
    sum = 0
    bi = M.at(i, m)
    aii = M.at(i, i)
    for j = i + 1, j == m-1:
        aij = M.at(i, j)
        xj = Xs[j]
        sum += aij * xj
    if aii == 0:
        if bi != sum:
            return 2, NULL
        else:
            TIPO = 1
            Xs[i] = 0
    Xs[i] = bi - sum / aii

return Xs, TIPO
```
