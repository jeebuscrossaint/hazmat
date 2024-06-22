CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -I/usr/local/include/mariadb
LDFLAGS = -L/usr/local/lib/mariadb -lmariadbcpp -largon2

TARGET = password_manager
SRCS = main.cpp manager.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
