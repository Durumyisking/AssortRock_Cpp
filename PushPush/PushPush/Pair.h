#pragma once
#include "Common.h"

// key type, value type
template<typename T1, typename T2>
class CPair
{
	CPair()
		: first(T1())
		, second(T2())
	{
	}
	CPair(T1& _first, T2& _second)
		: first(_first)
		, second(_second)
	{
	}
	// �̵� ����
	template<typename U1, typename U2>
	CPair(U1&& _first, U2&& _second)
		: first(forward<U1>(_first))
		, second(forward<U2>(_second))
	{
	}

	template<typename U1, typename U2>
	CPair(const pair<U1, U2>& _other)
		: first(_other.first)
		, second(_other.second)
	{
	}
	// �̵�������
	// type���� ��������� �ʱ� ������ forward ��� (universal reference)
	template<typename U1, typename U2>
	CPair(const pair<U1, U2>&& _other)
		: first(forward<U1>(_other.first))
		, second(forward<U2>(_other.second))
	{
	}
	~CPair() = default;

public:
	CPair& operator= (const CPair& _other)
	{
		first = _other.first;
		second = _other.second;
		return *this;
	}
	CPair& operator= (const CPair&& _other)
	{
		first = move(_other.first);
		second = move(_other.second);
		return *this;
	}

	bool operator == (const CPair& _other) const; // ����
	bool operator != (const CPair& _other) const; // ����
	bool operator < (const CPair& _other) const; // ����
	bool operator <= (const CPair& _other) const; // ����
	bool operator > (const CPair& _other) const; // ����
	bool operator >= (const CPair& _other) const; // ����

public:
	void swap(CPair& _other)
	{
		std::swap(first, _other.first);
		std::swap(second, _other.second);
	}

public:
	T1 first;
	T2 second;
};