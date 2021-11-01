.PHONY: test-ts test-go test-rust

test-ts:
	deno test 

test-go:
	go test .

test-rust:
	cargo test --bin binary_search

test-all: test-ts test-go test-rust
