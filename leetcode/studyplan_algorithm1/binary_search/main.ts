export const binarySearch = (nums: number[], target: number): number => {
  let startIndex = 0;
  let endIndex = nums.length - 1;
  let midIndex = Math.floor((nums.length - 1) / 2);

  while (startIndex <= endIndex) {
    midIndex = Math.floor((startIndex + endIndex) / 2);
    if (target === nums[midIndex]) return midIndex;
    else if (target > nums[midIndex]) startIndex = midIndex + 1;
    else endIndex = midIndex - 1;
  }

  return -1;
};
