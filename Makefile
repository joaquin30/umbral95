CXX = g++
BIN = "umbral95"
SRCS = $(shell find src -name *.cpp)
OBJS = $(SRCS:%=build/%.o)
DEPS = $(OBJS:.o=.d)
CFLAGS = -Iinclude -MMD -MP -O3 -std=c++11 -Wall -Wextra -pedantic
LDFLAGS = -lm

all: build/$(BIN)

build/$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

build/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf build

-include $(DEPS)
