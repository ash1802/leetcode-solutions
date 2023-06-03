// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
    TreeNode* buildTree(vector<int> nums, int start, int end) {
        if(start > end) return NULL;

        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums,start,mid-1);
        root->right = buildTree(nums,mid+1,end);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        TreeNode* root = buildTree(nums, 0, nums.size()-1);
        return root;
    }
};