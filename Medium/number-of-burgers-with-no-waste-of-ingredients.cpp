// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
// Medium

class Solution {
public:
    vector<int> numOfBurgers(int tomato, int cheese) {
/**
    	Count		16		7
Jumbo		1		4		1		4*1		1		|| 	4(cheese - Y) + 2Y = tomato
Small	 	6		2		1		2*6		6		||	4*cheese - 2Y = tomato
														
                                                        Y = (4*cheese - tomato)/2
														X = cheese - Y
									---------
									16		7
**/
    	int Y = abs((4*cheese - tomato)/2);
    	int X = abs(cheese - Y);

    	if(4*X + 2*Y == tomato) return {X, Y};

    	return {};
    }
};