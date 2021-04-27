CXX               := clang
CXXFLAGS          := -Wall -g
LDFLAGS           := -L/usr/lib -lstdc++ -lgmpxx -lgmp -I/usr/lib/
BUILD             := ./build
TARGET            := $(BUILD)/fibo-linux-x86_64
SRC               := main.cpp
ARCHIVE           := $(BUILD)/fibo-linux-x86_64.tar.xz
ARCHIVE_XX        := tar
ARCHIVE_FLAGS     := -cvJf

CXX_WIN           := i686-w64-mingw32-g++
LDFLAGS_WIN       := -L/usr/i686-w64-mingw32/sys-root/mingw/lib -lstdc++ -lgmpxx -lgmp -I/usr/i686-w64-mingw32/sys-root/mingw/include
TARGET_WIN        := $(BUILD)/fibo-windows-x86.exe
ARCHIVE_WIN       := $(BUILD)/fibo-windows-x86.zip
ARCHIVE_XX_WIN    := zip
ARCHIVE_FLAGS_WIN := -9

all:
	-@mkdir -p $(BUILD)
	-@$(CXX) $(LDFLAGS) $(CXXFLAGS) $(SRC) -o $(TARGET)
	-@$(CXX_WIN) $(CXXFLAGS) $(SRC) -o $(TARGET_WIN) $(LDFLAGS_WIN)
	-@$(ARCHIVE_XX) $(ARCHIVE_FLAGS) $(ARCHIVE) $(TARGET)
	-@$(ARCHIVE_XX_WIN) $(ARCHIVE_FLAGS_WIN) $(ARCHIVE_WIN) $(TARGET)

clean:
	-@rm -rvf $(BUILD)/*

info:
	-@echo "[*] Application dir: ${BUILD}     "
	-@echo "[*] Sources:         ${SRC}       "
	-@echo "[*] Out:             ${TARGET}    "
