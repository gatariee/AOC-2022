import * as fs from 'fs';

function solve(data: string[]): number[] {
  const elfSums: number[] = [];
  let currentSum = 0;

  for (const item of data) {
    const trimmedItem = item.trim(); 

    if (trimmedItem === '') {
      elfSums.push(currentSum);
      currentSum = 0;
    } else {
      const parsedNumber = parseInt(trimmedItem, 10); 
      if (!isNaN(parsedNumber)) {
        currentSum += parsedNumber;
      }
    }
  }

  return elfSums;
}

fs.readFile('../input.txt', 'utf8', (err: NodeJS.ErrnoException | null, fileData: string) => {
  if (err) {
    console.error(err);
    return;
  }

  const data: string[] = fileData.split('\n');
  const list_of_sums: number[] = solve(data);
  console.log(Math.max(...list_of_sums));
});
