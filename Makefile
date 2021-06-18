CXX = g++
BIN = umbral95
SRCS = $(shell find src -name *.cpp)
OBJS = $(SRCS:%=build/%.o)
DEPS = $(OBJS:.o=.d)
CFLAGS = -Iinclude -MMD -MP -O3 -std=c++17 -Wall -Wextra -pedantic
LIBS =

.PHONY: clean all run

all: build/$(BIN)

build/$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBS)

build/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf build

run: all
	./build/$(BIN)

-include $(DEPS)
