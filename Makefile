# Makefile
CXX = g++
CXXFLAGS = -Iinclude -std=c++17
SRC = src/main.cpp src/student.cpp src/admin.cpp
TARGET = student_app

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
