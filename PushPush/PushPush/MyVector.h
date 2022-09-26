#pragma once

template <typename T>
class CMyVector
{
	// con and dest
public:
	CMyVector()
		: m_Arr(new T[DEFAULT_CAP])
		, m_size(0)
		, m_capacity(DEFAULT_CAP)

	{
	}
	CMyVector(CMyVector& _other)
		: m_Arr(new T[_other.m_capacity])
		, m_capacity(_other.m_capacity)
		, m_size(_other.m_size)
	{
		for (size_t i = 0; i < m_capacity; i++)
		{
			m_Arr[i] = _other.m_Arr[i];
		}
	}

	~CMyVector()
	{
		delete[] m_Arr;
	}

public:
	// operator
	vector& operator=(vector& _other)
	{
		if (nullptr != this)
		{
			// 상대방의 배열 크기가 내꺼보다 크면
			if (m_capacity < _other.m_capacity)
			{
				// 내꺼 배열 삭제
				delete[]m_Arr;
				m_Arr = nullptr;
				//상대방 배열 크기 받고
				m_capacity = _other.m_capacity;
				// 그 크기가지는 새로운 배열 선언
				m_Arr = new T[m_capacity];
			}

			for (size_t i = 0; i < _other.m_size; ++i)
			{
				m_Arr[i] = _other[i];
				++m_size;
			}

		}

		return *this;
	}

	T& operator[](size_t idx) { return m_Arr[idx]; }


	// function
public:
	void push_back(const T& _Data)
	{
		// 배열의 인덱스가 size를 넘어갔다면
		if (m_size >= m_capacity)
		{
			if (m_capacity < DEFAULT_CAP)
				m_capacity = DEFAULT_CAP;
			else
			{
				m_capacity *= 2;
				T* newArr = new T[m_capacity];

				for (size_t i = 0; i < m_size; ++i)
					newArr[i] = m_Arr[i];
				delete[] m_Arr;
				m_Arr = newArr;
			}
		}
		m_Arr[m_size++] = _Data;
	}
	T pop_back()
	{
		// 굳이 값 초기화 안시켜도됨 기존값은 쓰레기값이나 매한가지
		if (!m_size)
			return m_Arr[--m_size];
	}


public:
	size_t size() { return m_size; }
	size_t capacity() { return m_capacity; }
	bool empty() { return !m_size; }
	void clear() { if (!empty()) m_size = 0; }


private:
	static constexpr size_t DEFAULT_CAP = 32;	// CMyVector들이 만들어질때 디폴트 크기
												// constexpr : const는 원래 사용을 하는순간 const처리가 되는데
												// 어차피 DEFAULT_CAP은 모든 CMyVector들이 똑같은 값으로 사용 할 것이기 때문에
												// static으로 선언하여 모든 CMyVector들이 하나의 변수만 사용하게 함
												// 클래스 내부에서 다같이 공유할수있는 전역변수같은느낌
	T* m_Arr;
	size_t	m_size;								// size : 사용가능한 배열의 크기
	size_t	m_capacity;							// capacity : 메모리 할당 혹시나 size를 넘어서 데이터 삽입할수도 있어서 메모리 할당은 size보다 크게 해둠

};
