
default: TerminalMario

TerminalMario: clean
	g++ Point.cpp EndChar.cpp Game.cpp FBuffer.cpp test/*.cpp -lpthread -lncursesw -o TerminalMario
clean:
	rm -rf TerminalMario
	rm -rf TerminalMario.exe
