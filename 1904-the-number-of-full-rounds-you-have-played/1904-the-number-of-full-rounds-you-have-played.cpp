class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int inhour = stoi(loginTime.substr(0,2)), inmin = stoi(loginTime.substr(3,2));
        int outhour = stoi(logoutTime.substr(0,2)), outmin = stoi(logoutTime.substr(3,2));
        int intime = inhour*60+inmin, outtime = outhour*60+outmin;
        int chess = 0;
        if(intime > outtime)
        {
            if(intime%15 != 0) intime += (15 - intime%15);
            if(outtime%15 != 0) outtime -= (outtime%15);
            int till12 = 1440-intime;
            int total = till12 + outtime;
            chess = total/15;
            return max(0,chess);
        }
        else{
            if(intime%15 != 0) intime += (15 - intime%15);
            if(outtime%15 != 0) outtime -= (outtime%15);
            int total = outtime - intime;
            chess = total/15;
            return max(0,chess);
        }
    }
};