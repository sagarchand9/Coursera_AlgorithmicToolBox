#include <bits/stdc++.h>

using namespace std;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    unordered_map<int, vector<string>> umap;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQueryNew(const Query& query) {
        vector<string> vtemp;
        if (query.type == "check") {
            vtemp = umap[query.ind];
            for(int i=0; i<vtemp.size(); i++)
                cout<<vtemp[i]<<" ";
            cout<<"\n";
        } else {            
            if (query.type == "find"){
                int hash = hash_func(query.s);
                vtemp = umap[hash];
                int flag=0;
                for(int i=0; i<vtemp.size(); i++){                
                    if(vtemp[i]==(query.s)){
                        flag++;
                        break;
                    }
                }

                if(flag==1)
                    cout<<"yes\n";
                else
                    cout<<"no\n";
            }                
            else if (query.type == "add") {
                int hash = hash_func(query.s);
                vtemp = umap[hash];
                reverse(vtemp.begin(), vtemp.end());
                int flag=0;
                for(int i=0; i<vtemp.size(); i++){                
                    if(vtemp[i]==(query.s)){
                        flag++;
                        break;
                    }
                }

                if(flag==0){
                    vtemp.push_back(query.s);
                    reverse(vtemp.begin(), vtemp.end());
                    umap[hash] = vtemp;
                }                

            } else if (query.type == "del") {
                int hash = hash_func(query.s);
                vtemp = umap[hash];
                int flag=0;
                int j;

                for(j=0; j<vtemp.size(); j++){                
                    if(vtemp[j]==(query.s)){
                        flag++;
                        break;
                    }
                }

                if(flag==1){
                    vtemp.erase(vtemp.begin()+j);
                    umap[hash] = vtemp;
                }

            }
        }
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                if (hash_func(elems[i]) == query.ind)
                    std::cout << elems[i] << " ";
            std::cout << "\n";
        } else {
            vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems.end());
            else if (query.type == "add") {
                if (it == elems.end())
                    elems.push_back(query.s);
            } else if (query.type == "del") {
                if (it != elems.end())
                    elems.erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQueryNew(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
