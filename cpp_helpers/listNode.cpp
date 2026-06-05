#include "listNode.hpp"

using std::ostream;


ListNode* ListNode::make_list(initializer_list<int> l) {
    size_t sz = l.size();
    if (sz == 0) return nullptr;
    
    ListNode* result = new ListNode[sz];
    for (size_t i = 0; i < sz - 1; ++i) {
        result[i].val = *(l.begin() + i);
        result[i].next = &result[i + 1];
    }

    result[sz - 1].val = *(l.begin() + sz - 1);

    return result;
}

ostream& operator<<(ostream& out, const ListNode& listNode ) {
    return out << "{type: ListNode, val: " << listNode.val << "}"; 
}