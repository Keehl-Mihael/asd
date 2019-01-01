//
// Created by siroid on 12/31/18.
//

#ifndef TEST_BUILD_TREE_H
#define TEST_BUILD_TREE_H

template <class I,class N>
class tree{
public:

    typedef I item;
    typedef N node;

    virtual void create ()  = 0;
    virtual bool empty () const  = 0;
    virtual void insRoot (item) = 0 ;
    virtual node root () const = 0 ;
    virtual node parent (node) const  = 0;
    virtual bool leaf (node) const  = 0;
    virtual node firstChild (node) const  = 0;
    virtual bool lastSibling (node) const  = 0;
    virtual node nextSibling (node) const  = 0;
    virtual void removeSubTree (node)  = 0;

    virtual void insFirst(node, item) = 0;
    virtual void ins(node, item) = 0;

    virtual void writeNode (node, item)  = 0;
    virtual item readNode (node) const = 0 ;

    virtual void print(node n) const = 0;
};

#endif //TEST_BUILD_TREE_H
