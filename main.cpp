#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef enum {
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	TWENTY = 11,
	THIRTY = 12,
	FORTY = 13,
	FIFTY = 14,
	SIXTY = 15,
	SEVENTY = 16,
	EIGHTY = 17,
	NINETY = 18,

} NUM_NAME_t;


std::map< NUM_NAME_t, std::string> numbers{
  {ONE, "one"},
  {TWO, "two"},
  {THREE, "three"},
  {FOUR, "four"},
  {FIVE, "five"},
  {SIX, "six"},
  {SEVEN, "seven"},
  {EIGHT, "eight"},
  {NINE, "nine"},
  {TEN, "ten"},
  {TWENTY, "twenty"},
  {THIRTY, "thirty"},
  {FORTY, "forty"},
  {FIFTY, "fifty"},
  {SIXTY, "sixty"},
  {SEVENTY, "seventy"},
  {EIGHTY, "eighty"},
  {NINETY, "ninety"},

};

std::vector<int> getNumOfDigits(long long num)
{
  std::vector<int> digits;
  while (num != 0)
  {
    digits.push_back(num % 10);
    num /= 10;
  }
  return digits;
}


void spellIt(long long num)
{
    if (num == 0) {
        std::cout << "zero";
        return;
    }

    std::vector<int> digits = getNumOfDigits(num);
    std::reverse(digits.begin(), digits.end()); // Reverse to process digits in correct order

    int count = digits.size();
    for (size_t i = 0; i < digits.size(); ++i) {
        NUM_NAME_t digit = static_cast<NUM_NAME_t>(digits[i]);

        if (digit != 0) {
            if ((count - i) % 3 == 2) { // Tens place
                std::cout << numbers[static_cast<NUM_NAME_t>(digit + 9)] << " ";
            } else {
                std::cout << numbers[digit] << " ";
                if ((count - i) % 3 == 0) { // Hundreds place
                    std::cout << "hundred ";
                }
                if ((count - i) == 4) {
                    std::cout << "thousand ";
                }
                if ((count - i) == 7) {
                    std::cout << "million ";
                }
                if ((count - i) == 10) {
                    std::cout << "billion ";
                }
            }
        }
    }
}

int main() {
	spellIt(23505);
}