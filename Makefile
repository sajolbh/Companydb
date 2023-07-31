CC = g++
CFLAGS = -std=c++11 -Wall

# Define the target executable
TARGET = companydb

# Define the source files
SRCS = companydb.cpp Company.cpp Employee.cpp Customer.cpp Purchase.cpp Person.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Define the rule to compile the source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Define clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
