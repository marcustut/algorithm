package studyplan_algorithm1

type firstBadVersion struct {
	n   int
	bad int
}

func (fbv *firstBadVersion) isBadVersion(version int) bool {
	return version >= fbv.bad
}

// simple linear search
// O(n)
func (fbv *firstBadVersion) firstBadVersionSlow() int {
	for i := 1; i < fbv.n+1; i++ {
		if fbv.isBadVersion(i) {
			return i
		}
	}
	return fbv.n
}

// binary search
// O(log n)
func (fbv *firstBadVersion) firstBadVersionFast() int {
	start := int64(1)
	end := int64(fbv.n)
	var result int

	for start <= end {
		mid := (start + end) / 2
		if fbv.isBadVersion(int(mid)) {
			end = mid - 1
			result = int(mid)
		} else {
			start = mid + 1
		}
	}

	return result
}
