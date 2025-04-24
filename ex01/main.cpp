#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

/* ************************************************************************** */
/*                         使い方デモ（公式 PDF の例）                          */
/* ************************************************************************** */
static void pdf_example()
{
    std::cout << "===== PDF sample =====" << std::endl;

    Span sp(5);              // 最大 5 要素

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl; // → 2
    std::cout << sp.longestSpan()  << std::endl; // → 14
}

/* ************************************************************************** */
/*                     1 万件ランダムデータでストレステスト                    */
/* ************************************************************************** */
static void stress_test()
{
    std::cout << "\n===== Stress test (10,000 numbers) =====" << std::endl;

    const unsigned int N = 10000;
    Span sp(N);

    /* 乱数シードを初期化（C++98 なので <random> は使えない） */
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (unsigned int i = 0; i < N; ++i)
        sp.addNumber(std::rand());

    std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span  : " << sp.longestSpan()  << std::endl;
}

/* ************************************************************************** */
int main()
{
    try
    {
        pdf_example();
        stress_test();

        /* ────────── イテレータ範囲挿入の例 ────────── */
        std::cout << "\n===== Range insert demo =====" << std::endl;
        std::vector<int> values;
        for (int i = 1; i <= 10; ++i)
            values.push_back(i * 100);

        Span sp2(15);
        /* 一括挿入：vector の begin/end を渡す */
        sp2.addNumber(values.begin(), values.end());
        sp2.addNumber(50);    // 単体追加も可能

        std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span  : " << sp2.longestSpan()  << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
