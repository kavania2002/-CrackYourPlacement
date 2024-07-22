class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;

        stringstream ss(path);
        string current;
        while (ss && !ss.eof()) {
            getline(ss, current, '/');
            if (current == "..") {
                if (!paths.empty())
                    paths.pop_back();
            } 
            else if (!current.empty() && current != ".") paths.push_back(current); 
        }

        string result = "";
        for (string &x: paths) result += "/" + x;
        if (!result.empty()) return result;
        return "/";
    }
};
