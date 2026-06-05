#pragma once

#ifndef LEETCODE_GRINDING_LIST_NODE
#define LEETCODE_GRINDING_LIST_NODE

#include <ostream>
#include <cstddef>  // For std::ptrdiff_t

#include "helpers.hpp"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}

    static ListNode* make_list(initializer_list<int> l);
    
    struct BaseIterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;

        using value_type        = ListNode;
        using pointer           = ListNode*;  // or also value_type*
        using reference         = ListNode&;  // or also value_type&
    };

    struct Iterator : public ListNode::BaseIterator {

        explicit Iterator(pointer const ptr = nullptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer   operator->() { return m_ptr; }

        // Prefix increment
        Iterator& operator++() { m_ptr = m_ptr->next; return *this; }
            
        // Postfix increment
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const Iterator& a, const Iterator& b) 
        { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b)
        { return a.m_ptr != b.m_ptr; };

        private:
            pointer m_ptr; 
    };

    struct ConstIterator : public ListNode::BaseIterator {
        using pointer           = const ListNode*;  // or also value_type*
        using reference         = const ListNode&;  // or also value_type&

        explicit ConstIterator(pointer const ptr = nullptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }

        // Prefix increment
        ConstIterator& operator++() { 
            m_ptr = m_ptr->next; 
            return *this; 
        }

        // Postfix increment
        ConstIterator operator++(int) { 
            ConstIterator tmp = *this; 
            ++(*this); 
            return tmp;
        }

        friend bool operator== (const ConstIterator& a, const ConstIterator& b) 
        { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const ConstIterator& a, const ConstIterator& b)
        { return a.m_ptr != b.m_ptr; };

        private:
            const ListNode* m_ptr;
    };


         Iterator  begin()       noexcept { return Iterator{this};         }
    ConstIterator  begin() const noexcept { return ConstIterator{this};    }
    ConstIterator cbegin() const noexcept { return ConstIterator{this};    }
         Iterator  end  ()       noexcept { return      Iterator(nullptr); }
    ConstIterator  end  () const noexcept { return ConstIterator(nullptr); }
    ConstIterator cend  () const noexcept { return ConstIterator(nullptr); }
};
static_assert(std::ranges::range<ListNode>);

std::ostream& operator<<(std::ostream& out, const ListNode& listNode );


#endif 