CXX      := clang
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++
BUILD    := ./build
TARGET   := $(BUILD)/fibo
SRC      := main.cpp

all:
	-@mkdir -p $(BUILD)
	-@$(CXX) $(LDFLAGS) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	-@rm -rvf $(BUILD)/*

info:
	-@echo "[*] Application dir: ${BUILD}     "
	-@echo "[*] Sources:         ${SRC}       "
	-@echo "[*] Out:             ${TARGET}    "
