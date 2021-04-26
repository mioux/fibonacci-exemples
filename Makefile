CXX               := clang
CXXFLAGS          := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS           := -L/usr/lib -lstdc++
BUILD             := ./build
TARGET            := $(BUILD)/fibo-linux-x86_64
SRC               := main.cpp
ARCHIVE           := $(BUILD)/fibo-linux-x86_64.tar.xz
ARCHIVE_XX        := tar
ARCHIVE_FLAGS     := -cvJf

CXX_WIN           := i686-w64-mingw32-g++
TARGET_WIN        := $(BUILD)/fibo-windows-x86.exe
ARCHIVE_WIN       := $(BUILD)/fibo-windows-x86.zip
ARCHIVE_XX_WIN    := zip
ARCHIVE_FLAGS_WIN := -9

all:
	-@mkdir -p $(BUILD)
	-@$(CXX) $(LDFLAGS) $(CXXFLAGS) $(SRC) -o $(TARGET)
	-@$(CXX_WIN) $(LDFLAGS) $(CXXFLAGS) $(SRC) -o $(TARGET_WIN)
	-@$(ARCHIVE_XX) $(ARCHIVE_FLAGS) $(ARCHIVE) $(TARGET)
	-@$(ARCHIVE_XX_WIN) $(ARCHIVE_FLAGS_WIN) $(ARCHIVE_WIN) $(TARGET)

clean:
	-@rm -rvf $(BUILD)/*

info:
	-@echo "[*] Application dir: ${BUILD}     "
	-@echo "[*] Sources:         ${SRC}       "
	-@echo "[*] Out:             ${TARGET}    "
