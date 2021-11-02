.PHONY: test-ts test-go test-rust

test-ts:
	deno test 

test-go:
	go test .

test-rust:
	cargo test --bin reverse_string

test-all: test-ts test-go test-rust
