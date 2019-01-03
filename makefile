
default: TerminalMario

TerminalMario: 
	g++ Point.cpp Game.cpp FBuffer.cpp example/*.cpp -lpthread -o TerminalMario