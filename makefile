
default: TerminalMario

TerminalMario: clean
	g++ Point.cpp Game.cpp FBuffer.cpp example/*.cpp -lpthread -lncursesw -o TerminalMario
clean:
	rm -rf TerminalMario
	rm -rf TerminalMario.exe