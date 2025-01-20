class Node{
public:
    Node* child[2];
    Node(){
        child[0] = child[1] = nullptr;
    }
};

int getMax(Node* head, int num){
    Node* curr = head;
    int res = 0;
    for(int i=31; i>=0; i--){
        int bit = (num>>i) & 1;

        if(curr->child[!bit]){
            res |= (1<<i);
            curr = curr->child[!bit];
        }
        else curr = curr->child[bit];
    }

    return res;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        
        Node* root = new Node();
        for(int num: nums){
            Node* curr = root;
            for(int i =31; i>=0; i--){
                int bit = (num >> i) & 1;
                if(!curr->child[bit]){
                    curr->child[bit] = new Node();
                }
                curr = curr->child[bit];
            }
        }

        int res = 0;

        for(int num: nums){
            res = max(res, getMax(root, num));
        }

        return res;
    }
};