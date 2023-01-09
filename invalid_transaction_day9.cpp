class Solution {
public:
    struct CustomerDetail{
        string name;
        int time;
        int amount;
        string city;
    };
    CustomerDetail prepareCustomerObject(string s){
        vector<string>temp;
        string t;
        istringstream f(s);
        while(getline(f,t,',')){
            temp.push_back(t);
        }
        CustomerDetail obj =  CustomerDetail();
        obj.name=temp[0];
        obj.time=stoi(temp[1]);
        obj.amount=stoi(temp[2]);
        obj.city=temp[3];
        return obj;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<bool> invalid(transactions.size());
        vector<CustomerDetail> details;
        map<string/*name*/,vector<int>/*list of indexes*/> hashmap;
        int i=0;
        for(string s: transactions) {
            CustomerDetail obj = prepareCustomerObject(s);
            invalid[i]=obj.amount>1000;
        
            if(hashmap.find(obj.name) != hashmap.end()) {
                vector<int> indexes = hashmap[obj.name];
                
                for(int ind: indexes) {
                    if(details[ind].city != obj.city && abs(obj.time-details[ind].time)<= 60) {
                        invalid[ind]=true;
                        invalid[i]=true;
                    }
                }
            }
            hashmap[obj.name].push_back(i);
            details.push_back(obj);
            i++;
        }
        vector<string> ans;
        for(i=0;i<transactions.size();i++){
            if(invalid[i])
                ans.push_back(transactions[i]);
        }
        return ans;
    }
};