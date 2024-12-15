#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

long long findMinDifference(vector<int>& weights, int index, long long group1Weight, long long totalWeight)
{
    if (index == weights.size())
        return abs((totalWeight - group1Weight) - group1Weight);

    return min(findMinDifference(weights, index + 1, group1Weight + weights[index], totalWeight),
        findMinDifference(weights, index + 1, group1Weight, totalWeight));
}

int main()
{
    int n;
    cin >> n;
    vector<int> weights(n);
    long long totalWeight = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
        totalWeight += weights[i];
    }
    cout << findMinDifference(weights, 0, 0, totalWeight) << endl;
    return 0;
}