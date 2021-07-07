
const int ALPHA_SIZE = 26;
struct trienode
{
    trienode* children[ALPHA_SIZE];
    bool end_of_word;
    trienode()
    {
        end_of_word = false;
        for(int i=0; i<ALPHA_SIZE; i++)
            children[i]=NULL;
    }
};
struct trienode* root = new trienode;

void insert(trienode* root, string key)
{
    trienode* pcrawl = root;
    for(int i=0; i<key.size(); i++)
    {
        int index = key[i]-'a';
        if(!pcrawl->children[index])
            pcrawl->children[index] = new trienode; 
        pcrawl = pcrawl->children[index];
    }
    pcrawl -> end_of_word = true;
}

bool search(trienode* root, string key)
{
    trienode* pcrawl = root;
    for(int i=0; i<key.size(); i++)
    {
        int index = key[i]-'a';
        if(!pcrawl->children[index])
            return false;
        pcrawl = pcrawl->children[index];
    }
    return pcrawl->end_of_word;
}

// For prefixes, don't use end_of_word