all: assemble

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build: mkdir_build
	cd cmake-build-debug;cmake ..;make roguelike

exec:
	./cmake-build-debug/src/roguelike

clean:
	rm -rf cmake-build-debug

assemble: clean build

fast_build:
	cd cmake-build-debug;make roguelike

run: fast_build exec

osx_dep:
	brew install cmake cppcheck clang-format
	brew install ncurses spdlog
