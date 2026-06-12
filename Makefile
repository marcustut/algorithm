CXX=g++-15
CXXFLAGS=-Wall -Wextra -Wconversion -pedantic -std=c++23 -g

SRCS=$(NAME)
LIBS=-L/opt/homebrew/lib -lfmt
INCLUDES=-I/opt/homebrew/include

OUTPUT=a.out

deps:
	@brew install gcc
	@brew install fmt
	@brew install watchexec

dev: $(NAME)
	@watchexec -e cpp,in,txt make run

run:
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDES) $(LIBS) -o $(OUTPUT) 
	@./$(OUTPUT) < $(INPUT) 
	@rm $(OUTPUT) 
