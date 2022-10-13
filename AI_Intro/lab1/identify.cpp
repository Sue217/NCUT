/**
 *    author: Jingbo Su
 *    created: April/14/2022 Thursday
**/
#include <iostream>
#include <iomanip>
#include <vector>

static constexpr int _SIZE_ = 23;
static constexpr int _COUNT_ = 77;

std::vector<std::string> features { "Have hair", "Have milk", "Have feather",
                                 "Can lay eggs", "Eat meat", "Have sharp teeth",
                                 "Have claws", "Eyes forward", "Have hooves",
                                 "Rumination", "Tawny", "Dark spots", "Black bars",
                                 "Long neck", "Long legs", "Can not fly",
                                 "Can fly", "Black and white", "Can swim",
                                 "Mammals", "Carnivores", "Ungulates", "Birds"
                               };

std::vector<std::string> answer { "Sorry, I don't know...",
                                  "It is Leopard.",
                                  "It is Tiger.",
                                  "It is Giraffe.",
                                  "It is Zebra.",
                                  "It is Ostrich.",
                                  "It is Penguin.",
                                  "It is Albatross.",
                                  "It is Mammals.",
                                  "It is Carnivores.",
                                  "It is Ungulates.",
                                  "It is Birds."
                                };

std::vector<std::string> status { 
                                  // Mammals
                                  "10000000000000000000000",
                                  "01000000000000000000000",
                                  "00000000000000000001000",
                                  "10000000000000000001000",
                                  "01000000000000000001000",
                                  // Birds
                                  "00100000000000000000000",
                                  "00010000000000001000000",
                                  "00000000000000000000001",
                                  "00100000000000000000001",
                                  "00010000000000001000001",
                                  // Carnivores
                                  "00001000000000000000000",
                                  "00000111000000000000000",
                                  "00000000000000000000100",
                                  // Ungulates
                                  "00000000100000000001000",
                                  "10000000100000000000000",
                                  "01000000100000000000000",
                                  "00000000010000000001000",
                                  "10000000010000000000000",
                                  "01000000010000000000000",
                                  "00000000000000000000010",
                                  "10000000100000000001000",
                                  "01000000010000000001000",
                                  // R9
                                  "10001000001100000000000",
                                  "10000111001100000000000",
                                  "10000000001100000000100",
                                  "01001000001100000000000",
                                  "01000111001100000000000",
                                  "01000000001100000000100",
                                  "00001000001100000001000",
                                  "00000111001100000001000",
                                  "00000000001100000001100",
                                  "10001000001100000001000",
                                  "01001000001100000001000",
                                  "10000111001100000001000",
                                  "01000111001100000001000",
                                  "10000000001100000001100",
                                  "01000000001100000001100",
                                  // R10
                                  "10001000001010000000000",
                                  "10000111001010000000000",
                                  "10000000001010000000100",
                                  "01001000001010000000000",
                                  "01000111001010000000000",
                                  "01000000001010000000100",
                                  "00001000001010000001000",
                                  "00000111001010000001000",
                                  "00000000001010000001100",
                                  "10001000001010000001000",
                                  "01001000001010000001000",
                                  "10000111001010000001000",
                                  "01000111001010000001000",
                                  "10000000001010000001100",
                                  "01000000001010000001100",
                                  // R11
                                  "00000000100101100001000",
                                  "10000000100101100000000",
                                  "01000000100101100000000",
                                  "00000000010101100001000",
                                  "10000000010101100000000",
                                  "01000000010101100000000",
                                  "00000000000101100000010",
                                  // R12
                                  "00000000100010000001000",
                                  "10000000100010000000000",
                                  "01000000100010000000000",
                                  "00000000010010000001000",
                                  "10000000010010000000000",
                                  "01000000010010000000000",
                                  "00000000000010000000010",
                                  // R13
                                  "00100000000001110100000",
                                  "00000000000001110100001",
                                  "00100000000001110100001",
                                  // R14
                                  "00100000000000010110000",
                                  "00000000000000010110001",
                                  "00100000000000010110001",
                                  // R15
                                  "00100000000000001000000",
                                  "00010000000000001000000",
                                  "00000000000000001000001",
                                  "00100000000000001000001",
                                  "00010000000000001000001",
                                };

int solve() {
  std::string in;
  std::string mask("00000000000000000000000");
  while (std::cin >> in, in != "END") {
    auto it = in.begin();
    bool ok = true;
    while (it != in.end()) {
      ++it;
      if (std::isalpha(*it)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      std::cout << "Invalid enter, please check the input!" << std::endl;
      continue;
    }
    int idx = std::stoi(in);
    --idx;
    if (0 <= idx && idx < _SIZE_) {
      mask[idx] = '1';
    } else {
      std::cout << "Invalid enter, please check the input!" << std::endl;
      continue;
    }
  }
  int pos = -1;
  for (int x = 0; x < _COUNT_; x++) {
    if (mask == status[x]) {
      pos = x;
      break;
    }
  }
  if (0 <= pos && pos < 5) return 8;
  if (5 <= pos && pos < 10) return 11;
  if (10 <= pos && pos < 13) return 9;
  if (13 <= pos && pos < 22) return 10;
  if (22 <= pos && pos < 37) return 1;
  if (37 <= pos && pos < 52) return 2;
  if (52 <= pos && pos < 59) return 3;
  if (59 <= pos && pos < 66) return 4;
  if (66 <= pos && pos < 69) return 5;
  if (69 <= pos && pos < 72) return 6;
  if (72 <= pos && pos < 77) return 7;
  return 0;
}

int main() {
  std::cout << "Choose feature(s) of the animal you want to identify:" << std::endl;
  std::cout << "And type `END` to stop entering." << std::endl << std::endl;
  for (int id = 0; id < _SIZE_; id++) {
    int out = id + 1;
    if (out >= 10) {
      std::cout << out << ". ";
    } else {
      std::cout << "0" + std::to_string(out) << ". ";
    }
    std::cout << std::left << std::setw(20) << rules[id] << " \n"[out % 3 == 0];
  }
  std::cout << std::endl;
  int idx = solve();
  std::cout << std::endl;
  std::cout << "My answer is:" << std::endl;
  std::cout << answer[idx] << std::endl;
  return 0;
}
