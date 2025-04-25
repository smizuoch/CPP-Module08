#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>     // std::stack
#include <deque>     // デフォルト内部コンテナ
#include <iterator>  // reverse_iterator 取得に必要

/* ************************************************************************** */
/*                             MutantStack クラステンプレート                  */
/*  - std::stack を public 継承し、protected メンバ c にアクセス               */
/*  - 4 種のイテレータ型を再エクスポート                                      */
/*  - begin()/end()/rbegin()/rend() を用意                                    */
/* ************************************************************************** */
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    /* ───────── 内部コンテナ型への別名 ───────── */
    typedef std::stack<T, Container>                     base_type;
    typedef typename base_type::container_type           container_type;

    /* ───────── 4 種のイテレータ型を公開 ──────── */
    typedef typename container_type::iterator            iterator;
    typedef typename container_type::const_iterator      const_iterator;
    typedef typename container_type::reverse_iterator    reverse_iterator;
    typedef typename container_type::const_reverse_iterator const_reverse_iterator;

    /* ───────── OCF（特別なメンバは base が実装済）───────── */
    MutantStack() : base_type() {}
    MutantStack(MutantStack const& other) : base_type(other) {}
    MutantStack& operator=(MutantStack const& other)
    {
        base_type::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    /* ───────── イテレータ取得関数 ───────── */
    iterator begin()                 { return this->c.begin(); }
    const_iterator begin() const     { return this->c.begin(); }
    iterator end()                   { return this->c.end(); }
    const_iterator end() const       { return this->c.end(); }

    reverse_iterator rbegin()                 { return this->c.rbegin(); }
    const_reverse_iterator rbegin() const     { return this->c.rbegin(); }
    reverse_iterator rend()                   { return this->c.rend(); }
    const_reverse_iterator rend() const       { return this->c.rend(); }
};

#endif /* MUTANTSTACK_HPP */
