#include "MutantStack.hpp"
#include <iostream>
#include <list>   // 動作比較用

/* ************************************************************************** */
/*                     PDF 例 (std::list と出力同一になる)                     */
/* ************************************************************************** */
static void pdf_like_demo()
{
    std::cout << "===== MutantStack demo =====" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "top(): " << mstack.top() << std::endl; // → 17

    mstack.pop();
    std::cout << "size(): " << mstack.size() << std::endl; // → 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    /* イテレータで走査 */
    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "forward iteration: ";
    for (; it != ite; ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    /* 逆順イテレータで走査 */
    std::cout << "reverse iteration: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
         rit != mstack.rend(); ++rit)
        std::cout << *rit << ' ';
    std::cout << std::endl;

    /* std::list で同じ動作を確認（出力は一致するはず） */
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "list forward      : ";
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
        std::cout << *lit << ' ';
    std::cout << std::endl;
}

/* ************************************************************************** */
int main()
{
    try
    {
        pdf_like_demo();
    }
    catch (std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
