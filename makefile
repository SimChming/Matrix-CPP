CXX			:= g++
cxxFLAGS	:= -std=c++17 -Wall -Wextra -Iinclude -O2
LDFLAGS		:=
TARGET		:= build/app.exe

SRCS		:= 	$(wildcard src/*.cpp)
OBJS		:= $(SRCS:src/%.cpp=build/%.o)
