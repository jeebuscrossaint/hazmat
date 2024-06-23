CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -pedantic -I/usr/include/mysql
LDFLAGS = -L/usr/local/lib/mariadb -lmysqlclient -largon2

TARGET = password_manager
SRCS = main.cpp manager.cpp db.cpp crypto.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
