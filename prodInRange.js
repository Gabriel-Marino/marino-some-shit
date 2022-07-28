function prod(arr)
{
	const [lesser, bigger] = arr.slice().sort((a, b) => a - b);
	const [bigp1, map2index, notFalsy] = [bigger + 1, (_, i) => i, val => val];
	const range = new Array(bigp1).fill(0, lesser, bigp1).map(map2index).filter(notFalsy);
	return range.reduce((acc, num) => acc * num, 1);
}
