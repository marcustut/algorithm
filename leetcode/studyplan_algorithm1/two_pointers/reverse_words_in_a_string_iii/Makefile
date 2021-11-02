.PHONY: test-ts test-go test-rust

test-ts:
	deno test 

test-go:
	go test .

test-rust:
	cargo test --bin reverse_words_in_a_string_iii

test-all: test-ts test-go test-rust
