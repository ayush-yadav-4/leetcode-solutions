class Solution {
public:
    int minOperationsToFlip(string exp) {
        stack<pair<char,int>> s;
        char val1, val2, op; int cost1, cost2;;
        pair<char,int> p; //Here, p stores the value of the expression along with the cost to change the expression

        for(int i=0; i<exp.size(); i++){
            if(exp[i] == '(' || exp[i] == '&' || exp[i] == '|'){
                s.push({exp[i], 0}); //These exp. don't have any value and cost to change them is also 0.
            }
            else{
                if(exp[i] == ')'){
                    p = s.top();
                    s.pop();
                    s.pop();
                }
                else{
                    p = {exp[i], 1}; //When we encounter '0' or '1', Store the value which is '0' and '1' respectively and                  
					//cost to change there value is just 1.(change 0 to 1 and 1  to 0)
                }
                while(!s.empty() && (s.top().first == '&' || s.top().first == '|')){
                    op = s.top().first;
                    s.pop();
                    val2 = p.first;
                    cost2 = p.second;
                    val1 = s.top().first;
                    cost1 = s.top().second;
                    s.pop();

                    if(op == '&' && val1 == '1' && val2 == '1') p = {'1', min(cost1, cost2)};
                    if(op == '&' && val1 == '1' && val2 == '0') p = {'0', 1};
                    if(op == '&' && val1 == '0' && val2 == '1') p = {'0', 1};
                    if(op == '&' && val1 == '0' && val2 == '0') p = {'0', min(1 + cost1, 1 + cost2)};

					if(op == '|' && val1 == '1' && val2 == '1') p = {'1', min(1 + cost1, 1 + cost2)};
                    if(op == '|' && val1 == '1' && val2 == '0') p = {'1', 1};
                    if(op == '|' && val1 == '0' && val2 == '1') p = {'1', 1};
                    if(op == '|' && val1 == '0' && val2 == '0') p = {'0', min(cost1, cost2)};
                }
                s.push(p);
            }
        }
        return s.top().second;
    }
};