class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        
        for (string& op : operations) {
            if (op == "C") {
                record.pop_back();  // Remove last score
            } 
            else if (op == "D") {
                record.push_back(2 * record.back());  // Double last score
            } 
            else if (op == "+") {
                int last = record.back();
                int secondLast = record[record.size() - 2];
                record.push_back(last + secondLast);  // Sum of last two scores
            } 
            else {
                record.push_back(stoi(op));  // Convert string to int and add
            }
        }

        // Sum up all the valid scores
        return accumulate(record.begin(), record.end(), 0);
    }
};
