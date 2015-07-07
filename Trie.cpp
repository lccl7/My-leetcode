class TrieNode
{
public:
    vector<TrieNode*> childNodes;
    int count;
    bool isword;
    char charNode;
    TrieNode():count(0),isword(false),charNode(' '){}
    TrieNode(char c):count(0),isword(false),charNode(c){}
    TrieNode* subNode(char c)
    {
        if(!childNodes.empty())
        for(auto node: childNodes)
        {
            if(node->charNode == c)
                return node;
        }
        return nullptr;
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    bool search(string word)
    {
        TrieNode* cur = root;
        for(auto c : word)
        {
            cur = cur->subNode(c);
            if(cur == nullptr)
                return false;
        }
        return cur->isword == true;
    }

    void insert(string word)
    {
        if(search(word)) return;
        TrieNode* cur = root;
        for(auto c : word)
        {
            TrieNode* child = cur->subNode(c);
            if(child != nullptr)
                cur = child;
            else {
                TrieNode* node = new TrieNode(c);
                cur->childNodes.push_back(node);
                cur = node;
            }
            cur->count++;
        }
        cur->isword = true;
    }

    bool startswith(string prefix)
    {
        TrieNode* cur = root;
        for(auto c : prefix)
        {
            cur = cur->subNode(c);
            if(cur == nullptr)
                return false;
        }
        return true;
    }
}
