/**
 * Consider the first 25 digits in the decimal expansion of π (3,1,3,1,5,9,...).
 * If you randomly select a number, how likely are you to find each number?
 * What's the most likely digit?
 * What's the median?
 * What's the average value?
 * What's the standard deviation?
 * 
 * Desmos Graph: https://www.desmos.com/calculator/ne5r1gcm7i
 */
 (
    function()
    {
        const NUM_SAMPLES = 25;
        // const PI_DIGITS = 3.1415926535897932384626433832795028841971693993751058209749445923.toFixed(NUM_SAMPLES).match(/\d/g);
        const PI_DIGITS = "3141592653589793238462643".split("");
        const COUNT = [];
        PI_DIGITS.map(digit => {
            const INDEX = COUNT.findIndex(key => key[0] === digit);
            INDEX === -1 ? COUNT.push([digit, 1]) :  COUNT[INDEX][1] += 1;
        });
        COUNT.sort((a, b) => b[1] - a[1]);
        const MOST_LIKELY = COUNT[0];
        COUNT.sort((a, b) => a[0] - b[0])
        const MEDIAN = COUNT.map((digit, index, array) => {
            const LEFT = array.slice(0, index+1).reduce((acc, num) => acc + num[1]/NUM_SAMPLES, 0);
            const RIGHT = array.slice(index).reduce((acc, num) => acc + num[1]/NUM_SAMPLES, 0);
            if (LEFT >= 1/2 && RIGHT >= 1/2) return digit[0];
        }).filter(val => val);
        const       AVERAGE = COUNT.reduce((acc, num) => acc + (num[1]/NUM_SAMPLES)*Number(num[0]), 0);
        const SQUAREAVERAGE = COUNT.reduce((acc, num) => acc + (num[1]/NUM_SAMPLES)*Number(num[0])**2, 0);
        const STANDARD_DEVIATION = (SQUAREAVERAGE-AVERAGE**2)**(1/2);
        console.log(`Most likely digit: ${MOST_LIKELY[0]}\nMedian: ${MEDIAN}\nAverage: ${AVERAGE}\nStandard deviation: ${STANDARD_DEVIATION}`);
    }
)()