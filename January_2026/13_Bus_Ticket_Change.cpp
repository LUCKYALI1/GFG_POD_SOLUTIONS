class Solution {
  public:
    bool canServe(vector<int> &bills) {
      int count5 = 0, count10 = 0;

        for (int b : bills) {
            if (b == 5) {
                count5++;
            } 
            else if (b == 10) {
                if (count5 == 0) return false;
                count5--;
                count10++;
            } 
            else { // b == 20
                if (count10 > 0 && count5 > 0) {
                    // Give 10 + 5
                    count10--;
                    count5--;
                } 
                else if (count5 >= 3) {
                    // Give 5 + 5 + 5
                    count5 -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
