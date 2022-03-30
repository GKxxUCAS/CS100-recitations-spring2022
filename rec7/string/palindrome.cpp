#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string s;
  std::getline(std::cin, s);
  int m;
  std::cin >> m;
  while (m--) {
    int q;
    std::cin >> q;
    if (q == 0) {
      int l, r;
      std::cin >> l >> r;
      bool ans = true;
      for (int i = l, j = r; i < j; ++i, --j) {
        while (!isalpha(s[i]) && i < j)
          ++i;
        while (!isalpha(s[j]) && i < j)
          --j;
        if (i >= j)
          break;
        if (toupper(s[i]) != toupper(s[j])) {
          ans = false;
          break;
        }
      }
      std::cout << (ans ? "Yes" : "No") << std::endl;
    } else if (q == 1) {
      int k;
      std::cin >> k;
      std::cin.ignore();
      std::cin.get(s[k]);
    } else {
      // q == 2
      std::cin.ignore();
      std::string tmp;
      std::getline(std::cin, tmp);
      s += tmp;
    }
  }
  return 0;
}