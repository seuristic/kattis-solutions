#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> date) {
  int pos = 0;
  int year = 0, month = 0, day = 0;
  for (int i = 0; i < 4; ++i) year = year * 10 + date[pos++];
  for (int i = 0; i < 2; ++i) month = month * 10 + date[pos++];
  for (int i = 0; i < 2; ++i) day = day * 10 + date[pos++];

  if (day == 0 || day > 31 || month == 0 || month > 12 || year < 2000) {
    return false;
  }

  bool is_leap = (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
  if (month == 2) {
    if (is_leap) {
      if (day > 29) return false;
    } else {
      if (day > 28) return false;
    }
  }

  // check month days
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
    return false;
  }

  return true;
}

int dateToInt(vector<int> date) {
  int date_int = 0;
  for (int i = 0; i < 8; ++i) {
    date_int = date_int * 10 + date[i];
  }
  return date_int;
}

string toDate(vector<int> date) {
  string date_str = "";
  for (int i = 6; i < 8; ++i) date_str += to_string(date[i]);
  date_str += ' ';
  for (int i = 4; i < 6; ++i) date_str += to_string(date[i]);
  date_str += ' ';
  for (int i = 0; i < 4; ++i) date_str += to_string(date[i]);
  return date_str;
}

void solve() {
  string dd, mm, yyyy;
  cin >> dd >> mm >> yyyy;
  vector<int> date(8);
  int pos = 0;
  for (char d : yyyy) date[pos++] = d - '0';
  for (char d : mm) date[pos++] = d - '0';
  for (char d : dd) date[pos++] = d - '0';

  sort(date.begin(), date.end());

  vector<int> early_date;
  int min_date_int = -1, count_valid_dates = 0;
  do {
    if (isValid(date)) {
      int date_int = dateToInt(date);
      if (min_date_int == -1 || min_date_int > date_int) {
        min_date_int = date_int;
        early_date = date;
      }
      ++count_valid_dates;
    }
  } while (next_permutation(date.begin(), date.end()));

  if (min_date_int == -1) cout << 0 << '\n';
  else cout << count_valid_dates << ' ' << toDate(early_date) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
