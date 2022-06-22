import { argv } from "./process";

function factorial(number: number): number
{
    let index: number = number;
    let fat: number = 1;

    if (number > 1)
    {
        while (index > 0)
        {
            fat *= index;
            index--;
        }
    }

    return fat;
}

function main()
{
    const input: number = +argv[2];
    if (input) console.log(`The factorial of ${input} is ${factorial(input)}`);
}

main()