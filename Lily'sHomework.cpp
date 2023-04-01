#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

using namespace std;

int numofswap(vector<int> arr, vector<int> sorted) {
    unordered_map<int, int> indexes;
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        indexes[arr[i]] = i;
    }
    int swaps = 0;
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        if (arr[i] != sorted[i]) {
            int index = indexes[sorted[i]];
            swap(arr[i], arr[index]);
            swaps++;
            indexes[arr[i]] = i; // update index for arr[i]
            indexes[arr[index]] = index; // update index for arr[index]
        }
    }
    return swaps;
}

int lilysHomework(vector<int> arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    vector<int> arr_copy = arr; // make a copy of the original array
    int swapOrg = numofswap(arr_copy, sorted);

    vector<int> rev_sorted = arr;
    sort(rev_sorted.begin(), rev_sorted.end(), greater<int>());
    arr_copy = arr; // reset the copy of the original array
    int swapRev = numofswap(arr_copy, rev_sorted);

    return min(swapOrg, swapRev);
}




int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
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
