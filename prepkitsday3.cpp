#include "prepkitsday3.h"
#include "utils.h"
#include <fstream>

using namespace std;

void PrepKitsDay3::exZigZagSequence()
{
  int n, x;
  int test_cases;
  std::cin >> test_cases;

  for (int cs = 1; cs <= test_cases; cs++) {
    std::cin >> n;
    vector < int > a;
    for (int i = 0; i < n; i++) {
      std::cin >> x;
      a.push_back(x);
    }
    findZigZagSequence(a, n);
  }
}

void PrepKitsDay3::findZigZagSequence(std::vector<int> a, int n)
{
  sort(a.begin(), a.end());
  int mid = n / 2;              // Modified
  swap(a[mid], a[n - 1]);

  int st = mid + 1;
  int ed = st + 1;
  while (a[st] <= a[ed] and ed <= (n - 1)) {
    swap(a[st], a[ed]);
    st = st + 1;
    ed = ed + 1;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

void PrepKitsDay3::exTowerBreakers()
{
  //ofstream fout(getenv("OUTPUT_PATH"));

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int result = towerBreakers(n, m);

    //fout << result << "\n";
  }

  //fout.close();

  //return 0;
}

int PrepKitsDay3::findMaxDivisor(int num)
{
  if (num % 2 == 0)
    return num / 2;
  
  for (int i = num / 2; i > 1; i--) {
    if (num % i == 0)
      return i;
  }
  return 1;
}

void PrepKitsDay3::exCaesarCipher()
{
  //ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string s;
  getline(cin, s);

  string k_temp;
  getline(cin, k_temp);

  int k = stoi(ltrim(rtrim(k_temp)));

  string result = caesarCipher(s, k);

  //fout << result << "\n";

  //fout.close();

  //return 0;
}

std::string PrepKitsDay3::caesarCipher(string s, int k)
{
  int maxLower = 122;
  int maxUpper = 90;
  int totalChars = 26;
  int charInt = 0;
  int maxVal = 0;
  int cipheredChar = 0;
  int convertedShifts = k % totalChars;

  std::string cipheredString = "";

  for (auto character : s) {
    charInt = static_cast<int>(character);                      // Convert the character to int

    if ((maxUpper - totalChars) < charInt && charInt <= maxUpper)         // Check if it's in the range of Upper Case 
      maxVal = maxUpper;
    else if ((maxLower - totalChars) < charInt && charInt <= maxLower)    // Check if it's in the range of Lower Case
      maxVal = maxLower;
    else {                                                      // Just append the character and move to the next one
      cipheredString += character;
      continue;
    }

    cipheredChar = charInt + convertedShifts;                                 // Add k offset and if it exceeds the maximum, subtract the max number of letters
    if (cipheredChar > maxVal)
      cipheredChar -= totalChars;

    cipheredString += static_cast<char>(cipheredChar);
  }

  cout << cipheredString;
  return cipheredString;
}

void PrepKitsDay3::exTestPalindrome()
{
  //ofstream fout(getenv("OUTPUT_PATH"));

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s;
    getline(cin, s);

    int result = palindromeIndex(s);

    //fout << result << "\n";
  }

  //fout.close();

  //return 0;
}

int PrepKitsDay3::palindromeIndex(std::string s)
{
  int lastChar = s.length() - 1;
  int stringHalfSize = (s.length() - 1) / 2;
  int removeChar = -1;
  int leftOffset = 0, rightOffset = 0;

  for (int i = 0; i < (stringHalfSize - leftOffset - rightOffset) ; i++) {
     
    if (s[i + leftOffset] == s[lastChar - rightOffset - i])
      continue;
    else if (removeChar != -1) {
      removeChar = -1;
      break;
    }

    if (s[i+ leftOffset] == s[lastChar - rightOffset - i - 1]) {
      removeChar = lastChar - i;
      rightOffset = 1;
      continue;
    }    
    
    if (s[i + leftOffset + 1] == s[lastChar - rightOffset - i]) {
      removeChar = i;
      leftOffset = 1;
      continue;
    }

    removeChar = -1;
    break;
  }


  cout << removeChar;
  return removeChar;
}

int PrepKitsDay3::towerBreakers(int n, int m)
{
  int winner = 0;
  
  if (m == 1) winner = 2;
  else if (n % 2 == 0)
    winner = 2;
  else
    winner = 1;


  
  //// Create n towers with height m
  //std::vector<int> towers(n, m);
  //int currentPlayer = 1;
  //int winner = 0;
  //int currentTower = 0;
  //int maxDiv = 0;
  //int piecesToRemove = 0;

  //// If there is only 1 tower, player 1 will win as they can automatically optimize it and remove all but one pieces
  //if (n == 1) winner = 1;

  //while (winner == 0) {

  //  maxDiv = findMaxDivisor(towers[currentTower]);
  //  piecesToRemove = towers[currentTower] - maxDiv;

  //  if (piecesToRemove <= 1) {
  //    winner = (currentPlayer == 1 ? 2 : 1);
  //    break;
  //  }

  //  towers[currentTower] -= piecesToRemove;

  //  currentTower = (currentTower == n - 1 ? 0 : currentTower + 1);
  //  currentPlayer = (currentPlayer == 1 ? 2 : 1);

  //}

  cout << winner;
  return winner;
}
