class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bank_set(bank.begin(), bank.end());
        
        if(!bank_set.count(end))
            return -1;
        
        queue<string> visit;
        visit.push(start);
        bank_set.insert(start);
        
        int sol = 0;
        while (!visit.empty()) {
            queue<string>::size_type q_sz = visit.size();
            
            for (auto i = 0; i < q_sz; ++i) {
                string gene = visit.front();
                visit.pop();
                
                if (gene.compare(end) == 0)
                    return sol;
                else {
                    bank_set.erase(gene);
                    for (auto j = 0; j < gene.length(); ++j) {
                        char c = gene[j];
                        for (auto ch : string{"ATCG"}) {
                            gene[j] = ch;
                            if (bank_set.count(gene)) {
                                visit.push(gene);
                                bank_set.erase(gene);
                            }
                        }
                        gene[j] = c;
                    }
                }
            }
            
            ++sol;
        }
        
        return -1;
        
    }
};
