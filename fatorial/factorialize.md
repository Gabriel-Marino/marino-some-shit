```Ruby
def fact(num)
    fat = 1
    until num == 0 
        fat *= num
        num -= 1
    end
    fat
end
```

```Haskell
fact n = product [1..n]
```

```JavaScript
function fact(num)
{
    return new Array(num).fill(0).map((_, i) => i+1).reduce((num, fat) => fat *= num);
}
```

```Python
def fact(num):
    if num <= 1:
        return 1
    return num * fact(num - 1)
```