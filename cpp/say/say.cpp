#include "say.h"
#include <iostream>
#include <map>
#include <vector>
#include <ranges>
#include <cctype>

using std::string;
using std::vector;



namespace say {
  string sub_twenty_pronounciation[] {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
  };

  string tens_pronounciation[] {
    "",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
  };

  string triplet_pronounciation[] {
    "",
    "thousand",
    "million",
    "billion",
    "trillion",
  };

  void basic_rtrim(string& input) {
    while (std::isspace(*(input.end() - 1))) {
      input.erase(input.end()-1);
    }
  }

  string get_two_digit_pronounciation(unsigned long long number) {
    unsigned short tens_digit = number / 10;
    unsigned short ones_digit = number % 10;

    if (number > 99) {
      throw;
    }

    if (number < 20) {
      return sub_twenty_pronounciation[number];
    }

    if (number % 10 == 0) {
      return tens_pronounciation[tens_digit];
    }

    return tens_pronounciation[tens_digit] + "-" + sub_twenty_pronounciation[ones_digit];
  }

  string get_three_digit_pronounciation(unsigned long long number) {
    unsigned short hundreds_digit = number / 100;

    if (number > 999) {
      throw;
    }

    if (hundreds_digit == 0) {
      return get_two_digit_pronounciation(number);
    }

    if (number % 100 == 0) {
      return sub_twenty_pronounciation[hundreds_digit] + " hundred";
    }

    return sub_twenty_pronounciation[hundreds_digit] + " hundred " + get_two_digit_pronounciation(number % 100);
  }

  string get_triplet_pronounciation(unsigned long long number) {
    if (number >= 1000) {
      throw;
    }

    if (number < 20) {
      return sub_twenty_pronounciation[number];
    }

    return get_three_digit_pronounciation(number);
  }

  string get_full_pronounciation(unsigned long long number) {
    vector<int> triplets {};
    string number_as_string {};

    if (number < 1000) {
      throw;
    }

    for (unsigned long long i = number; i > 0; i /= 1000) {
      triplets.insert(triplets.begin(), i % 1000);
    }

    unsigned int triplet_count = triplets.size();

    for (vector<int>::iterator it = triplets.begin(); it < triplets.end(); std::advance(it, 1)) {
      int triplet = *it;

      if (triplet == 0) {
        continue;
      }

      std::cout << "triplet: " << triplet << std::endl;

      string triplet_as_string = get_triplet_pronounciation(triplet);
      int triplet_index = std::distance(triplets.begin(), it);

      number_as_string.append(triplet_as_string + " " + triplet_pronounciation[triplet_count - triplet_index - 1
      ] + " ");
    }


    return number_as_string;
  }


  string in_english(long long number) {
    if (number < 0 || number >= 1000LL * 1000LL * 1000LL * 1000LL) {
      throw std::domain_error("Error");
    }

    if (number < 20) {
      return sub_twenty_pronounciation[number];
    }

    if (number < 1000) {
      return get_three_digit_pronounciation(number);
    }

    std::cout << "number: " << number << std::endl;

    string result = get_full_pronounciation(number);
    basic_rtrim(result);

    return result;
  }
} 
