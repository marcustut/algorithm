// arrayEquals deep compare two given arrays.
const arrayEquals = (x: Array<unknown>, y: Array<unknown>): boolean => {
  if (x === y) return true;
  if (x.length !== y.length) return false;

  for (let i = 0; i < x.length; i++)
    if (x[i] !== y[i]) return false;

  return true;
}

// processStrings takes two string and process them.
export const processStrings = (first: string, second: string): [boolean, number, string] => {
  // check if both string will end up the same
  const isAnagram = arrayEquals(first.split('').sort(), second.split('').sort());

  // sum of both string's length
  const totalLength = first.length + second.length;

  // remove all duplicated char by converting it to a set
  const dedupedFirst = [...new Set(first)].join('')

  return [isAnagram, totalLength, dedupedFirst];
}
