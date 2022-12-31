CXX=g++-12
CXXFLAGS=-Wall -Wextra -Werror -Wconversion -pedantic -std=c++20 -g

SRCS=$(NAME)
LIBS=-L/opt/homebrew/lib -lfmt
INCLUDES=-I/opt/homebrew/include

OUTPUT=a.out

deps:
	@brew install gcc@12
	@brew install fmt
	@brew install watchexec

dev: $(NAME)
	@watchexec -e cpp,in,txt make run

run:
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDES) $(LIBS) -o $(OUTPUT) && ./$(OUTPUT) < $(INPUT) && rm $(OUTPUT) && echo ""
