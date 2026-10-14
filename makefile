CXX			:= g++
cxxFLAGS	:= -std=c++17 -Wall -Wextra -Iinclude -O2
LDFLAGS		:=
TARGET		:= build/app.exe

SRCS		:= 	$(wildcard src/*.cpp)
OBJS		:= $(patsubst src/%.cpp, build/%.o, $(SRCS))