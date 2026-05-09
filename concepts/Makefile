CC = g++
CFLAGS = -fmodules -std=c++23 -Wall  -Werror -lstdc++
INCLUDE = -I include
OUTPUTDIR = build
SRC = $(shell find src -name "*.cpp")
OBJ = $(patsubst src/%.cpp, $(OUTPUTDIR)/%.o, $(SRC))

all: $(OUTPUTDIR)/main test

$(OUTPUTDIR)/main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $@

$(OUTPUTDIR)/%.o: src/%.cpp 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

-include $(OBJ:.o=.d)

$(OUTPUTDIR):
	mkdir -p $(OUTPUTDIR)


clean:
	rm -rf $(OUTPUTDIR)


