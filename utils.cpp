#include "utils.h"

using namespace std;

string ltrim(const string& str) {
  string s(str);

  s.erase(
    s.begin(),
    find_if(s.begin(), s.end(), [](unsigned char c) { return !isspace(c); })
  );

  return s;
}

string rtrim(const string& str) {
  string s(str);

  s.erase(
    find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !isspace(c); }).base(),
    s.end()
  );

  return s;
}

vector<string> split(const string& str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}