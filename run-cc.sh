# Bash script to run CodeChef programs (folders where there is in.txt and main.cpp)
g++ main.cpp -Wall --define DEBUG; if [ $? -eq 0 ]; then cat in.txt; printf "\n\n"; time ./a.out < in.txt; fi;