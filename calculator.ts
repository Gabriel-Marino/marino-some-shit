function calculator (operationName: string, value1: number, value2: number)
{
    const opertions = {
        sum (value1: number, value2: number)
        {
            return value1 + value2;
        },
        sub (value1: number, value2: number)
        {
            return value1 - value2;
        },
        prod (value1: number, value2: number)
        {
            return value1 * value2;
        },
        div (value1: number, value2: number)
        {
            return value1 / value2;
        },
        pow (value1: number, value2: number)
        {
            return value1 ** value2;
        },
        nthroot (value1: number, value2: number)
        {
            return value1 ** (1/value2);
        }
    }

    const op = opertions[operationName];
    if (op) return op(value1, value2);
}
