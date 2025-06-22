#include "prepkitsday2.h"
#include "utils.h"
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

void PrepKitsDay2::exLonelyInteger()
{
  //ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split(rtrim(a_temp_temp));

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  int result = lonelyinteger(a);

  //fout << result << "\n";

  //fout.close();
}

int PrepKitsDay2::lonelyinteger(std::vector<int> a)
{
  int uniqueNum = 0;
  std::vector<int>::iterator it = a.begin();
  while (uniqueNum == 0) {
    if (count_if(a.begin(), a.end(), [it](int num) {return num == *it; }) == 1) {
      uniqueNum = *it;
      break;
    }
    it++;
  }

  cout << uniqueNum;
  return 0;

}

void PrepKitsDay2::exDiagonalDifference()
{
  //ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  vector<vector<int>> arr(n);

  for (int i = 0; i < n; i++) {
    arr[i].resize(n);

    string arr_row_temp_temp;
    getline(cin, arr_row_temp_temp);

    vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

    for (int j = 0; j < n; j++) {
      int arr_row_item = stoi(arr_row_temp[j]);

      arr[i][j] = arr_row_item;
    }
  }

  int result = diagonalDifference(arr);

  //fout << result << "\n";

  //fout.close();
}

int PrepKitsDay2::diagonalDifference(std::vector<std::vector<int>> arr)
{
  int trace = 0, rightDiagonal = 0;
  int arrSize = arr.size();

  for (int i = 0; i < arrSize; i++) {
    trace += arr[i][i];
    rightDiagonal += arr[i][arrSize - 1 - i];
  }


  cout << std::abs(trace-rightDiagonal);

  return std::abs(trace - rightDiagonal);
}


void PrepKitsDay2::exCountingSort1()
{
  //ofstream fout(getenv("OUTPUT_PATH"));

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

  vector<int> result = countingSort(arr);

  /*for (size_t i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << " ";
    }
  }*/

  //fout << "\n";

  //fout.close();

  //return 0;
}


std::vector<int> PrepKitsDay2::countingSort(std::vector<int> arr)
{
  std::vector<int> freqArray(100, 0);

  for (auto num : arr)
    freqArray[num]++;
  
  for (int i=0;i<100;i++)
    cout << freqArray[i];
  
  return freqArray;
}

void PrepKitsDay2::exTestFlipMatrix()
{
  //ofstream fout(getenv("OUTPUT_PATH"));

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> matrix(2 * n);

    for (int i = 0; i < 2 * n; i++) {
      matrix[i].resize(2 * n);

      string matrix_row_temp_temp;
      getline(cin, matrix_row_temp_temp);

      vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

      for (int j = 0; j < 2 * n; j++) {
        int matrix_row_item = stoi(matrix_row_temp[j]);

        matrix[i][j] = matrix_row_item;
      }
    }

    int result = flippingMatrix(matrix);

    //fout << result << "\n";
  }

  //fout.close();

  //return 0;
}

int PrepKitsDay2::flippingMatrix(std::vector<std::vector<int>> matrix)
{
  int sizeMat = matrix.size();
  int halfSize = sizeMat / 2;
  int maxSum = 0;

  for (int i = 0; i < halfSize; i++) {
    for (int j = 0; j < halfSize; j++) {

      maxSum += std::max({
        matrix[i][j],
        matrix[i][sizeMat - j - 1],
        matrix[sizeMat - i - 1][j],
        matrix[sizeMat - i - 1][sizeMat - j - 1],
        }
        );
    }
  }

  cout << maxSum;

  
  //int sizeMat = matrix.size();
  //std::vector<int> quads_sum = { 0, 0, 0, 0 };
  //int startRow = 0;
  //int startCol = 0;
  //int halfSize = sizeMat / 2;
  //int maxSum = -1;

  //while (maxSum == -1) {
  //  // Sum each quad
  //  for (int quad = 0; quad < sizeMat; quad++) {
  //    if (quad > halfSize) {
  //      startRow = halfSize;
  //      startCol = halfSize;
  //    }

  //    for (int row = startRow; row < halfSize; row++) {
  //      for (int col = startCol; col < halfSize; col++) {
  //        quads_sum[quad] += matrix[row][col];
  //      }
  //    }
  //  }

  //  // check if it's maximum
  //  int max_sum = *std::max_element(quads_sum.begin(), quads_sum.end());
  //  if (quads_sum[0] == max_sum)
  //    break;

  //  // check which quadrant was the maximum
  //  int max_quad = *std::find(quads_sum.begin(), quads_sum.end(), max_sum);



  //}

  


  //for (int i = 0; i < (sizeMat / 2); i++) {
  //  auto iteratorMax = std::max_element(matrix[i].begin(), matrix[i].end());
  //  if (iteratorMax == matrix[i].end()) {
  //    // Reverse
  //    for (int j = 0; j < (sizeMat/2); j++) {
  //      int aux = matrix[i][j];
  //      matrix[i][j] = matrix[i][sizeMat - j];
  //      matrix[i][sizeMat - j] = matrix[i][j];
  //    }
  //  }
  //}

  //int firstSum = 0;
  //int secondSum = 0;

  //for (int i = 0; i < sizeMat; i++) {

  //  for (int j = 0; j < sizeMat; j++) {
  //    if (j < (sizeMat / 2))
  //      firstSum += matrix[i][j];
  //    else
  //      secondSum += matrix[i][j];
  //  }

  //  if (firstSum < secondSum) {
  //    for (int j = 0; j < (sizeMat / 2); j++) {
  //      int aux = matrix[i][j];
  //      matrix[i][j] = matrix[i][sizeMat - j];
  //      matrix[i][sizeMat - j] = matrix[i][j];
  //    }
  //  }

  //  firstSum = 0;
  //  secondSum = 0;
  //}




  //// Sum quadrant
  //int totalSum = 0;

  //for (int i = 0; i < (sizeMat / 2); i++) {
  //  for (int j = 0; j < (sizeMat / 2); j++) {
  //    totalSum += matrix[i][j];
  //  }
  //}

  //cout << totalSum << endl;

  //for (int i = 0; i < (sizeMat); i++) {
  //  for (int j = 0; j < (sizeMat); j++) {
  //    cout << matrix[i][j] << "";
  //  }
  //}

  return 0;
}

