output=$(g++ -o main main.cpp -std=c++17 -O2 -Wsign-compare -DONLINE_JUDGE -Wc++11-extensions -Werror=return-type)
if [[ $? == 0 ]]; then
  ./main< in1 >out1
  ./main< in2 >out2
  ./main< in3 >out3
  ./main< in4 >out4
  ./main< in5 >out5
fi
