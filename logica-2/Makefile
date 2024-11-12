.MAIN: compile

compile:
	echo "[x] Compiling main.cpp..."
	mkdir -p build
	/usr/bin/clang++ -std=gnu++14 -fcolor-diagnostics -fansi-escape-codes -g main.cpp -o build/main

run:
	echo "[x] Running main..."
	./build/main

dev:
	make compile
	make run

test:
	echo "[x] Running tests..."
	/usr/bin/clang++ -std=gnu++14 -fcolor-diagnostics -fansi-escape-codes -g test.cpp -o build/test
	./build/test