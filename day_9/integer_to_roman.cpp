class Solution {
public:
    vector<pair<int, string>> symbols = {
        {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
        {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
        {500, "D"}, {900, "CM"}, {1000, "M"}};
    string intToRoman(int num) {
        int index = symbols.size() - 1;

        string result = "";
        while (index >= 0) {
            int value = symbols[index].first;
            string symbol = symbols[index].second;

            for (int i = 0; i < num / value; i++)
                result += symbol;
            num %= value;
            index--;
        }

        return result;
    }
};
