class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0, n1 = version1.size(), n2 = version2.size();
        while(i1 < n1 or i2 < n2)
        {
            int num1 = 0, num2 = 0;
            string curr1 = "";
            while(i1<n1 and version1[i1] != '.')
            {
                curr1 += version1[i1++];
            }
            while(i1 < n1 and version1[i1] == '.') i1++; //to skip .
            if(curr1 != "") num1 = stoi(curr1);
            curr1 = "";
            while(i2<n2 and version2[i2] != '.')
            {
                curr1 += version2[i2++];
            }
            while(i2<n2 and version2[i2] == '.') i2++; //to skip .
            if(curr1 != "") num2 = stoi(curr1);
            if(num1 < num2) return -1;
            else if(num1 > num2) return 1;
            else continue;
        }
        return 0;
    }
};