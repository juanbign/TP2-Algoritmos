programa.exe: *.cpp *.h
	g++ -g -Wall -std=c++98 *.cpp *.h -o programa.exe