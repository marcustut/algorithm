.PHONY: test-ts test-go test-rust

test-ts:
	deno test 

test-go:
	go test .

test-rust:
	cargo test --bin middle_of_the_linked_list

test-all: test-ts test-go test-rust
