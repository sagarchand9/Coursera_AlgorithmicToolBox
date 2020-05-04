#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

int compute_hash( string s ){

}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

vector<int> get_occurrences_naive(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i) {
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    }
    return ans;
}

ll polyHash(const string& s, int prime, int x) {
    ll hash = 0;
    for (ll i = static_cast<ll> (s.size()) - 1; i >= 0; --i)
        hash = (hash * x + s[i]) % prime;
    return hash;
}

vector<ll> preComputeHashes(string text, int pL, int p, int x) {
    int tL = text.size();
    std::vector<ll> H(tL - pL + 1);
    string s = text.substr(tL - pL, pL);
    H[tL - pL] = polyHash(s, p, x);
    long long y = 1;
    for (int i = 1; i <= pL; ++i)
        y = y * x % p;
    for (int i = tL - pL - 1; i >= 0; --i) {
        long long preHash = x * H[i + 1] + text[i] - y * text[i + pL];
        while (preHash < 0) {
            preHash += p;
        }
        H[i] = preHash % p;
    }
    return H;
}

vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    int p = 1e9 + 7;
    int x = rand()%(p-1) + 1;

    ll pHash = polyHash(s, p, x);
    vector<ll> H = preComputeHashes(t, s.size(), p, x);
    for (size_t i = 0; i + s.size() <= t.size(); ++i) {
        if (pHash != H[i])
            continue;
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
