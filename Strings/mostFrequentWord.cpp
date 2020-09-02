#include<iostream>
#include<map>
using namespace std;



struct trie {
	string key;
	int cnt;
	map<char,trie*> mp;
};

trie* getNewTrieNode()
{
	trie* node = new trie;
	node->cnt = 0;
	return node;
}

void insert(trie*& root, string &str)
{
	trie* temp = root;

	for(int i=0; i<str.length(); i++)
	{
		char x = str[i];
		if(!temp->mp.count(x))
			temp->mp[x] = getNewTrieNode();

		temp = temp->mp[x];
	}

	temp->key = str;
	temp->cnt += 1;
}

bool preorder(trie* temp, int &maxcnt, string &key)
{
	if(!temp)
		return false;

	for(auto it: temp->mp)
	{
		if(maxcnt < it.second->cnt)
		{
			key = it.second->key;
			maxcnt = it.second->cnt;
		}

		preorder(it.second,maxcnt,key);
	}
}


void mostFrequent(string arr[], int n)
{
	trie* root = getNewTrieNode();
	for(int i=0;i<n;i++)
		insert(root,arr[i]);

	string key;
	int cnt=0;
	preorder(root,cnt,key);

	cout<<"\nMost frequent word: "<<key<<" occuring: "<<cnt;
}





void hashing(string arr[], int n)
{
	map<string,int> mp;

	pair<string,int> maxval;
	maxval.first = "";
	maxval.second = INT_MIN;

	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
		if(mp[arr[i]] > maxval.second)
		{
			maxval.second = mp[arr[i]];
			maxval.first = arr[i];
		}
	}

	cout<<"\nMost Frequent string: "<<maxval.first<<" occuring: "<<maxval.second;

}



int main()
{
	string arr[] = {"geeks", "for", "geeks", "a", 
                "portal", "to", "learn", "can",
                "be", "computer", "science", 
                 "zoom", "yup", "fire", "in", 
                 "be", "data", "geeks"};
    int n = sizeof(arr)/sizeof(arr[0]);

    hashing(arr,n);

    return 0;
}