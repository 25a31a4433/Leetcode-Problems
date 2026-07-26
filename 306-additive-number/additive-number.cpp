class Solution {
public:
    // Function to add two large numbers represented as strings
    string addStrings(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            res.push_back(char(sum % 10 + '0'));
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string a, string b, int start, string &num) {
        while (start < num.size()) {
            string sum = addStrings(a, b);

            if (num.substr(start, sum.size()) != sum)
                return false;

            start += sum.size();
            a = b;
            b = sum;
        }
        return true;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n / 2; i++) {
            if (num[0] == '0' && i > 1)
                break;

            for (int j = 1; max(i, j) <= n - i - j; j++) {
                if (num[i] == '0' && j > 1)
                    break;

                string first = num.substr(0, i);
                string second = num.substr(i, j);

                if (check(first, second, i + j, num))
                    return true;
            }
        }

        return false;
    }
};