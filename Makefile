CXX = g++
BIN = umbral95
SRCS = $(shell find src -name *.cpp)
OBJS = $(SRCS:%=build/%.o)
DEPS = $(OBJS:.o=.d)
CFLAGS = -Iinclude -MMD -MP -O3 -std=c++11 -Wall -Wextra -pedantic
LIBS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_gfx -lSDL2_net

.PHONY: clean all

all: build/$(BIN)

build/$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBS)

build/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf build

-include $(DEPS)
