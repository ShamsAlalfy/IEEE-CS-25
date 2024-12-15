#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Cow
{
    int start, end, coolingNeed;
};

struct AirConditioner
{
    int rangeStart, rangeEnd, coolingPower, operationCost;
};

void adjustCooling(vector<int>& coolingEffect, const AirConditioner& ac, bool activate)
{
    int coolingChange = activate ? ac.coolingPower : -ac.coolingPower;
    for (int i = ac.rangeStart; i <= ac.rangeEnd; i++)
    {
        coolingEffect[i] += coolingChange;
    }
}

bool allCowsSatisfied(const vector<Cow>& cowList, const vector<int>& coolingEffect)
{
    for (const auto& cow : cowList)
    {
        for (int i = cow.start; i <= cow.end; i++)
        {
            if (coolingEffect[i] < cow.coolingNeed)
                return false;
        }
    }
    return true;
}

void findMinimumCost(int currentAC, int currentCost, vector<int>& coolingEffect, const vector<Cow>& cowList, const vector<AirConditioner>& acList, int& minimumCost)
{
    if (currentAC == acList.size())
    {
        if (allCowsSatisfied(cowList, coolingEffect))
            minimumCost = min(minimumCost, currentCost);
        return;
    }
    findMinimumCost(currentAC + 1, currentCost, coolingEffect, cowList, acList, minimumCost);
    adjustCooling(coolingEffect, acList[currentAC], true);
    findMinimumCost(currentAC + 1, currentCost + acList[currentAC].operationCost, coolingEffect, cowList, acList, minimumCost);
    adjustCooling(coolingEffect, acList[currentAC], false);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Cow> cowList(n);
    for (int i = 0; i < n; i++)
        cin >> cowList[i].start >> cowList[i].end >> cowList[i].coolingNeed;
    vector<AirConditioner> acList(m);
    for (int i = 0; i < m; i++)
        cin >> acList[i].rangeStart >> acList[i].rangeEnd >> acList[i].coolingPower >> acList[i].operationCost;
    vector<int> coolingEffect(101, 0);
    int minCost = INT_MAX;
    findMinimumCost(0, 0, coolingEffect, cowList, acList, minCost);
    cout << minCost << "\n";
    return 0;
}
