#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lonelyinteger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int lonelyinteger(vector<int> a) {
    // Initialize the result to 0. 
    // Any number XORed with 0 remains unchanged (X ^ 0 = X).
    int unique_element = 0;
    
    // Iterate through all elements in the vector.
    for (int num : a) {
        // Apply bitwise XOR operator (^).
        // Duplicate numbers will cancel each other out and become 0 (X ^ X = 0).
        // Consequently, only the element that appears once will remain.
        unique_element ^= num;
    }
    
    // Return the single unique integer that does not have a pair.
    return unique_element;
}


int lonelyinteger2(vector<int> a) {
    // Use a Hash Map (Frequency Table) to store the count of each number.
    // Key: the number itself, Value: how many times it appears.
    unordered_map<int, int> frequency_map;
    
    // Step 1: Record the frequency of each number in the array.
    for (int num : a) {
        frequency_map[num]++;
    }
    
    // Step 2: Traverse the map to find the element that appeared exactly once.
    for (const auto& pair : frequency_map) {
        // pair.first is the number, pair.second is its frequency count.
        if (pair.second == 1) {
            return pair.first; // Found the lonely integer.
        }
    }
    
    // Return -1 as a fallback if no unique element is found.
    return -1; 
}


int lonelyinteger3(vector<int> a) {
    int n = a.size();
    
    // Step 1: Find the number of unique elements (U) using a std::set.
    // std::set automatically removes duplicates.
    set<int> unique_elements(a.begin(), a.end());
    int u = unique_elements.size();
    
    // Edge case handling: If there's only 1 element or 1 kind of element
    if (n == 1) return a[0];
    if (u <= 1) return -1; 
    
    // Step 2: Automatically calculate 'k' using the mathematical formula.
    // Total elements (n) = k * (unique kinds (u) - 1) + 1
    int k = (n - 1) / (u - 1);

    // ----------------------------------------------------------------
    // Step 3: From here, it's the same bitwise logic you already know.
    // ----------------------------------------------------------------
    int result = 0;
    
    // Iterate through all 32 bits of an integer.
    for (int i = 0; i < 32; i++) {
        int bit_sum = 0;
        
        for (int num : a) {
            if ((num >> i) & 1) {
                bit_sum++;
            }
        }
        
        // Use the automatically found 'k' here.
        if (bit_sum % k != 0) {
            result |= (1 << i);
        }
    }
    
    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}

std::vector<string> split(const string &str)
{
    vector<string> tokens;
    string_view str_view(str);
    size_t start = 0;
    size_t end = 0;

    while ((end = str_view.find(' ', start)) != string_view::npos)
    {
        if (end > start)
        {
            tokens.emplace_back(str_view.substr(start, end - start));
        }
        start = end + 1;
    }

    if (start < str_view.size())
    {
        tokens.emplace_back(str_view.substr(start));
    }

    return tokens;
}
