class Solution {
public:
    std::string fractionToDecimal(long long numerator, long long denominator) {
        if (!numerator)
            return "0";
		std::string str = numerator < 0 ^ denominator < 0 ? "-" : "";
        numerator = std::abs(numerator);
        denominator = std::abs(denominator);
        str += std::to_string(numerator / denominator);
        long long remainder = numerator % denominator;
        if (!remainder)
            return str;
		str += '.';
        std::unordered_map<int, int> flag;
		int pos = str.size();
        while (remainder && flag.find(remainder) == flag.end()) {
            flag[remainder] = pos++;
            str += '0' + remainder * 10 / denominator;
            remainder = remainder * 10 % denominator;
        }
        if (remainder) {
            str += ')';
            str.insert(str.begin() + flag[remainder], '(');
        }
        return str;
    }
};