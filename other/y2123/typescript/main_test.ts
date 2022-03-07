import { strict as assert } from 'assert';
import { processStrings } from './main';

// testProcessStrings run test cases for the processStrings function
const testProcessStrings = () => {
  const tcs = [
    { input: { first: "anagram", second: "nagaram" }, output: [true, 14, "angrm"] },
    { input: { first: "angel", second: "leava" }, output: [false, 10, "angel"] },
    { input: { first: "car", second: "car" }, output: [true, 6, "car"] },
  ];

  tcs.forEach((tc, i) => {
    const [isAnagram, totalLength, dedupedFirst] = processStrings(tc.input.first, tc.input.second);
    assert(isAnagram === tc.output[0]);
    assert(totalLength === tc.output[1]);
    assert(dedupedFirst === tc.output[2]);
    console.log(`[PASSED] Testcase ${i+1}: ${JSON.stringify(tc, null, 2)}`);
  });
}

testProcessStrings();