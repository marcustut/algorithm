package studyplan_algorithm1

func binarySearch(nums []int, target int) int {
	startIndex := 0
	endIndex := len(nums) - 1
	var midIndex int

	for startIndex <= endIndex {
		midIndex = (startIndex + endIndex) / 2
		if target == nums[midIndex] {
			return midIndex
		} else if target > nums[midIndex] {
			startIndex = midIndex + 1
		} else {
			endIndex = midIndex - 1
		}
	}

	return -1
}
