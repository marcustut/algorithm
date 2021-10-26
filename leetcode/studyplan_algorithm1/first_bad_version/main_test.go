package studyplan_algorithm1

import (
	"testing"
)

func Test_firstBadVersion_isBadVersion(t *testing.T) {
	type fields struct {
		n   int
		bad int
	}
	type args struct {
		version int
	}
	tests := []struct {
		name   string
		fields fields
		args   args
		want   bool
	}{
		{
			name:   "test is bad version",
			fields: fields{n: 5, bad: 4},
			args:   args{version: 1},
			want:   false,
		},
		{
			name:   "test is bad version",
			fields: fields{n: 5, bad: 4},
			args:   args{version: 2},
			want:   false,
		},
		{
			name:   "test is bad version",
			fields: fields{n: 5, bad: 4},
			args:   args{version: 3},
			want:   false,
		},
		{
			name:   "test is bad version",
			fields: fields{n: 5, bad: 4},
			args:   args{version: 4},
			want:   true,
		},
		{
			name:   "test is bad version",
			fields: fields{n: 5, bad: 4},
			args:   args{version: 5},
			want:   true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			fbv := &firstBadVersion{
				n:   tt.fields.n,
				bad: tt.fields.bad,
			}
			if got := fbv.isBadVersion(tt.args.version); got != tt.want {
				t.Errorf("firstBadVersion.isBadVersion() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_firstBadVersion_firstBadVersionSlow(t *testing.T) {
	type fields struct {
		n   int
		bad int
	}
	tests := []struct {
		name   string
		fields fields
		want   int
	}{
		{
			name:   "test firstBadVersionSlow",
			fields: fields{n: 5, bad: 4},
			want:   4,
		},
		{
			name:   "test firstBadVersionSlow",
			fields: fields{n: 1, bad: 1},
			want:   1,
		},
		{
			name:   "test firstBadVersionSlow",
			fields: fields{n: 3, bad: 2},
			want:   2,
		},
		{
			name:   "test firstBadVersionSlow",
			fields: fields{n: 1926205968, bad: 1167880583},
			want:   1167880583,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			fbv := &firstBadVersion{
				n:   tt.fields.n,
				bad: tt.fields.bad,
			}
			if got := fbv.firstBadVersionSlow(); got != tt.want {
				t.Errorf("firstBadVersion.firstBadVersionSlow() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_firstBadVersion_firstBadVersionFast(t *testing.T) {
	type fields struct {
		n   int
		bad int
	}
	tests := []struct {
		name   string
		fields fields
		want   int
	}{
		{
			name:   "test firstBadVersionFast",
			fields: fields{n: 5, bad: 4},
			want:   4,
		},
		{
			name:   "test firstBadVersionFast",
			fields: fields{n: 1, bad: 1},
			want:   1,
		},
		{
			name:   "test firstBadVersionFast",
			fields: fields{n: 3, bad: 2},
			want:   2,
		},
		{
			name:   "test firstBadVersionFast",
			fields: fields{n: 1926205968, bad: 1167880583},
			want:   1167880583,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			fbv := &firstBadVersion{
				n:   tt.fields.n,
				bad: tt.fields.bad,
			}
			if got := fbv.firstBadVersionFast(); got != tt.want {
				t.Errorf("firstBadVersion.firstBadVersionFast() = %v, want %v", got, tt.want)
			}
		})
	}
}
