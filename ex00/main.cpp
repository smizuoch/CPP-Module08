#include <iostream>    
#include <vector>    
#include <list>    
#include <deque> 
#include "easyfind.hpp" 

/* ************************************************************************** */
/*  値を格納して easyfind を試す汎用テスト関数                                */
/* ************************************************************************** */
template <typename Container>
void test(const std::string& name)
{
    std::cout << "---- " << name << " ----" << std::endl;

    Container c;

    // C++98 なので {} 初期化不可。push_back で値を投入
    for (int i = 1; i <= 5; ++i)
        c.push_back(i * 10); // 10 20 30 40 50

    try {
        /* 30 を検索して dereference で値を表示 */
        typename Container::iterator it = easyfind(c, 30);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        /* 存在しない 99 を検索 → 例外をキャッチ */
        easyfind(c, 99);
    }
    catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    /* 各種 STL コンテナで動作確認 */
    test< std::vector<int> >("std::vector");
    test< std::list<int>   >("std::list");
    test< std::deque<int>  >("std::deque");

    return 0;
}
