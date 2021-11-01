.PHONY: test-ts test-go test-rust

test-ts:
	deno test 

test-go:
	go test .

test-rust:
	cargo test --bin search_insert_position

test-all: test-ts test-go test-rust
