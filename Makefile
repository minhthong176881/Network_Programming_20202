CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

SRC		:= src

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system -lpthread -lsfml-network
EXECUTABLE	:= main


all: $(EXECUTABLE)

run: clean all
	clear
	./$(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cpp $(SRC)/network/*.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBRARIES)

clean:
	-rm ./$(EXECUTABLE)
