.PHONY: clean

BIN=./bin
SRC=./src
LLIB=$(SRC)/sieve_eratos.o
LIB=-lpthread
CXXFLAGS=-Ofast -std=gnu++17 -ftemplate-depth=1024

BINARIES=$(BIN)/euler001 \
			$(BIN)/euler002 \
			$(BIN)/euler003 \
			$(BIN)/euler004 \
			$(BIN)/euler005 \
			$(BIN)/euler006 \
			$(BIN)/euler007 \
			$(BIN)/euler008 \
			$(BIN)/euler009 \
			$(BIN)/euler010 \
			$(BIN)/euler011 \
			$(BIN)/euler012 \
			$(BIN)/euler013 \
			$(BIN)/euler014 \
			$(BIN)/euler015 \
			$(BIN)/euler016 \
			$(BIN)/euler017 \
			$(BIN)/euler018 \
			$(BIN)/euler019 \
			$(BIN)/euler020 \
			$(BIN)/euler021 \
			$(BIN)/euler022 \
			$(BIN)/euler023 \
			$(BIN)/euler024 \
			$(BIN)/euler025 \
			$(BIN)/euler026 \
			$(BIN)/euler027 \
			$(BIN)/euler028 \
			$(BIN)/euler029 \
			$(BIN)/euler030 \
			$(BIN)/euler031 \
			$(BIN)/euler032 \
			$(BIN)/euler033 \
			$(BIN)/euler034 \
			$(BIN)/euler035 \
			$(BIN)/euler036 \
			$(BIN)/euler037 \
			$(BIN)/euler038 \
			$(BIN)/euler039 \
			$(BIN)/euler040 \
			$(BIN)/euler041 \
			$(BIN)/euler042 \
			$(BIN)/euler043 \
			$(BIN)/euler044 \
			$(BIN)/euler045 \
			$(BIN)/euler046 \
			$(BIN)/euler047 \
			$(BIN)/euler048 \
			$(BIN)/euler049 \
			$(BIN)/euler055 \
			$(BIN)/euler056 \
			$(BIN)/euler057 \
			$(BIN)/euler058 \
			$(BIN)/euler059 \
			$(BIN)/euler060 \
			$(BIN)/multiple_24 \
			$(BIN)/unittest

all: $(BINARIES)

clean:
	rm -f $(BINARIES)

$(SRC)/sieve_eratos.o: $(SRC)/sieve_eratos.cpp $(SRC)/sieve_eratos.h

$(SRC)/euler007.o: $(SRC)/euler007.cpp $(SRC)/sieve_eratos.h

$(SRC)/euler010.o: $(SRC)/euler010.cpp $(SRC)/sieve_eratos.h

$(BIN)/euler007: $(SRC)/euler007.o $(SRC)/sieve_eratos.o
	$(CXX) $(CXXFLAGS) $< -o $@ $(LLIB)

$(BIN)/euler010: $(SRC)/euler010.o $(SRC)/sieve_eratos.o
	$(CXX) $(CXXFLAGS) $< -o $@ $(LLIB)

$(BIN)/multiple_24: $(SRC)/multiple_24.o $(SRC)/sieve_eratos.o
	$(CXX) $(CXXFLAGS) $< -o $@ $(LLIB)

TESTINC := $(wildcard $(SRC)/test_*.h)
SOLUSRC := $(wildcard $(SRC)/euler*.cpp)
$(SRC)/unittest.o: $(SRC)/unittest.cpp $(TESTINC) $(SRC)/sieve_eratos.h $(SRC)/simple_timer.h

$(BIN)/unittest: $(SRC)/unittest.o $(SRC)/unittest_euler059.o $(SRC)/unittest_euler060.o $(SRC)/sieve_eratos.o $(SRC)/catch_amalgamated.o
		$(CXX) $(CXXFLAGS) $^ -o $@ $(LIB)

$(SRC)/unittest_euler059.o: $(SRC)/euler059.cpp
	$(CXX) $(CXXFLAGS) -DUNITTEST_MODE -c -o $@ $<

$(SRC)/unittest_euler060.o: $(SRC)/euler060.cpp
	$(CXX) $(CXXFLAGS) -DUNITTEST_MODE -c -o $@ $<

$(BIN)/%:  $(SRC)/%.o $(SRC)/simple_timer.h
	$(CXX) $(CXXFLAGS) $< -o $@
