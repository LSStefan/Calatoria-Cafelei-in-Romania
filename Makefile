# Numele executabilului
TARGET = cafenea

# Compilatorul folosit
CXX = g++

# Opțiuni de compilare (opțional, poți adăuga -Wall pentru mai multe avertismente)
CXXFLAGS = -std=c++17 -Wall -g

# Fișierele sursă
SRCS = main.cpp

# Fișierele obiect generate
OBJS = $(SRCS:.cpp=.o)

# Regula principală (default)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regula pentru generarea fișierelor obiect
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regula pentru curățare
clean:
	rm -f $(OBJS) $(TARGET)
