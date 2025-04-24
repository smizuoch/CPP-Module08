#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <stdexcept> // std::runtime_error

/* ************************************************************************** */
/*  ■ easyfind                                                              */
/* -------------------------------------------------------------------------- */
/*  テンプレート引数 T には「int を要素とするコンテナ型」を想定。              */
/*  第 1 引数 : コンテナ (T&／T const&)                                       */
/*  第 2 引数 : 検索対象の int 値                                            */
/*  戻 り 値 : 要素が見つかった位置を指すイテレータ                           */
/*             （見つからなければ例外を送出）                                */
/* ************************************************************************** */
template <typename T> typename T::iterator easyfind(T &container, int value)
{
	/* std::find で先頭から末尾まで走査し，最初に一致したイテレータを取得 */
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	/* 見つからなかった場合は end() を返すので，ここで判定して例外を投げる */
	if (it == container.end())
		throw std::runtime_error("easyfind: value not found");

	return it; // 見つかったイテレータを呼び出し元へ返す
}

/* -------------------------------------------------------------------------- */
/*  const コンテナ用のオーバーロード                                          */
/* -------------------------------------------------------------------------- */
template <typename T> typename T::const_iterator easyfind(T const &container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("easyfind: value not found (const)");

	return it;
}

#endif // EASYFIND_HPP
