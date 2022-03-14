package main

import (
	"fmt"
)

func removeDuplicates(arr []int) []int {
  // initialize a hashmap
  hashmap := make(map[int]int)
  // a temporary slice to store unduplicated element
  temp := []int{}

  // loop through the arr
  for _, elem := range arr {
    // if elem not in hashmap
    if _, ok := hashmap[elem]; !ok {
      // insert it and the element to the slice
      hashmap[elem] += 1
      temp = append(temp, elem)
    }
  }

  return temp
}

func findMinAndMax(arr []int) (int, int) {
  min := arr[0]
  max := arr[0]

  for _, elem := range arr {
    if elem < min {
      min = elem
    } else if elem > max {
      max = elem
    }
  }
  
  return min, max
}

func main() {
  slice := []int{3,2,2,24,2,23,2,2,7,3,1,9,10,10,111,12,5,4,4,111,4,112,4}
  fmt.Printf("with duplicates: %+v\n", slice)
  fmt.Printf("without duplicates: %+v\n", removeDuplicates(slice))
  // fmt.Println(findMinAndMax([]int{1,10,3,4,7,-1,7,12,-11,1211}))
}

