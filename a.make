# Makefile is created by Dev-CPP
CPP      = g++.exe
OBJ      = proj.o Category.o Transaction.o
LINKOBJ  = proj.o Category.o Transaction.o
LIBS     = -L"D:/Program Files (x86)/Dev-Cpp/MinGW64/lib" -L"D:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc
CXXINCS  = -I"D:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"D:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"D:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = proj.exe
CXXFLAGS = $(CXXINCS) 
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) budget.txt transaction.txt $(BIN)

run: proj
	proj.exe

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

proj.o: proj.cpp
	$(CPP) -c proj.cpp -o proj.o $(CXXFLAGS)

Category.o: Category.cpp
	$(CPP) -c Category.cpp -o Category.o $(CXXFLAGS)

Transaction.o: Transaction.cpp
	$(CPP) -c Transaction.cpp -o Transaction.o $(CXXFLAGS)