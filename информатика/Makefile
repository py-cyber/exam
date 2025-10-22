CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -pthread

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test
BIN_DIR = bin

MAIN_SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/HybridQuickSort.cpp
TEST_SRC = $(TEST_DIR)/test_quicksort.cpp $(SRC_DIR)/HybridQuickSort.cpp

MAIN_OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/HybridQuickSort.o
TEST_OBJ = $(OBJ_DIR)/test_quicksort.o $(OBJ_DIR)/HybridQuickSort.o

MAIN_EXE = $(BIN_DIR)/quicksort_demo
TEST_EXE = $(BIN_DIR)/quicksort_tests

all: $(MAIN_EXE) $(TEST_EXE)

$(MAIN_EXE): $(MAIN_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_EXE): $(TEST_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

debug: CXXFLAGS += -g -DDEBUG
debug: clean all

run: $(MAIN_EXE)
	./$(MAIN_EXE)

test: $(TEST_EXE)
	./$(TEST_EXE)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

rebuild: clean all

help:
	@echo "Доступные цели:"
	@echo "  all      - сборка всех программ (по умолчанию)"
	@echo "  debug    - отладочная сборка"
	@echo "  run      - запуск демо-программы"
	@echo "  test     - запуск тестов"
	@echo "  clean    - очистка сборочных файлов"
	@echo "  rebuild  - пересборка"
	@echo "  help     - эта справка"

.PHONY: all debug run test clean rebuild help
