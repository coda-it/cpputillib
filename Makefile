all: 
	g++ main.cpp -o main

.PHONY: install
install:
	conan install .

.PHONY: test
test: 
	g++ -std=c++17 -I /System/Volumes/Data/Users/oszura/.conan/data/catch2/2.13.3/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/include/ test.cpp -o test
	./test
	rm test

.PHONY: fix
fix:
	clang-format -i -style=file *.cpp *.h

.PHONY: version
version:
	git tag $(V)
	./scripts/changelog.sh
	git add ./docs/changelogs/CHANGELOG_$(V).md
	./scripts/version.sh $(V)
	git add ./version.h
	git commit --allow-empty -m "Build $(V)"
	git tag --delete $(V)
	git tag $(V)	