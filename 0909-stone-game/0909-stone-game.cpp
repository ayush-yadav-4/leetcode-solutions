class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

/*
For any case, Alex will win
because:
Firstly, we can divide the stones by their index(odd,even)
like 5,4,5,3
so the total value of stones with even index is : sumEven :5 + 5 = 10
the total value of stones with odd index is : sumOdd: 4 + 3

note"The total number of stones is odd, so there are no ties."
so sumEven will not be equal with sumOdd
Becase Alex chooses stone first
so if sumEven > sumOdd
then he can always choose stones with even index
if sumEven < sumOdd
then he can always choose stones with odd index
so, Alex will always win this game

we only need to return true.
*/