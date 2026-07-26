/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void dfsSerial(TreeNode* node, vector<string>& res) {
        if(!node)
        {
            res.push_back("N");
            return ;
        }
        res.push_back(to_string(node->val));
        dfsSerial(node->left, res);
        dfsSerial(node->right, res);
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto &i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }
        return s.str();
    }

    TreeNode* dfsDeserial(vector<string>& data, int& i) {
        if(data[i] == "N")
        {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(data[i]));
        i++;
        node->left = dfsDeserial(data, i);
        node->right = dfsDeserial(data, i);
        return node;
    }

    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerial(root, res);
        return join(res,",");
    }

    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfsDeserial(vals, i);
    }
};
