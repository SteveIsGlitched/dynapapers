install: compile move

compile:
	g++ -I./ ./main.cpp -o dynapapers

move:
	cp dynapapers /usr/local/bin
