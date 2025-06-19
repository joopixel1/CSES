class TimeMap {
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {  
        if (!m.count(key)){
            map<int, string> s;
            m.insert( make_pair(key, s) );
        }
        m[key].insert( make_pair(timestamp, value) );
    }
    
    string get(string key, int timestamp) {
        if (m.count(key)){
            auto a = m[key].lower_bound( timestamp );
            if(a != m.end()) return (*a).second;
            else return "";
        }
        else return "";
    }

private:
    unordered_map< string, map<int, string> > m; 
};
