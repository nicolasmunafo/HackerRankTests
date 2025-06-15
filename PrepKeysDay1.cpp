#include "PrepKeysDay1.h"
#include "utils.h"
#include <fstream>

using namespace std;


void PrepKeysDay1::exPlusMinus(){
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  plusMinus(arr);
}

void PrepKeysDay1::plusMinus(vector<int> arr) {
  float pos = 0, neg = 0, zero = 0;
  int sizeArray = arr.size();

  for (int i : arr) {
    if (i > 0)
      pos++;
    else if (i < 0)
      neg++;
    else
      zero++;
  }
  printf("%.6f\n", pos / sizeArray);
  printf("%.6f\n", neg / sizeArray);
  printf("%.6f\n", zero / sizeArray);

}


void PrepKeysDay1::exMiniMaxSum()
{
  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(5);

  for (int i = 0; i < 5; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  miniMaxSum(arr);
}

void PrepKeysDay1::miniMaxSum(std::vector<int> arr)
{
  long long minSum = 0;
  long long maxSum = 0;
  
  sort(arr.begin(), arr.end());

  for (int i = 0; i < (arr.size()-1); i++) {
    minSum += static_cast<long long>(arr[i]);
    maxSum += static_cast<long long>(arr[i+1]);
  }

  cout << minSum << " " << maxSum;

}

void PrepKeysDay1::exTimeConversion()
{
  //ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = timeConversion(s);

  //fout << result << "\n";

  //fout.close();
}

std::string PrepKeysDay1::timeConversion(std::string s)
{
  string dayTime = s.substr(8, 2);
  string hourString = s.substr(0, 2);
  int hours = std::stoi(hourString);
  std::transform(dayTime.begin(), dayTime.end(), dayTime.begin(), [](unsigned char c) { return std::toupper(c); });
  s.erase(8, 2);
  
  if (hours == 12)
    hours = 0;

  if (dayTime == "PM")
    hours += 12;
  
  hourString = std::to_string(hours);
  if(hourString.length() == 1)
    hourString.insert(0,"0");

  s.replace(0, 2, hourString);

  cout << s;
  
  return s;
}
