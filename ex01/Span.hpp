#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>       // 内部ストレージ用
#include <algorithm>    // sort, min_element, max_element
#include <iterator>     // distance
#include <stdexcept>    // 例外クラス
#include <climits>      // INT_MAX, INT_MIN

/* ************************************************************************** */
/*                                   Span                                     */
/*   - 最大 N 個の int を保持                                                 */
/*   - 追加・最短スパン・最長スパン計算が可能                                 */
/* ************************************************************************** */
class Span
{
public:
    /* ────────────── OCF: コンストラクタ / 代入 / デストラクタ ───────────── */
    explicit Span(unsigned int N);          // 最大要素数を受け取る
    Span(Span const& other);
    Span& operator=(Span const& other);
    ~Span();

    /* ────────────── 要素追加 ───────────── */
    void addNumber(int value);              // 単一要素を追加

    /* テンプレート: イテレータ範囲で複数追加
       - ヘッダ内に実装する必要がある（テンプレートのリンク問題回避）        */
    template <typename InputIt>
    void addNumber(InputIt first, InputIt last);

    /* ────────────── スパン計算 ───────────── */
    int shortestSpan() const;               // 最小差
    int longestSpan()  const;               // 最大差

private:
    std::vector<int> _data;                 // 実際の要素を保持
    unsigned int     _capacity;             // 最大保持数
};

/* ************************************************************************** */
/*                     テンプレート関数の実装（ヘッダ内）                      */
/* ************************************************************************** */
template <typename InputIt>
void Span::addNumber(InputIt first, InputIt last)
{
    /* 追加数と残りキャパシティを比較してオーバーフローを検出 */
    size_t distance_to_add = std::distance(first, last);
    if (_data.size() + distance_to_add > _capacity)
        throw std::runtime_error("Span: capacity exceeded (range insert)");

    /* 連続挿入を実行（vector::insert は一気にコピーしてくれる） */
    _data.insert(_data.end(), first, last);
}

#endif /* SPAN_HPP */
