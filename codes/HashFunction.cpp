/*
step1: (a + b + c) % d = (a % d + b % d + c % d) % d
step2: a^3 % d = ((((a % d) * a) % d) * a) % d
eg. 33^3 % 100 = 33 % 100 
                => (33 * 33) % 100 = (10 * 100 + 89) % 100 = 89
                => (89 * 33) % 100 = (29 * 100 + 37) % 100 = 37
*/
class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        int size = key.size();
        if (size == 0) return 0;
        
        long long hashcode = 0;
        vector<long long> codes(size + 1, 0);
        generateCodes(codes, HASH_SIZE);
        for (int i = 0; i < size; i++)  {
            hashcode += codes[size - i - 1] * key[i];
        }
        return hashcode % HASH_SIZE;
    }

    /*
    使用动态规划生成codes
    */
    void generateCodes(vector<long long> &codes, int HASH_SIZE) {
        long long code = 1;
        codes[0] = code;
        for (int i = 1; i < codes.size(); i++) {
            code = (code * 33) % HASH_SIZE;
            codes[i] = code;
        }
    }
};
