clang++ -std=c++17  $(find . -name "*.cpp") $(find . -name "*.h")
./a.out
rm $(find . -name "*.gch") 