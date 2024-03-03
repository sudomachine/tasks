all: build

build: cmake
	cmake --build ./build/

cmake: build_dir
	cmake -S ./ -B ./build

build_dir:
	mkdir -p ./build

clean:
	rm -rf ./build