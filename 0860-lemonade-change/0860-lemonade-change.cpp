class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;
        int fives = 1, tens = 0, twenties = 0;
        for(int i = 1;i<bills.size();i++)
        {
            if(bills[i] == 5)
                fives++;
            else if(bills[i] == 10)
            {
                if(fives > 0)
                {
                    fives--;
                    tens++;
                }
                else return false;
            }
            else{
                if(fives > 0 and tens > 0)
                {
                    fives--;
                    tens--;
                    twenties++;
                }
                else if(fives >= 3)
                    fives -= 3;
                else return false;
            }
        }
        return true;
    }
};