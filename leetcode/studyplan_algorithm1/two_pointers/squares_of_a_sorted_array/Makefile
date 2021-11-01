.PHONY: test-ts test-go test-rust

test-ts:
	deno test 

test-go:
	go test .

test-rust:
	cargo test --bin squares_of_a_sorted_array

test-all: test-ts test-go test-rust
