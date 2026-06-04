#include <iostream>
#include <vector>

#include "cpp_helpers/listNode.hpp"
#include "cpp_helpers/helpers.hpp"

ListNode* addTwoNumbers(
    const ListNode* l1, 
    const ListNode* l2
) {
    if (!l1 && !l2) return nullptr;

    ListNode* result = new ListNode;

    for (
        auto cur_node = result; 
        cur_node; 
        cur_node = cur_node->next
    ) {
        if (l1) { cur_node->val += l1->val; l1 = l1->next; } 
        if (l2) { cur_node->val += l2->val; l2 = l2->next; } 
    
        int remainder = cur_node->val / 10;
        if (l1 || l2 || remainder)
            cur_node->next = new ListNode(remainder);
        
        cur_node->val %= 10;
    }

    return result;
}

int main() {

    auto l1 = ListNode::make_list({2,4,3});
    auto l2 = ListNode::make_list({5,6,4});

    auto l3 = addTwoNumbers(l1, l2);

    print_container(*l3);


    return 0;
}