/*
	Implemention of a Trie.
	Support '.' vague search, i.e. if word "melody" exists, then 
	search for "..lody" or "...ody" all will return true.
*/
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():c('\0'), isWord(false)
	{
		for(int i = 0; i < 26; ++i)
			next[i] = nullptr;
	}
	TrieNode(char _c, bool _isWord = false):c(_c), isWord(_isWord)
	{
		for(int i = 0; i < 26; ++i)
			next[i] = nullptr;
	}
	~TrieNode(){}
	
	bool hasChild(char _c)
	{
		return next[_c - 'a'] != nullptr;
	}
	
	void setCh(char _c)
	{
		c = _c;
	}
	
	void setBl(bool _isWord)
	{
		isWord = _isWord;
	}
	
	void set(char _c, bool _isWord)
	{
		c = _c;
		isWord = _isWord;
	}
	
	void giveBirth(char _c)
	{
		if(next[_c - 'a']) 
		{	
			next[_c - 'a']->setCh(_c);
			return;
		}
		next[_c - 'a'] = new TrieNode(_c);
	}
	
    bool isWord;
	char c;
	TrieNode *next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
	
	~Trie(){ destory(root); }

	void destory(TrieNode *root)
	{
		if(!root) return;
		for(int i = 0; i < 26; ++i)
		{
			if(root->next[i]) destory(root->next[i]);
		}
		delete root;
	}

    // Inserts a word into the trie.
    void addWord(string word) {
		TrieNode *tmp = root;
        for(auto &c : word)
		{
			if(!tmp->hasChild(c))
				tmp->giveBirth(c);
			tmp = tmp->next[c - 'a'];
		}
		tmp->setBl(true);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
		return search(word, root);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
		TrieNode *tmp = root;
        for(auto &c : prefix)
		{
			if(!tmp->hasChild(c)) return false;
			tmp = tmp->next[c - 'a'];
		}
		return true;
    }

private:
    TrieNode* root;
	
    bool search(string word, TrieNode *root) {
		if(!root) return false;
		TrieNode *tmp = root;
        for(int i = 0; i < word.size(); ++i)
		{
			if(word[i] == '.')
			{
				bool flag = false;
				for(int j = 0; j < 26; ++j)
				{
					flag = flag || search(word.substr(i+1), tmp->next[j]);
				}
				return flag;
			}
			else
			{
				if(!tmp->hasChild(word[i])) return false;
				tmp = tmp->next[word[i] - 'a'];
			}
		}
		return tmp->isWord;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

class TrieNode 
{
public:
    // Initialize your data structure here.
    bool isWord;
    vector<TrieNode *> next;
    TrieNode():isWord(false), next(26, nullptr){}
};

class Trie2
{
public:
    Trie() 
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
        TrieNode *t = root;
        for(auto &c : word)
        {
            if(!t->next[c - 'a']) t->next[c - 'a'] = new TrieNode();
            t = t->next[c - 'a'];
        }
        t->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) 
    {
        TrieNode *t = root;
        for(auto &c : word)
        {
            if(!t->next[c- 'a']) return false;
            t = t->next[c - 'a'];
        }
        return t->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
    {
        TrieNode *t = root;
        for(auto &c : prefix)
        {
            if(!t->next[c - 'a']) return false;
            t = t->next[c - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};