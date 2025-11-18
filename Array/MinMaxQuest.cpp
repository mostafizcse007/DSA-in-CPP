#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    map<int, int> mpp;
    multiset<pair<int, int>> track;

    while (q--)
    {
        int define;
        cin >> define;

        if (define == 1)
        {
            int val;
            cin >> val;
            if (mpp[val] > 0)
            {
                track.erase(track.find({mpp[val], val}));
            }
            mpp[val]++;
            track.insert({mpp[val], val});
        }
        else if (define == 2)
        {
            if (track.empty())
            {
                cout << "empty" << endl;
            }
            else
            {
                auto it = track.begin();
                int minmpp = it->first;
                auto range = track.equal_range({minmpp, INT_MAX});
                --range.second;
                int minEl = range.second->second;
                track.erase(range.second);
                int toRemove = max(1, minmpp / 2);
                mpp[minEl] -= toRemove;

                if (mpp[minEl] > 0)
                {
                    track.insert({mpp[minEl], minEl});
                }
                else
                {
                    mpp.erase(minEl);
                }

                cout << minEl << endl;
            }
        }
    }
    return 0;
}
