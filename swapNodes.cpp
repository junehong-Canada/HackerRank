#include <iostream>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */

class Node 
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }   
};

void printnode_inOrder(Node *root, vector<int> &result)
{
    if (root->data < 0)
        return;
    
    if (root->left != NULL)
        printnode_inOrder(root->left, result);
    cout << root->data << " ";
    result.push_back(root->data);
    if (root->right != NULL)
        printnode_inOrder(root->right, result);
}

void swap_k_depth(Node *node, int depth, int k)
{
    if (node == NULL)
    {
        return;
    }
    
    if (depth % k == 0)
    {
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    swap_k_depth(node->left, depth + 1, k);
    swap_k_depth(node->right, depth + 1, k);
}

vector<vector<int> > swapNodes(vector<vector<int> > indexes, vector<int> queries) 
{
    vector<vector<int> > result;
    Node root(1);
    Node *node = &root;
    queue<Node *> q;
    q.push(node);

    // for (auto i : indexes)
    for (int i = 0; i < indexes.size(); i++)
    {
        node = q.front();
        // for (auto j : i)
        for ( int j = 0; j < indexes[i].size(); j++)
        {
            // Node *nn = new Node(j);
            Node *nn = new Node(indexes[i][j]);
            if (node->left == NULL)
            {
                node->left = nn;
            }
            else
            {
                node->right = nn;
            }

            // if (j != -1)
            if (indexes[i][j] != -1)
                q.push(nn);
        }
        q.pop();
    }

    // for debugging
    // vector<int> temp_result;
    // printnode_preOrder(&root, temp_result);

    // for (auto k : queries)
    for (int k = 0; k < queries.size(); k++)
    {
        // swap_k_depth(&root, 1, k);
        swap_k_depth(&root, 1, queries[k]);
        vector<int> current_result;
        printnode_inOrder(&root, current_result);
        result.push_back(current_result);
    }
    
    return result;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int> > indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int> > result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j != result[i].size() - 1) {
                cout << " ";
            }
        }

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    // fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
