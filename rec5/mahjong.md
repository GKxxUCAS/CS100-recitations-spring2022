```pseudocode
bool check_sets(hand, want) {
  if (want == 0)
    return true;
  for i from 0 to 3 * want - 1
    for j from i + 1 to 3 * want - 1
      for k from j + 1 to 3 * want - 1
        if (is_chow(hand[i], hand[j], hand[k]) or is_pung(hand[i], hand[j], hand[k])) {
          rest = The mahjong-hand obtained from hand by removing the i-th, j-th and k-th tiles.
          if (check_sets(rest, want - 1))
            return true;
        }
  return false;
}
bool check_win(hand) {
  for i from 0 to 13
    for j from i + 1 to 13
      if (hand[i] == hand[j]) {  // a pair
        rest = The mahjong-hand obtained from hand by removing the i-th and j-th tiles.
        if (check_sets(rest, 4))
          return true;
      }
  return false;
}
```
