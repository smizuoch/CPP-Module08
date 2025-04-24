#include "Span.hpp"

/* ************************************************************************** */
/*                         コンストラクタ / デストラクタ                       */
/* ************************************************************************** */
Span::Span(unsigned int N)
    : _data()          // 空ベクタ
    , _capacity(N)
{
    _data.reserve(N);  // N 個分のメモリを事前確保（再確保コスト削減）
}

Span::Span(Span const& other)
    : _data(other._data)
    , _capacity(other._capacity)
{}

Span& Span::operator=(Span const& other)
{
    if (this != &other)
    {
        _data      = other._data;
        _capacity  = other._capacity;
    }
    return *this;
}

Span::~Span() {}

/* ************************************************************************** */
/*                                 要素追加                                   */
/* ************************************************************************** */
void Span::addNumber(int value)
{
    if (_data.size() >= _capacity)
        throw std::runtime_error("Span: capacity exceeded (single insert)");

    _data.push_back(value);
}

/* ************************************************************************** */
/*                               最短スパン計算                                */
/*   1) 要素数チェック → 例外                                                 */
/*   2) コピーをソートし、隣接ペア差分の最小値を走査                           */
/* ************************************************************************** */
int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Span: not enough elements for span");

    /* コピーしてソート（元データは順序保持） */
    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());

    int min_span = INT_MAX;
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < min_span)
            min_span = diff;
    }
    return min_span;
}

/* ************************************************************************** */
/*                               最長スパン計算                                */
/*   - 最小値と最大値の差を返すだけ → O(N)                                     */
/* ************************************************************************** */
int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Span: not enough elements for span");

    int min_val = *std::min_element(_data.begin(), _data.end());
    int max_val = *std::max_element(_data.begin(), _data.end());

    return max_val - min_val;
}
